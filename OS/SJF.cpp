#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int burst_time[n];
    int waiting_time = 0, turnaround_time = 0;

    cout << "Enter the burst times for each process:" << endl;
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time" << endl;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t";
        cin >> burst_time[i];
        waiting_time += burst_time[i];
        turnaround_time += waiting_time;
        cout << burst_time[i] << "\t\t" << waiting_time - burst_time[i] << "\t\t" << turnaround_time << endl;
    }

    double avg_waiting_time = static_cast<double>(waiting_time) / n;
    double avg_turnaround_time = static_cast<double>(turnaround_time) / n;

    cout << "Average Waiting Time: " << fixed << setprecision(2) << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << avg_turnaround_time << endl;

    return 0;
}
