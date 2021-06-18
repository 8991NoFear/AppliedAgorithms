#include <iostream>
#include <bits/stdc++.h>

/*
 * Allocates some automatic memory, and creates an object in that memory using its default constructor
 * The memory is released automatically when the object goes out of scope
 */
std::vector< std::pair<int,int> > periods;

int n = 0;

void input() {
    std::cin >> n;
    int s = 0, t = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> s >> t;
        periods.push_back(std::make_pair(s, t));
    }
}

// thu tu muon sap xep
bool my_sort(std::pair<int,int> a, std::pair<int,int> b) {
    return a.first < b.first;
}

// brute force
void method1() {
    // sap xep lai periods theo start time
    std::sort(periods.begin(), periods.end(), my_sort);

    // lap va so sanh
    int record = -1;
    for (int i = 0; i < n-1;  i++) {
        int firstAmount = periods[i].second - periods[i].first;
        for (int j = i+1; j < n; j++) {
            if (periods[i].second <= periods[j].first) {
                int secondAmount = periods[j].second - periods[j].first;
                record = std::max(record, firstAmount + secondAmount);
            }
        }
    }
    std::cout << record;
}

// dynamic programing
void method2() {

}

void solve() {
    method1();
}

int main()
{
    // them 2 dong nay se khien cin/cout nhanh nhu scanf/printf
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    input();
    solve();
    return 0;
}
