#include<bits/stdc++.h>
using namespace std;

struct rr {
    int pid, bt, sbt, wt, lst;
} p[10];

int main() {
    int pp = -1, ts, flag, count, ptm = 0, i, n, twt = 0, ttat = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time slice: ";
    cin >> ts;
    for (i = 0; i < n; i++) {
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> p[i].bt;
        p[i].sbt = p[i].bt;
        p[i].pid = i + 1;
        p[i].wt = p[i].lst = 0;
    }
    while (1) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (p[i].sbt > 0) {
                flag = 1;
                if (p[i].sbt > ts) {
                    p[i].sbt -= ts;
                    ptm += ts;
                }
                else {
                    ptm += p[i].sbt;
                    p[i].sbt = 0;
                    p[i].wt = ptm - p[i].bt;
                }
            }
        }
        if (flag == 0)
            break;
    }

    for (i = 0; i < n; i++) {
        int tat = p[i].bt + p[i].wt;
        ttat += tat;
        twt += p[i].wt;
        cout << "Process " << p[i].pid << " - Turnaround Time: " << tat << ", Waiting Time: " << p[i].wt << endl;
    }

    cout << "Average Turnaround Time: " << (float)ttat / n << endl;
    cout << "Average Waiting Time: " << (float)twt / n << endl;

    return 0;
}
