#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of processees";
    int n;
    cin>>n;
    int arrTime[n];
    int burstTime[n];
    int b[n];
    int check[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the arrival and burst time process";
        cin>>arrTime[i];        //assuming given arrival times are sorted 
        cin>>burstTime[i];
        check[i]=0;
        b[i]=burstTime[i];
    }
    cout<<"Enter the time quanta"<<endl;
    int quanta;
    cin>>quanta;
    int compTime[n];
    int waitingTime[n];
    int turnAroundTime[n];
    int time=0;
    int c=n;
    while(c>0)
    {
        for(int i=0;i<n;i++)
        {
            if(check[i]==0)
            {
                if(arrTime[i]<=time)
                {
                    if(burstTime[i]>=quanta)
                    {
                        time+=quanta;
                        burstTime[i]-=quanta;
                    }
                    else
                    {
                        int t=burstTime[i];
                        time+=t;
                        burstTime[i]-=t;
                        compTime[i]=time;
                        check[i]=1;
                        c--;
                    }
                }
                else
                {
                    time++;
                }
            }     
        }
    }
    for(int i=0;i<n;i++)
    {
        turnAroundTime[i]=compTime[i]-arrTime[i];
    }
    for(int i=0;i<n;i++)
    {
        waitingTime[i]=turnAroundTime[i]-b[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"process"<<i+1<<endl;
        cout<<"arrival time: "<<arrTime[i]<<"  burst time: "<<burstTime[i]<<endl;
        cout<<"turn around time: "<<turnAroundTime[i]<<"  completion time :"<<compTime[i]<<"  waitng time : "<<waitingTime[i]<<endl;
    }
    return 0;
}