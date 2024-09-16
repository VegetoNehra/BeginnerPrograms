#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
    int id;            // Process ID
    int arrivalTime;    // Arrival time of the process
    int burstTime;      // Burst time (CPU time needed)
    int waitingTime;    // Waiting time (total time spent waiting)

    Process(int pid, int at, int bt) {
        id = pid;
        arrivalTime = at;
        burstTime = bt;
        waitingTime = 0;
    }
};

bool compareBurstTime(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;
    
    // Input the arrival and burst time for each process
    for (int i = 0; i < n; i++) {
        int arrival, burst;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> arrival >> burst;
        processes.push_back(Process(i + 1, arrival, burst));
    }

    // Sort processes by burst time (SJF logic)
    sort(processes.begin(), processes.end(), compareBurstTime);

    int currentTime = 0;
    int totalWaitingTime = 0;

    cout << "\nProcess Execution Order:\n";
    for (int i = 0; i < n; i++) {
        Process &p = processes[i];
        // Calculate waiting time
        p.waitingTime = max(0, currentTime - p.arrivalTime); 
        currentTime += p.burstTime;
        totalWaitingTime += p.waitingTime;

        // Display the order of execution
        cout << "Process " << p.id << " executed (waiting time: " << p.waitingTime << ")\n";
    }

    // Calculate and display the average waiting time
    double avgWaitingTime = (double) totalWaitingTime / n;
    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;

    return 0;
}
