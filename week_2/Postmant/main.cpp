// Giai khong hay --> xem postman trong training contest 7

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n = 0, k = 0;

// dung trong ham sort
bool myCmp(pair<int,int> &x, pair<int,int> &y) {
    return x.first > y.first;
}

void input(vector< pair<int,int> > &posData, vector< pair<int,int> > &negData) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int xi = 0, mi = 0;
        cin >> xi >> mi;
        if (xi > 0) {
            posData.push_back({xi, mi});
        } else {
            negData.push_back({xi, mi});
        }
    }
    return;
}
/*
 * DUNG STACK
 */

//long long solve1Side(stack< pair<int,int> > S) {
//    long long ans = 0;
//    while (!S.empty()) {
//        pair<int,int> top = S.top();
//        if (top.second >= k) {
//            ans += (top.second/k) * 2 * llabs(top.first); // so lan can van chuyen nhan voi 2 lan toa do, luu y ham llabs() - long long absolute
//            // cap nhat
//            int remainder = top.second%k;
//            if (remainder != 0) {
//                top.second %= k;
//            } else {
//               S.pop();
//            }
//        } else {
//            ans += 2 * abs(top.first); // 2 lan toa do
//            S.pop();
//            int newK = k - top.second;
//            while (!S.empty() && (newK != 0)) {
//                pair<int,int> newTop = S.top();
//                if (newTop.second > newK) {
//                    // cap nhat
//                    newTop.second -= newK;
//                    newK = 0;
//                } else {
//                    newK -= newTop.second;
//                    S.pop();
//                }
//            }
//        }
//    }
//    return ans;
//}

long long solve1Side(vector< pair<int,int> > V) {
    long long ans = 0;
    int len = V.size();
    int i = 0;
    while (i < len) {
        pair<int,int> current = V[i];
        if (current.second >= k) {
            ans += (long long) abs(current.first) * (current.second/k) * 2; // so lan can van chuyen nhan voi 2 lan toa do
            // cap nhat
            int remainder = current.second%k;
            if (remainder != 0) {
                current.second = remainder;
            } else {
               i++;
            }
        } else {
            ans += (long long) 2 * abs(current.first); // luu y ham can ep ve long long (vi co the phep nhan gay tran)
            i++;
            int newK = k - current.second;
            while ((i < len) && (newK != 0)) {
                pair<int,int> newCurrent = V[i];
                if (newCurrent.second > newK) {
                    // cap nhat
                    newCurrent.second -= newK;
                    newK = 0;
                } else {
                    newK -= newCurrent.second;
                    i++;
                }
            }
        }
    }
    return ans;
}

void solve() {
    vector< pair<int,int> > posData, negData;
    input(posData, negData);

    // sap xep lai du lieu theo chieu giam dan
    sort(posData.begin(), posData.end(), myCmp);
    sort(negData.begin(), negData.end());

// CODE NAY DUNG KHI SD STACK
//    stack< pair<int,int> > posStack, negStack;
//    for (int i = 0; i < posData.size(); i++) {
//        posStack.push(posData[i]);
//    }
//
//    for (int i = 0; i < negData.size(); i++) {
//        negStack.push(negData[i]);
//    }
//
//    long long res = solve1Side(posStack) + solve1Side(negStack);

    long long res = solve1Side(posData) + solve1Side(negData);
    cout << res;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
    solve();
    return 0;
}
