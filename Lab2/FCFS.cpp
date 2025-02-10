#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of processees";
    int n;
    cin>>n;
    int arrTime[n];
    int burstTime[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the arrival and burst time process";
        cin>>arrTime[i];//assuming given arrival times are sorted
        cin>>burstTime[i];
    }
    int compTime[n];
    int waitingTime[n];
    int turnAroundTime[n];
    int time=arrTime[0];
    for(int i=0;i<n;i++)
    {
        time+=burstTime[i];
        compTime[i]=time;
    }
    for(int i=0;i<n;i++)
    {
        turnAroundTime[i]=compTime[i]-arrTime[i];
    }
    for(int i=0;i<n;i++)
    {
        waitingTime[i]=turnAroundTime[i]-burstTime[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"process"<<i+1<<endl;
        cout<<"arrival time: "<<arrTime[i]<<"  burst time: "<<burstTime[i]<<endl;
        cout<<"turn around time: "<<turnAroundTime[i]<<"  completion time :"<<compTime[i]<<"  waitng time : "<<waitingTime[i]<<endl;
    }
    return 0;
}