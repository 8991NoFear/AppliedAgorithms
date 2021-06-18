#include <iostream>
#include <bits/stdc++.h>

int n = 0, k = 0;
std::vector< std::pair<int,int> > left, right;

void input() {
    std::cin >> n >> k;
    int x = 0, m = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> m;
        if (x < 0) {
            left.push_back({x, m});
        } else {
            right.push_back({x, m});
        }
    }
    return;
}

bool asc(std::pair<int,int> &a, std::pair<int,int> &b) {
    return a.first < b.first;
}

bool des(std::pair<int,int> &a, std::pair<int,int> &b) {
    return a.first > b.first;
}

long long solve1Side(std::vector< std::pair<int,int> > &data) {
    int i = data.size() - 1;
    long long res = 0;
    while (i >= 0) {
        int cap = k;
        int times = (int) data[i].second / cap;
        data[i].second = data[i].second % cap;
        res += 2 * times * (long long) std::abs(data[i].first);
        if (data[i].second > 0) {
            cap -=  data[i].second;
            data[i].second = 0;
            res += 2 * (long long) std::abs(data[i].first);
            while (i > 0 && cap > 0) {
                i--;
                if (data[i].second > cap) {
                    data[i].second -= cap;
                    cap = 0;
                } else {
                    data[i].second = 0;
                    cap -= data[i].second;
                }
            }
        } else {
            i--;
        }
    }
    return res;
}

void solve() {
    std::sort(left.begin(), left.end(), des);
    std::sort(right.begin(), right.end(), asc);
    long long res = solve1Side(right) + solve1Side(left);
    std::cout << res;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(0);
    input();
    solve();
    return 0;
}
