#include <iostream>

using namespace std;

int res = 0;
int a[8] = {0}; // I,C,T,H,U,S,K (8 pt vi try tu 1)
int n = 7;
int target = 0;

void input() {
    cin >> target;
}


void solution() {
    int current = a[1]*100 + a[2]*10 + a[3] - (a[7]*100 + 62) + a[4]*1000 + a[5]*100 + a[6]*10 + a[3];
    if (current == target) {
        res++;
    }
    return;
}


bool check(int k, int v) {
    for (int i = k - 1; i > 0; i--) {
        if (a[i] == v) {
            return false;
        }
    }
    return true;
}

void TRY(int k) {
    for (int v = 1; v <= 9; v++) {
        if (check(k, v)) {
            a[k] = v;
            if (k == n) {
                solution();
            } else {
                TRY(k+1);
            }
            a[k] = 0;
        }
    }
}

int main()
{
    input();
    TRY(1);
    cout << res << endl;
    return 0;
}
