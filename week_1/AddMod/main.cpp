#include <iostream>
#include <bits/stdc++.h>


using namespace std;
unsigned long long a, b;
const unsigned int C = 1E9 + 7; // 1E9 == 10^9

void input() {
    cin >> a >> b;
}

unsigned int solve() {
    return (a%C + b%C)%C;
}

int main()
{
    input();
    cout << solve() << endl;
    return 0;
}
