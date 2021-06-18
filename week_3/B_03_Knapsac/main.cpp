#include <iostream>
#include <bits/stdc++.h>

const int MAX_N = 64;

int n = 0, b = 0;
std::vector< std::pair<int,int> > things; // things[i].first la trong luong cua vat thu i con things[i].second la gia tri cua no
int curWei = 0;
long long curVal = 0;
int isChoosen[MAX_N]; // isChoosen[i] bang true thi vat i duoc chon << co the thay the mang nay bang ki thuat bitmask >>
long long res = -1;

void input() {
    std::cin >> n >> b;
    things.push_back(std::pair<int,int>(0,0)); // phan tu thu 0 khong bao gio dung
    for (int i = 1; i <= n; i++) {
    	int a, c;
        std::cin >> a >> c;
        things.push_back(std::make_pair(a, c)); // things[i] = make_pair(a, c) --> loi vi sao ??? vi things[i] vuot ra bien
    }
}


void arrange() {
    // funtion pointer va lambda expression
    bool (*funPtr) (std::pair<int,int> a, std::pair<int,int> b) = [] (std::pair<int,int> a, std::pair<int,int> b) {
        // mat cmn mot tieng dong ho vi deo ep kieu sang float
        // > tuc la sap xep giam dan
        return ((float) a.second/a.first) > ((float) b.second/b.first); // true thi swap
    };

    // co the truyen truc tiep lambda expression ma khong con funtion pointer
	std::sort(things.begin() + 1, things.end(), funPtr); // nho la bo qua thang things[0]
	return;
}

bool check(int k, int v) {
    if (curWei + v*things[k].first > b) {
        return false;
    }
    return true;
}

void solution() {
    res = std::max(res, curVal);
    return;
}

void TRY(int k) {
    for (int v = 1; v >= 0; v--) {
        if (check(k, v)) {
            isChoosen[k] = v;
            curVal += isChoosen[k]*things[k].second;
            curWei += isChoosen[k]*things[k].first;
            if (k == n) {
                solution();
            } else { // cat nhanh o day
                int estVal = curVal + (float)things[k+1].second / (float)things[k+1].first * (b-curWei); // cho nay ep kieu hoi bi loang ngoang
                if (estVal > res) {
                    TRY(k+1);
                }
            }
            curWei -= isChoosen[k]*things[k].first;
            curVal -= isChoosen[k]*things[k].second;
        }
    }
    return;
}

void solve() {
	input();
	arrange();
    TRY(1);
    return;
}

int main()
{
    solve();
    std::cout << res << std::endl;
    return 0;
}
