#include <iostream>
#include <bits/stdc++.h>

int N = 0, M = 0;
int *a; // mang chieu cao cay

void input() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> N >> M;
    a = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    return;
}

bool binarySearchCharacteristicFunction(int height) {
    long long woods = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] > height) {
            woods += a[i] - height; //  chu y: wood co the vuot qua pham vi int
        }
    }
    return woods >= M;
}

void BS(int l, int r) {
    if (l >= r-1) {
        std::cout << l;
        return;
    }
    int h = (l+r)/2;
    if (binarySearchCharacteristicFunction(h)) {
        l = h;
    } else {
        r = h;
    }
    BS(l, r);
    return;
}

void solve() {
    input();

    int minHeight = *std::min_element(a, a+N);
    int maxHeight = *std::max_element(a, a+N);
    BS(minHeight, maxHeight);

    delete [] a;
    return;
}

int main()
{
    solve();
    return 0;
}
