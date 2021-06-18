#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * THUAT TOAN SINH
 * +, tim tu trai qua phai chi so j thoa man a[j] < a[j+1]
 * +, tim a[k] la so nho nhat con lon hon a[j] trong cac so ben phai a[j]
 * +, doi cho a[j] voi a[k]
 * +, lat nguoc doan tu a[j+1] den a[n]
 */


void solve() {
    int n;
    std::cin >> n;
    int a[n+1] = {};
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int j = n-1;
    while (j > 0 && a[j] > a[j+1]) {
        j--;
    }
    if (j > 0) {
        int k = j+1;
        for (int i = k; i <= n; i++) {
            if (a[i] < a[k] && a[i] > a[j]) {
                k = i;
            }
        }
        std::swap(a[j], a[k]);
        std::reverse(a+j+1, a+n+1); // chu y kich thuoc mang la n + 1
        for (int i = 1; i <= n; i++) {
            std::cout << a[i] << " ";
        }
    } else {
        std::cout << -1 << std::endl;
    }
}

int main()
{
    solve();
    return 0;
}
