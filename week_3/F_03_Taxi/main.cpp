#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 23;

int n = 0, k = 1;
bool m[MAX] = {};
int c[MAX][MAX] = {};
int minDist = INT_MAX;
int curDist = 0;
int avai = 0;
int route[MAX] = {};
int minEle = INT_MAX;

void input() {
    cin >> n;
    avai = k;
    int row = 2*n+1;
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
    // curDist += c[route[2*n]][0]; --> khong duoc tang curDist
    minDist = min(minDist, curDist + c[route[2*n]][0]);
    return;
}

void TRY(int ith) {
    for (int xi = 1; xi <= 2*n; xi++) {
        if (check(xi)) {
            route[ith] = xi;
            curDist += c[route[ith-1]][xi];
            m[xi] = true;
            (xi <= n) ? avai-- : avai++;

            if (ith == 2*n) {
                solution();
            } else if (curDist + (2*n-ith+1)*minEle < minDist) {
                TRY(ith + 1);
            }

            (xi <= n) ? avai++ : avai--;
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
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    cout << minDist << endl;
    return 0;
}
