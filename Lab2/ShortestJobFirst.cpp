#include <iostream>
using namespace std;
int getProcess(int arrTime[],int burstTime[],int time,int n,int check[]);
bool processRemain(int process[],int n);
int main()
{
    cout<<"Enter the number of processees";
    int n;
    cin>>n;
    int arrTime[n];//assume arrival times are given in ascending order
    int burstTime[n];
    int check[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the arrival and burst time process";
        cin>>arrTime[i];
        cin>>burstTime[i];
        check[i]=0;//the process is still to be processed
    }
    int compTime[n];
    int waitingTime[n];
    int turnAroundTime[n];
    int time=0;
    while(processRemain(check,n))
    {
        int index=getProcess(arrTime,burstTime,time,n,check);
        time+=burstTime[index];
        if(index!=-1)
        {
            compTime[index]=time;
            check[index]=1;
        }
        else
        {
            time++;
        } 
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
bool processRemain(int process[],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(process[i]==0)
        {
            c++;
        }
    }
    if(c>0)
    {
        return true;
    }
    return false;
}
int getProcess(int arrTime[],int burstTime[],int time,int n,int check[])
{
    int p=100;
    int val=-1;
    for(int i=0;i<n;i++)
    {
        if(check[i]==0 && arrTime[i]<=time)
        {
            if(p>burstTime[i])
            {
                p=burstTime[i];
                val=i;
            }
        }
    }
    return val;
}