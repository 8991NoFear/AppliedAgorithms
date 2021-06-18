#include <iostream>
#include <bits/stdc++.h>

#define max_c 16;

long long W = 0;
int c = 0;
int notes[4*max_c] = {};
int dump[4] = {1000, 2000, 3000, 5000};

void input() {
    std::cin >> W >> c;
}

void solve() {

}

int main()
{
    for (int i = 0; i < max_c; i+=4) {
        for (int j = 0; j < 4; j++) {
            notes[i+j] = dump[j] * std::pow(10, i);
        }
    }
    int T = 0;
    std::cin >> T;
    while (T--) {
        input();
        solve();
    }
    return 0;
}
