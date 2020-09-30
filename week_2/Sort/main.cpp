#include <bits/stdc++.h>

using namespace std;

int n;
// n < 10^6 --> neu khai bao mang tinh thi co the bi tran stack

// neu khai bao global vector<int> arr thi loi doi voi C++17
void input(vector<int> &arr) {
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    return;
}

void solve(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return;
}

int main()
{
    vector<int> arr;
    input(arr);
    solve(arr);
    return 0;
}
