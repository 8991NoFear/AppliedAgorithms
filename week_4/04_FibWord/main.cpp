#include <iostream>
#include <bits/stdc++.h>
/*
 * GIAI THUAT CUI BAP: tim ra day bieu dien so fibonnaci roi dem
 */

std::string fibOf(int n) {
    if (n < 2) {
        std::string res = std::to_string(n);
        return res;
    }

    std::string fibNSub2 = "0", fibNSub1 = "1", temp;
    while (n >= 2) {
        temp = fibNSub1 + fibNSub2;
        fibNSub2 = fibNSub1;
        fibNSub1 = temp;
        n--;
    }

    return fibNSub1;
}

long long occurenceOf(std::string &pattern, std::string &ori) {
    std::size_t found;
    std::size_t pos = 0;
    std::size_t occ = 0;

    found = ori.find(pattern, pos);
    while (found != std::string::npos) {
        occ++;
        pos = found+1;
        found = ori.find(pattern, pos);
    }

    return occ;
}


int main()
{
    std::string p;
    int n = 0;
    int cnt = 0;
    while (std::cin >> n >> p) { // khi nhap n la ky tu thi chuong trinh se dung
        cnt++;
        std::string ori = fibOf(n);
        long long occ = occurenceOf(p, ori);
        std::cout << "Case " << cnt << ": " << occ << std::endl;
    }
    return 0;
}
