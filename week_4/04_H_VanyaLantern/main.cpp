#include <iostream>
#include <bits/stdc++.h>

const int MAX_N = 1000;
const int MAX_L = 1e9;

int n = 0, l = 0;
int a[MAX_N] = {};

void input() {
    std::cin >> n >> l;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
}

void solve() {
    std::sort(a, a+n);
    int max_dist = 0; // khoang cach lon nhat giua 2 den
    for (int i = 1; i < n; i++) {
        max_dist = std::max(max_dist, a[i] - a[i-1]);
    }
    int start_dist = a[0]; // khoang cach tu vi tri 0 den den dau tien
    int end_dist = l - a[n-1]; // khoang cach tu vi tri cua den cuoi cung den vi tri ket thuc doan duong
    double ans = std::max(start_dist, end_dist);
    ans = std::max((double)max_dist/2, (double)ans);
    printf("%.10f", ans);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    solve();
    return 0;
}
