#include <iostream>
#include <bits/stdc++.h>

const int limit = 1e6;

int n = 0;
int a[limit] = {};
int res[limit] = {};
int cur_res[limit] = {};
long long ans = 0;
long long cur_ans = 0;
int len = 0;
int cur_len = 0;

void input() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    return;
}

bool check(int v, int k) {
    return (k == 0) ? true : !(cur_res[k-1]*v);
}

void solution(){
    if (ans < cur_ans) {
       ans = cur_ans;
       len = cur_len;
       for (int i = 0; i < n; i++) {
            res[i] = cur_res[i];
       }
    }
}

void TRY(int k) {
    for (int v = 0; v <= 1; v++) {
        if (check(v, k)) {
            cur_res[k] = v;
            cur_ans += v*a[k];
            cur_len += v;
            if (k == n-1) {
                solution();
            } else {
                TRY(k+1);
            }
            cur_len -= cur_res[k];
            cur_ans -= cur_res[k]*a[k];
        }
    }
}

void solve() {
    TRY(0);
    std::cout << ans << "\n" << len << "\n";
    for (int i = 0; i < n; i++) {
        if (res[i]) {
            std::cout << i+1 << " ";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    input();
    solve();
    return 0;
}
