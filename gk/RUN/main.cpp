#include <iostream>
#include <bits/stdc++.h>


int n = 0;
int *a = nullptr;

void input() {
    std::cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
}

void solve() {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) {
            continue;
        } else {
            cnt++;
        }
    }
    printf("%d", cnt+1);
}

int main()
{
    input();
    solve();
    delete [] a;
    return 0;
}
