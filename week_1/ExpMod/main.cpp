#include <iostream>

using namespace std;

const unsigned int C = 1E9 + 7; // 1E9 <=> 10^9

unsigned long long a, b;

void input() {
    cin >> a >> b;
}

unsigned long long getMod(unsigned long long x, unsigned long long exp) {
    unsigned long long mod = 0; // unsigned int thi khong chay het test duoc
    if (exp == 1) {
        mod = x%C;
    } else {
        unsigned long long mod1, mod2;
        if (exp%2 == 0) {
            mod1 = getMod(x, exp/2);
            mod2 = mod1;
        } else {
            mod1 = getMod(x, (exp - 1)/2);
            mod2 = getMod(x, (exp + 1)/2);
        }
        mod = (mod1*mod2)%C;// tranh viec goi ham qua nhieu lan thi ta dung bien
    }
    return mod;
}

void solve() {
    cout << getMod(a, b);
}

int main()
{
    input();
    solve();
    return 0;
}
