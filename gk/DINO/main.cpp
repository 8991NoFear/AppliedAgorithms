#include <iostream>
#include <bits/stdc++.h>

int n = 0;
int *p = nullptr;
std::string s;

std::stack<int> chuong;
std::queue<int> hanhlang;

void input() {
    std::cin >> n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = n-1; i >= 0; i--) {
        chuong.push(p[i]);
    }
    delete [] p;
    std::cin >> s;
}

void solve() {
    int len = s.length();
    int dino = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'C') {
            dino = chuong.top(); chuong.pop();
            hanhlang.push(dino);
        } else {
            dino = hanhlang.front(); hanhlang.pop();
            chuong.push(dino);
        }
    }

    while (!chuong.empty()) {
        dino = dino = chuong.top(); chuong.pop();
        printf("%d ", dino);
    }
}

int main()
{
    input();
    solve();
    return 0;
}
