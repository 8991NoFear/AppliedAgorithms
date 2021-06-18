#include <iostream>
#include <bits/stdc++.h>

const int n = 7;

long long N = 0;
long long res = 0;
int a[n] = {}; // H, U, S, T, O, I, C
               // 0, 1, 2, 3, 4, 5, 6

void input() {
    res = 0;
    std::fill(a, a+n+1, 0);
    std::cin >> N;
}

bool check(int k, int v) {
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] == v) {
            return false;
        }
    }
    return true;
}

void solution() {
    // tinh HUST + SOICT
    long long sum = (a[0]*1000 + a[1]*100 + a[2]*10 + a[3]) + (a[2]*10000 + a[4]*1000 + a[5]*100 + a[6]*10 + a[3]);
    if (sum == N) {
        res++;
    }
    return;
}

void TRY(int k) {
    for (int v = 0; v <= 9; v++) {
        if (check(k, v)) {
            a[k] = v;
            if (k == n-1) {
                solution();
            } else {
                TRY(k+1);
            }
            a[k] = 0;
        }
    }
}

void solve() {
    input();
    TRY(0);
    std::cout << res << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
