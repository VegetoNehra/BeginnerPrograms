#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Job {
public:
    int ID;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit if the job is completed before or on its deadline

    Job(int a, int b, int c) : ID(a), deadline(b), profit(c) {}
};

// Comparison function to sort jobs by profit in descending order
struct CompareProfit {
    bool operator()(const Job& a, const Job& b) {
        return a.profit > b.profit; // Sort in descending order of profit
    }
};

// Function to perform job sequencing to maximize profit
int jobSequencing(vector<Job>& jobs) {
    // Step 1: Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), CompareProfit());

    // Find the maximum deadline to determine the size of the time slots
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Step 2: Create a time slot array to keep track of free time slots
    vector<int> timeSlots(maxDeadline + 1, -1); // Initialize with -1 (indicating free slots)

    int netProfit = 0; // To store the total profit
    int jobCount = 0;  // To store the number of jobs done

    // Step 3: Traverse the jobs and place them in the latest available slot
    for (const Job& job : jobs) {
        // Try to place this job in the latest available slot (before or on its deadline)
        for (int t = job.deadline; t > 0; --t) {
            if (timeSlots[t] == -1) { // If the time slot is available
                timeSlots[t] = job.ID; // Schedule the job at this time slot
                netProfit += job.profit; // Add the profit
                jobCount++; // Increment the job count
                break; // Move on to the next job
            }
        }
    }

    // Step 4: Return the maximum profit (you can also return the job count if needed)
    cout << "Maximum profit: " << netProfit << endl;
    cout << "Total jobs done: " << jobCount << endl;

    return netProfit;
}

int main() {
    // Example: Job ID, Deadline, Profit
    vector<Job> jobs = {
        Job(1, 2, 100), Job(2, 1, 19), Job(3, 2, 27),
        Job(4, 1, 25), Job(5, 3, 15)
    };

    // Function to solve the job sequencing problem
    jobSequencing(jobs);

    return 0;
}
