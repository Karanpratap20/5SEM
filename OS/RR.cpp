#include <iostream>
#include <vector>

using namespace std;

// Function to implement Round-Robin scheduling
void roundRobin(vector<int>& processes, int n, vector<int>& burst_time, int quantum) {
    vector<int> remaining_time(n);
    vector<int> waiting_time(n), turnaround_time(n);
    int completion_time = 0;

    // Copy burst_time to remaining_time
    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];

    // Round-Robin scheduling
    while (true) {
        int all_finished = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                all_finished = 0;

                if (remaining_time[i] > quantum) {
                    // Process runs for a time quantum
                    completion_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    // Process completes its execution
                    completion_time += remaining_time[i];
                    waiting_time[i] = completion_time - burst_time[i];
                    remaining_time[i] = 0;
                    turnaround_time[i] = completion_time;
                }
            }
        }

        if (all_finished)
            break;
    }

    // Print Gantt chart
    cout << "\nGantt Chart:\n";
    for (int i = 0; i < n; i++) {
        cout << turnaround_time[i] - burst_time[i] << " - P" << processes[i] << " ";
        if (i < n - 1)
            cout << "| ";
    }

    cout << "\n";
}

int main() {
    // Example processes and burst times
    vector<int> processes = {1, 2, 3, 4};
    int n = processes.size();
    vector<int> burst_time = {10, 5, 8, 12};
    int quantum = 2;

    roundRobin(processes, n, burst_time, quantum);

    return 0;
}
