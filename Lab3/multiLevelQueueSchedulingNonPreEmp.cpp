#include <iostream>
using namespace std;

class Process {
public:
    int pid;
    int arrTime;
    int burstTime;
    int priority;
    int compTime;
    int waitTime;
    int TurnAroundTime;

public:
    Process(int p, int a, int b, int c) {
        pid = p;
        arrTime = a;
        burstTime = b;
        priority = c;
    }

    bool operator<(const Process& other) const {
        if (arrTime < other.arrTime) {
            return true;
        }
        return false;
    }

    void display() const {
        cout << "Process ID: " << pid << endl;
        cout << "Arrival Time: " << arrTime << "  Burst Time: " << burstTime << "  Priority: " << priority << endl;
        cout << "Completion Time: " << compTime << "  Turnaround Time: " << TurnAroundTime << "  Waiting Time: " << waitTime << endl;
    }
};

int roundRobin(vector<Process> &process,int quanta)
{
    int n=process.size();
    sort(process.begin(),process.end());
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        b[i]=process[i].burstTime;
    }
    vector<int> check(n);
    int time=0;
    int c=n;
    while(c>0)
    {
        for(int i=0;i<n;i++)
        {
            if(check[i]==0)
            {
                if(process[i].arrTime<=time)
                {
                    if(process[i].burstTime>=quanta)
                    {
                        time+=quanta;
                        process[i].burstTime-=quanta;
                    }
                    else
                    {
                        int t=process[i].burstTime;
                        time+=t;
                        process[i].burstTime-=t;
                        process[i].compTime=time;
                        process[i].TurnAroundTime = process[i].compTime - process[i].arrTime;
                        process[i].burstTime=b[i];
                        process[i].waitTime = process[i].TurnAroundTime - b[i];
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
    return time;
}
int FCFS(vector<Process> &process,int start)
{
    int time=start;
    sort(process.begin(),process.end());
    int n=process.size();
    for (int i = 0; i < n; i++) {
        if (time < process[i].arrTime) {
            time = process[i].arrTime;  
        }
        time += process[i].burstTime;
        process[i].compTime = time;
        process[i].TurnAroundTime = process[i].compTime - process[i].arrTime;
        process[i].waitTime = process[i].TurnAroundTime - process[i].burstTime;
    }
    return time;
}
int main()
{
    cout<<"Enter the number of processes:";
    int n;
    cin>>n;
    vector<Process> highPriority;
    vector<Process> lowPriority;
    for(int i=0;i<n;i++)
    {
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ":\n";
        int a, b, c;
        cin >> a >> b >> c;
        if(c==1)
        {
            highPriority.push_back(Process(i+1,a,b,c));
        }
        else
        {
            lowPriority.push_back(Process(i+1,a,b,c));
        }
    }
    cout<<"Enter the time Quanta :";
    int timeQuanta;
    cin>>timeQuanta;
    int currTime=roundRobin(highPriority,timeQuanta);
    int finishTime=FCFS(lowPriority,currTime);
    for (int i = 0; i < highPriority.size(); i++) {
        highPriority[i].display();
    }
    for(int i=0;i<lowPriority.size();i++)
    {
        lowPriority[i].display();
    }
    return 0;
 }