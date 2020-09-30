#include <iostream>

using namespace std;

int n;
string *strArr;

void input() {
    cin >> n;
    strArr = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> strArr[i];
    }

    return;
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (strArr[i].size() <= 10) {
            cout << strArr[i] << endl;
        } else {
            string res = strArr[i].front() + to_string(strArr[i].size() - 2) + strArr[i].back();
            cout << res << endl;
        }
    }

    return;
}

int main()
{
    input();
    solve();

    return 0;
}
