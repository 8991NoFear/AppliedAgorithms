#include <bits/stdc++.h>

using namespace std;

int n, b;
int *a;

void input() {
    cin >> n >> b;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return;
}

void solve() {
    int *maxPre = new int[n];
    int *maxPos = new int[n];

    maxPre[0] = a[0];
    maxPos[n-1] = a[n - 1];
    for (int i = 1; i < (n-1); i++) {
        maxPre[i] = (a[i-1] > maxPre[i-1]) ? a[i-1] : maxPre[i-1];
    }

    for (int i = (n-2); i >= 1; i--) {
        maxPos[i] = (a[i+1] > maxPos[i+1]) ? a[i+1] : maxPos[i+1];
    }

    int result = -1;
    for (int i = 1; i < (n-1); i++) {
        if ((maxPre[i] - a[i] >= b) && (maxPos[i] - a[i] >= b)) {
            int tmp = maxPre[i] - a[i] + maxPos[i] - a[i];
            result = (tmp > result) ? tmp : result;
        }
    }
    cout << result;
}

int main() {
    input();
    solve();
    return 0;
}
