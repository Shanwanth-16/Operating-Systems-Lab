#include <iostream>
#include <vector>
using namespace std;

int* safetyAlgo(int available[], int** need, int** allocated, int n, int m) {
    int y = 0;
    vector<bool> finish(n, false);
    int* safeSequence = new int[n];
    
    for (int a = 0; a < n; a++) {
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (finish[i] == false && available[j] >= need[i][j]) {
                    count++;
                }
            }
            if (count == m) { // It means I can execute that process
                finish[i] = true;
                safeSequence[y] = i;
                y++;
                for (int k = 0; k < m; k++) {
                    available[k] += allocated[i][k];
                }
            }
        }
    }

    int flag = 0;
    for (int i = 0; i < finish.size(); i++) {
        if (finish[i] == false) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        return safeSequence;
    } else {
        return nullptr;
    }
}

int main() {
    cout << "Enter the number of resource types in the system: ";
    int m;
    cin >> m;

    int available[m];
    for (int i = 0; i < m; i++) {
        cout << "Enter the number of instances of resources available for " << i + 1 << ": ";
        cin >> available[i];
    }

    cout << "Enter the number of processes: ";
    int n;
    cin >> n;

    // Dynamically allocate memory for max, allocated, and need arrays
    int** max = new int*[n];
    int** allocated = new int*[n];
    int** need = new int*[n];

    for (int i = 0; i < n; i++) {
        max[i] = new int[m];
        allocated[i] = new int[m];
        need[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter the number of resource instances of " << j + 1 << " max needed by " << i + 1 << ": ";
            cin >> max[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter the number of resource instances of " << j + 1 << " allocated to " << i + 1 << ": ";
            cin >> allocated[i][j];
        }
    }

    // Calculate the need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    // Let the request of process 3 be {1,0,1}
    int request[m];
    int process = 0;
    cout << "Enter the process that raises the request: ";
    cin >> process;

    for (int i = 0; i < m; i++) {
        cout << "Enter the requested number of resource instances of resource type " << i + 1 << ": ";
        cin >> request[i];
    }

    for (int i = 0; i < m; i++) {
        if (request[i] > need[process][i]) {
            cout << "Request not possible because process is requesting more than max need" << endl;
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (request[i] > available[i]) {
            cout << "Process has to wait, not enough available resources" << endl;
            return 0;
        }
    }

    // Grant the request
    for (int i = 0; i < m; i++) {
        allocated[process][i] += request[i];
        need[process][i] -= request[i];
        available[i] -= request[i];
    }

    // Call safety algorithm to check for safe sequence
    int* ans = safetyAlgo(available, need, allocated, n, m);
    if (ans == nullptr) {
        cout << "The request causes deadlock." << endl;
    } else {
        cout << "The request can be granted with safe sequence: ";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] max[i];
        delete[] allocated[i];
        delete[] need[i];
    }
    delete[] max;
    delete[] allocated;
    delete[] need;
    delete[] ans;

    return 0;
}
