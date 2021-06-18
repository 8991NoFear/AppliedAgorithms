#include <iostream>
#include <bits/stdc++.h>

const int max_N = 1e6;

int N = 0;
int t[max_N] = {};

void input() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> t[i];
    }
}

bool asc(int a, int b) {
    return a >= b;
}

void solve() {
    std::sort(t, t+N, asc);
    int res = 0;
    for (int i = 0; i < N; i++) {
        res = std::max(res, t[i]+i+1);
    }
    std::cout << res+1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    input();
    solve();
    return 0;
}
