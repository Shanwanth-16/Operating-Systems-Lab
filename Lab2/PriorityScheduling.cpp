#include <iostream>
#include <vector>
#include <algorithm>  

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
        } else if (arrTime == other.arrTime) {
            return priority < other.priority;
        }
        return false;
    }

    void display() const {
        cout << "Process ID: " << pid << endl;
        cout << "Arrival Time: " << arrTime << "  Burst Time: " << burstTime << "  Priority: " << priority << endl;
        cout << "Completion Time: " << compTime << "  Turnaround Time: " << TurnAroundTime << "  Waiting Time: " << waitTime << endl;
    }
};

int main() {
    cout << "Enter the number of processes: ";
    int n;
    cin >> n;

    vector<Process> process;
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ":\n";
        int a, b, c;
        cin >> a >> b >> c;
        process.push_back(Process(i + 1, a, b, c));
    }

    sort(process.begin(), process.end());

    int time = process[0].arrTime;
    for (int i = 0; i < n; i++) {
        if (time < process[i].arrTime) {
            time = process[i].arrTime;  
        }
        time += process[i].burstTime;
        process[i].compTime = time;
        process[i].TurnAroundTime = process[i].compTime - process[i].arrTime;
        process[i].waitTime = process[i].TurnAroundTime - process[i].burstTime;
    }

    for (int i = 0; i < n; i++) {
        process[i].display();
    }

    return 0;
}
