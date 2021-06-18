#include <iostream>
#include <bits/stdc++.h>

std::string strIn;
int n; // length of string

void input() {
    std::cin >> n;
    std::cin >> strIn;
}

/*
 * THUAT TOAN SINH KE TIEP
 * +, Tim i dau tien thoa man ai = 0 voi i = n, n-1, ..., 1
 * +, gan ai = 1 va bj = 0 voi tat ca j > i
 */

void solve1() {
    int i = n - 1;
    while (strIn[i] && i>=0) {
        i--;
    }
    if (i >= 0) {
        strIn[i] = 1;
        for (int j = i+1; j < n; j++) {
            strIn[j] = 0;
        }
        std::cout << strIn << std::endl;
    } else {
        std::cout << -1;
    }

}

void solve2() {
    int add[n] = {};
    add[n-1] = 1;

    int carry = 0;
    std::string res;
    for (int i = n-1; i >= 0; i--) {
        int resIdx = (strIn[i] - '0') + add[i] + carry;
        res.insert(0, std::to_string(resIdx%2));
        carry = resIdx/2;
    }
    if (carry) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << res << std::endl;
    }
}

int main()
{
    input();
//    solve1();
    solve2();
    return 0;
}
