#include <iostream>
#include <bits/stdc++.h>

#define max_dong 6

int N = 0;
int dong[max_dong] = {500, 100, 50, 10, 5, 1};

void input() {
    std::cin >> N;
}

void solve() {
    int tong = 1000 - N;
    int i = 0;
    int them = 0;
    int dem = 0;
    while (i < max_dong) {
        them = (int) tong/dong[i];
        dem += them;
        tong -= them*dong[i];
        i++;
    }
    std::cout << dem;
}

int main()
{
    input();
    solve();
    return 0;
}
