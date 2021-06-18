#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 21;

int n = 0, m = 0;
int prices[MAX][MAX] = {};
int path[MAX] = {};
bool visited[MAX] = {};
int curPri = 0;
int minEle = INT_MAX;
int minPri = INT_MAX;

void input() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        fill(prices[i], prices[i] + n + 1, INT_MAX);
    }
    for (int it = 0; it < m; it++) {
        int i, j, c;
        cin >> i >> j >> c;
        prices[i][j] = c;
    }
}

void solution() {
    minPri = min(minPri, curPri + prices[path[n]][1]);
}

bool check(int k, int v) {
    if (k == n && (prices[v][1] == INT_MAX)) {
        return false;
    }
    if (visited[v] || (prices[path[k-1]][v] == INT_MAX)) {
        return false;
    }
    return true;
}

void TRY(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(k, v)) {
            path[k] = v;
            visited[v] = true;
            curPri += prices[path[k-1]][path[k]];
            if (k == n) {
                solution();
            } else {
                if (curPri + (n-k+1)*minEle < minPri) {
                    TRY(k+1);
                }
            }
            curPri -= prices[path[k-1]][path[k]];
            visited[v] = false;
        }
    }
    return;
}

void solve() {
    minEle = min(minEle, *min_element(&prices[0][0], &prices[MAX][MAX]));
    path[1] = 1;
    visited[1] = true;
    TRY(2);
}

int main()
{
    input();
    solve();
    cout << minPri << endl;
    int arr[3][3];
    return 0;
}
