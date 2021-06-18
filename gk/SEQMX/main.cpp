#include <iostream>
#include <bits/stdc++.h>

const int limit = 1e6;


int n, k;
int a[limit] = {};
double ans = INT_MIN;

void input() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
}

long long get_sum(int start_idx, int num) {
    long long res = 0;
    int i = start_idx;
    while (num--) {
        res += a[i];
        i++;
    }
    return res;
}

void solve() {
    for (int i = k; i <= n; i++) {
        for (int start_idx = 0; start_idx <= (n-i); start_idx++) {
            long long sum = get_sum(start_idx, i);
            ans = std::max(ans, (double) sum/i);
        }
    }
    printf("%.5lf", ans);
}

int main()
{
    input();
    solve();
    return 0;
}
