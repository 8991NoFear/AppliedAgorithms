#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;


int T = 0; // so test
int L = 0, C = 0; // so dong va so cot cua ma tran anh thay doi cho moi test
int a[2*MAX][2*MAX] = {0};// co mot lan khai bao hon 1 trieu phan tu thi bi tran, bh test lai thi khong thay gi

void input(vector< pair<int,int> > &img) {
    int tmp = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> tmp;
            if (tmp == 1) {
                img.push_back({i, j}); // {i, j} tuong duong voi pair<int,int>(i,j)
            }
        }
    }
    return;
}

void solve(vector< pair<int,int> > &img1, vector< pair<int,int> > &img2) {

    input(img1);
    input(img2);
    for (int i = 0; i < img1.size(); i++) {
        for (int j = 0; j < img2.size(); j++) {
            int distanceRow = img1[i].first - img2[j].first; // co the am
            int distanceCol = img1[i].second - img2[j].second; // co the am
            a[distanceRow + L][distanceCol + C]++; // ghi nhan
        }
    }

    // duyet mang a de tim max, luu y mang a co kich thuoc 2L*2C
    int res = 0;
    for (int i = 0; i < (2*L); i++) {
        for (int j = 0; j < (2*C); j++) {
            res = (res > a[i][j]) ? res : a[i][j];
        }
    }
    memset(a, 0, sizeof a);
    cout << res << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> T;
    while ( T != 0) {
        cin >> L >> C;
        vector< pair<int,int> > img1, img2;
        solve(img1, img2);
        T--;
    }

    return 0;
}
