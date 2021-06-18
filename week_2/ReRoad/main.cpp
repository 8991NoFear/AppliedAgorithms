#include <bits/stdc++.h>

using namespace std;

int N = 0, Q = 0, pi = 0, ci = 0;
int *road;

// trong bai nay ta danh chi so tu 1

void input(vector< pair<int,int> > &acm) {// announcement
    cin >> N;
    road = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> road[i];
    }
    cin >> Q;

    acm.push_back({-1, -1}); // mang dong acm luon bat dau tu 0 nen ta phai day 1 gia tri ao vo truoc
    for (int i = 1; i <= Q; i++) {
        cin >> pi >> ci;
        acm.push_back({pi, ci}); // pair<int,int>(pi, ci)
    }
}

void solve(vector< pair<int,int> > &acm) {
    int res = 1;
    // get current res
    if (N > 1) {
        for (int i = 2; i <= N; i++){
            if (road[i] != road[i - 1]) {
                res++;
            }
        }
    }

    // re-calculate res for each announcement
    for (int i = 1; i < acm.size(); i++) { // i < acm.size() chu khong phai i <= acm.size() boi vi acm co phan tu 0
        int idx = acm[i].first;
        int val = acm[i].second;
        //
        if (idx == 1) {
            if (road[idx] == road[idx+1]) {
                res = (val == road[idx+1]) ? res : res + 1;
            } else {
                res = (val == road[idx+1]) ? res - 1 : res;
            }
            cout << res << endl;
        } else if (idx == N) {
            if (road[idx] == road[idx-1]) {
                res = (val == road[idx-1]) ? res : res + 1;
            } else {
                res = (val == road[idx-1]) ? res - 1 : res;
            }
            cout << res << endl;
        } else if (idx != 1 && idx != N) {
            if (road[idx] == road[idx-1] && road[idx] == road[idx+1]) {
                res = (val != road[idx]) ? res + 2 : res;
            } else if (road[idx-1] == road[idx+1]) {
                res = (val != road[idx-1]) ? res : res - 2;
            } else {
                if (road[idx] == road[idx-1] || road[idx] == road[idx+1]) {
                    res = (val == road[idx-1] || val == road[idx+1]) ? res : res + 1;
                } else {
                    res = (val == road[idx-1] || val == road[idx+1]) ? res - 1 : res;
                }
            }
            cout << res << endl;
        }
        road[idx] = val;
    }
}

int main()
{
    vector< pair<int,int> > acm;
    input(acm);
    solve(acm);
    return 0;
}
