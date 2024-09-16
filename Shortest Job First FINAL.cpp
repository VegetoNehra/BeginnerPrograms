#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Process {
public:
    int id;            // Process ID
    int arrivalTime;    // Arrival time of the process
    int burstTime;      // Burst time (CPU time needed)
    int waitingTime;    // Waiting time (total time spent waiting)

    Process(int pid, int at, int bt) : id(pid), arrivalTime(at), burstTime(bt), waitingTime(0) {}
};

// Comparator for the priority queue to sort by burst time
struct CompareBurstTime {
    bool operator()(const Process& a, const Process& b) {
        return a.burstTime > b.burstTime; // Min-heap based on burst time
    }
};

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

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) { //lambda function ,[] is called a capturte list, here it is empty
        return a.arrivalTime < b.arrivalTime;                                         //it sorts the vedctor acc to arerival time
    });

    priority_queue<Process, vector<Process>, CompareBurstTime> readyQueue;

    int currentTime = 0;
    int index = 0;
    int totalWaitingTime = 0;

    cout << "\nProcess Execution Order:\n";
    while (index < n || !readyQueue.empty()) {
        // Add all processes that have arrived by currentTime to the ready queue
        while (index < n && processes[index].arrivalTime <= currentTime) {
            readyQueue.push(processes[index]);
            index++;
        }

        if (readyQueue.empty()) {
            // If no process is ready, advance time to the next process arrival
            currentTime = processes[index].arrivalTime;
            continue;
        }

        // Get the process with the shortest burst time from the ready queue
        Process p = readyQueue.top();
        readyQueue.pop();
        
        // Calculate waiting time
        p.waitingTime = currentTime - p.arrivalTime;
        totalWaitingTime += p.waitingTime;

        // Execute the process
        currentTime += p.burstTime;

        // Display the order of execution
        cout << "Process " << p.id << " executed (waiting time: " << p.waitingTime << ")\n";
    }

    // Calculate and display the average waiting time
    double avgWaitingTime = (double)totalWaitingTime / n;
    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;

    return 0;
}