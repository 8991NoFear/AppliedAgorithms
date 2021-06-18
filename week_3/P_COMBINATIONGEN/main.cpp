#include <iostream>
#include <bits/stdc++.h>

int m = 0, n = 0;
int *a = nullptr;

void input() {
    std::cin >> n >> m;
    a = new int[m+1];
    for (int i = 1; i <= m; i++) {
        std::cin >> *(a+i);
    }
}

/*
 * THUAT TOAN SINH KE TIEP
 * +, Tim tu ben phai day a1, a2, ..., am phan tu ai != n - m + i
 * +, thay ai boi ai + 1
 * +, thay aj boi ai + j - i voi j = i+1, i+2, ..., m
 */
void solve() {
    int i = m;
    while (a[i] == n-m+i && i > 0) {
        i--;
    }
    if (i > 0) {
        a[i]++;
        for (int j = i+1; j <= m; j++) {
            a[j] = a[i] + j - i;
        }
        for (int i = 1; i <= m; i++) {
            std::cout << a[i] << " ";
        }
    } else {
        std::cout << -1;
    }

    delete [] a;
}

int main()
{
    input();
    solve();
    return 0;
}
