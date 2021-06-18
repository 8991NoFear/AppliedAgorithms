#include <iostream>
#include <bits/stdc++.h>

const int max_N = 1e4+1;
const int max_T = 1e3+1;

int N, T, D;
int a[max_N] = {};
int t[max_N] = {};
int dp[max_N][max_T] = {};

void input() {
    std::cin >> N >> T >> D;
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> t[i];
    }
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int k = t[i]; k <= T; k++) {
            for (int j = i-1; j >= std::max(0, i-D); j--) {
                dp[i][k] = std::max(dp[i][k], dp[j][k-t[i]] + a[i]);
            }
            ans = std::max(ans, dp[i][k]);
        }
    }
    std::cout << ans;
}

int main()
{
    input();
    solve();
    return 0;
}
