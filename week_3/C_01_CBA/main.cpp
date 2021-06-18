#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 31;

bool conflic[MAX_N][MAX_N] = {false}; // conflic[i][j] == true thi mon i va mon j trung thoi khoa bieu
set<int> canTeach[MAX_N]; // canTeach[i] la tap cac giao vien co the day mon i
int m = 0, n = 0; // m giao vien, n mon hoc
int teacher[MAX_N]; // teacher[i] la giao vien day mon i
int maxLoad = INT_MAX;

void input() {
    cin >> m >> n;
    for (int teacher = 1; teacher <= m; teacher++) {
        int k = 0; // khong thay dung
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int subject = 0;
            cin >> subject;
            canTeach[subject].insert(teacher);
        }
    }
    int k = 0;
    cin >> k;
    for (int idx = 1; idx <= k; idx++) {
        int i = 0, j = 0;
        cin >> i >> j;
        conflic[i][j] = true;
        conflic[j][i] = true;
    }
}

void solution() {
    int *subject = new int[m+1];
    fill(subject, subject + m + 1, 0);
    for (int i = 1; i <= n; i++) {
        subject[teacher[i]]++;
    }
    maxLoad = min(maxLoad, *max_element(subject, subject + m + 1));
    delete subject;
}

bool check(int v, int k) {
    for (int i = 1; i <= (k-1); i++) {
        if (conflic[i][k]) {
            if (teacher[i] == v) {
                return false;
            }
        }
    }
    return true;
}

void TRY(int k) { // tim giao vien co the day mon k
    for (set<int>::iterator it = canTeach[k].begin(); it != canTeach[k].end(); it++) {
        int v = *it;
        // kiem tra xem giao vien v co the day mon k hay khong
        if (check(v, k)) {
            teacher[k] = v; // giao vien k day mon v
            if (k == n) {
                solution();
            } else {
                TRY(k+1);
            }
        }
    }
}

int main()
{
    input();
    TRY(1);
    cout << maxLoad;
    return 0;
}
