#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 23;

int n = 0, k = 0, t = 0;
bool m[MAX] = {};
int c[MAX][MAX] = {};
int minDist = INT_MAX;
int curDist = 0;
int avai = 0;
int route[MAX] = {};
int minEle = INT_MAX;

void input() {
    cin >> n >> k;
    avai = k;
    t = n<<1;
    int row = t+1;
    int col = row;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> c[i][j];
        }
    }
    return;
}

bool check(int xi) {
    if (m[xi]) {
        return false;
    }

    if (xi <= n && avai == 0) {
        return false;
    }

    if (xi > n && m[xi-n] == false) {
        return false;
    }

    return true;
}

void solution() {
    // curDist += c[route[t]][0]; --> khong duoc tang curDist
    minDist = min(minDist, curDist + c[route[t]][0]);
    return;
}

void TRY(int ith) {
    for (int xi = 1; xi <= n; xi++) {
        if (check(xi)) {
            route[ith] = xi;
            curDist += c[route[ith-1]][xi];
            m[xi] = true;
            avai--;

            if (ith == t) {
                solution();
            } else if (curDist + (t-ith+1)*minEle < minDist) {
                TRY(ith + 1);
            }

            avai++;
            m[xi] = false;
            curDist -= c[route[ith-1]][xi];
        }
    }

    for (int xi = n+1; xi <= t; xi++) {
        if (check(xi)) {
            route[ith] = xi;
            curDist += c[route[ith-1]][xi];
            m[xi] = true;
            avai++;

            if (ith == t) {
                solution();
            } else if (curDist + (t-ith+1)*minEle < minDist) {
                TRY(ith + 1);
            }

            avai--;
            m[xi] = false;
            curDist -= c[route[ith-1]][xi];
        }
    }
    return;
}

void solve() {
    fill(&c[0][0], &c[0][0]+MAX*MAX, INT_MAX);
    input();
    minEle = *min_element(&c[0][0], &c[0][0] + MAX*MAX);
    route[0] = 0;
    TRY(1);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    cout << minDist << endl;
    return 0;
}
