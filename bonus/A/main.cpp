#include <iostream>
#include <bits/stdc++.h>

const int limit = 1e6;

int n = 0;
int a[limit] = {};

void input() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    return;
}

void solve() {
    for (int i = 0; i < n-1; i++) {
        if (a[i] >= a[i+1]) {
            std::cout << 0;
            return;
        }
    }
    std::cout << 1;
    return;
}

int main()
{
    input();
    solve();
    return 0;
}
