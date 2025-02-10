#include <iostream>
#include <vector>
using namespace std;
struct process{
    int pid;
    int arrTime;
    int burstTime;
    int remainingTime;
    int comTime;
    int waitTime;
    int turnaroundTime;
};
int main()
{
    int n;
    cout<<"Enter the number of process scheduled";
    cin>>n;
    vector<process> process(n);
    for(int i=0;i<n;i++)
    {
        process[i].pid=i+1;
        cout<<"Enter the arrival and burst time of the process"<<endl;
        cin>>process[i].arrTime;
        cin>>process[i].burstTime;
        process[i].remainingTime=process[i].burstTime;
    }
    int count=0;
    int currTime=0;
    while(count<n)
    {
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(process[i].arrTime<=currTime && process[i].remainingTime>0 && (idx==-1 || process[i].remainingTime<process[idx].remainingTime))
            {
                idx=i;
            }
        }
        if(idx!=-1)
        {
            process[idx].remainingTime--;
            currTime++;
            if(process[idx].remainingTime==0)
            {
                process[idx].comTime=currTime;
                process[idx].turnaroundTime=process[idx].comTime-process[idx].arrTime;
                process[idx].waitTime=process[idx].turnaroundTime-process[idx].burstTime;
                count++;
            }
        }
        else{
            currTime++;
        }
    }
    double avgTOT;
    double avgWaitTime;
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
        cout<<"process id:"<<process[i].pid<<endl;
        cout<<"arrival Time "<<process[i].arrTime<<" burst Time:"<<process[i].burstTime<<endl;
        cout<<"comTime : "<<process[i].comTime<<" turn around time :"<<process[i].turnaroundTime<<" waitting time:"<<process[i].waitTime<<endl;
        sum1+=process[i].turnaroundTime;
        sum2+=process[i].waitTime;
    }
    avgTOT=sum1/n;
    avgWaitTime=sum2/n;
    cout<<"The average turn around and waiting times are "<<avgTOT<<" and "<<avgWaitTime<<endl;
    return 0;
}