#include <bits/stdc++.h>

using namespace std;

const unsigned int C = 1E9 + 7; // 1E9 <=> 10^9

int n;
unsigned int *a;
unsigned long long sum = 0;

void input() {
    cin >> n;
    a = new unsigned int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    return;
}

void solve() {
    cout << sum%C;
}

int main()
{
    input();
    solve();
    return 0;
}
