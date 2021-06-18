#include <iostream>
#include <bits/stdc++.h>

int main()
{
    int N = 0, K = 0;
    std::cin >> N >> K;
    int a[N+1] = {}; // N phan tu tu 1 -> N cong voi phan tu 0 nen mang co N+1 phan tu
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    int cnt = 0;
    std::sort(a+1, a+N+1); // bo qua phan tu 0 khi sap xep
    for (int i = 1; i <= N-2; i++) {
        for (int j = i+1; j <= N-1; j++) {
            int x = K - a[i] - a[j];
            if (std::binary_search(a+j+1, a+N+1, x)) { // check xem co ton tai x trong mang a hay ko
                // chu y la dang tim kiem nua khoang [lIdx, rIdx)
                int lIdx = std::lower_bound(a+j+1, a+N+1, x) - a; // lower_bound co chap nhan a[k] == x
                int rIdx = std::upper_bound(a+j+1, a+N+1, x) - a; // upper_bound khong chap nhan a[k] == x
                cnt += rIdx - lIdx;
            }
        }
    }
    std::cout << cnt;
    return 0;
}
