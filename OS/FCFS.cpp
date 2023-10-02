#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    cin >> n;
    vector<Process> pro(n);

    cout << "Enter Arrival time:" << endl;
    for (int i = 0; i < n; i++) {
        pro[i].pid = i;
        cin >> pro[i].at;
    }

    cout << "Enter Burst time:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> pro[i].bt;
    }

    Process key;
    int j;
    for (int i = 1; i < n; i++) {
        key = pro[i];
        j = i - 1;
        while (j >= 0 && pro[j].at > key.at) {
            pro[j + 1] = pro[j];
            j = j - 1;
        }
        pro[j + 1] = key;
    }

    int time;
    time = pro[0].ct = pro[0].bt;
    for (int i = 1; i < n; i++) {
        if (pro[i].at > time) {
            time += pro[i].at - time;
        }
        time += pro[i].bt;
        pro[i].ct = time;
    }

    for (int i = 0; i < n; i++) {
        pro[i].tat = pro[i].ct - pro[i].at;
        pro[i].wt = pro[i].tat - pro[i].bt;
    }

    cout << "PID\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T. " << endl;
    for (int i = 0; i < n; i++) {
        cout << pro[i].pid << "\t" << pro[i].at << "\t" << pro[i].bt << "\t" << pro[i].ct << "\t" << pro[i].tat << "\t" << pro[i].wt << endl;
    }

    return 0;
}
