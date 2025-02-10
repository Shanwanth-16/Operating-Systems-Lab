#include <iostream>
#include <vector>
using namespace std;
//first try to represent the situation in the form of code
class vertex{
    public:
        int id;
        vector<vertex> adjList;
        vertex(int i)
        {
            id=i;
        }
};
int main()
{
    cout<<"Enter the number of processes in system";
    int n1;
    cin>>n1;
    cout<<"Enter the number of resouce types in system";
    int n2;
    cin>>n2;
    //total vertices are n1+n2
    //first take input of processes then take input of resources
    cout<<"Enter the process id"<<endl;
    int id;
    vector<vertex> graph;
    for(int i=0;i<n1;i++)
    {
        cout<<"Enter the val of id";
        cin>>id;
        vertex obj(id);
        graph.push_back(obj);
    }
    cout<<"Enter the resource id";
    for(int i=0;i<n2;i++)
    {
        cout<<"Enter the id of resource type"<<endl;
        cout<<"Enter the number of Instances";
        int instances;
        cin>>instances;
        for(int j=0;j<instances;j++)
        {
            cout<<"Enter the val of id";
            cin>>id;
            vertex obj(id);
            graph.push_back(obj);
        }
    }
    for(int i=0;i<n1;i++)
    {
        cout<<"Enter the number of resources held by "<<graph[i].id<<endl;
        int n;
        cin>>n;
        for(int k=0;k<n;k++)
        {
            cout<<"Enter the id of resource";
            int a;
            cin>>a;
            for(int j=n1;j<graph.size();j++)
            {
                if(graph[j].id==a)
                {
                    graph[i].adjList.push_back(graph[j]);
                }
            }
        }
    }
    for(int i=n1;i<graph.size();i++)
    {
        cout<<"Enter the number of processes requesting "<<graph[i].id<<endl;
        int n;
        cin>>n;
        for(int k=0;k<n;k++)
        {
            cout<<"Enter the process id which is requesting for resource"<<endl;
            int a;
            cin>>a;
            for(int j=0;j<n1;j++)
            {
                if(graph[j].id==a)
                {
                    graph[i].adjList.push_back(graph[j]);
                }
            }
        }
    }
    //showing the graph
        for(int i=0;i<n1+n2;i++)
        {
            cout<<graph[i].id<<"---->";
            for(int j=0;j<graph[i].adjList.size();j++)
            {
                cout<<graph[i].adjList[j].id<<" , ";
            }
        }
    return 0;
}