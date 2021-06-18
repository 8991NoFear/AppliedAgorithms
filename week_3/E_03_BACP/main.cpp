#include <bits/stdc++.h>

const int LIM = 20;

int N = 0, M = 0;
int C[LIM] = {};
int A[LIM][LIM] = {}; // A[i][j] = 1 tuc la khoa hoc i phai hoc truoc khoa j

// cac cau truc du lieu lien quan
int X[LIM] = {}; // X[i] la ky cho khoa hoc i
int load[LIM] = {}; // load[i] la so tin trong ky i
int minMaxLoad = INT_MAX; // min cua max load (day la dap an can in ra cung la ky luc)
int curMaxLoad = INT_MIN;

void input() {
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        std::cin >> C[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> A[i][j];
        }
    }
    return;
}

void solution() {
    minMaxLoad = std::min(minMaxLoad, curMaxLoad);
    return;
}

bool check(int k, int v) { // khoa hoc k, ky v
    // khoa hoc k chua duoc gan o cac ky truoc ==> hien nhien

    // cac khoa hoc dieu kien da duoc hoc o cac ky truoc
    // A[i][k] = 1 tuc la khoa i can hoc truoc khoa k, ky dang xet la v
    // ta dang co X[1..k-1] ma X[i] tuc la ky duoc gan cho khoa hoc i
    for (int i = 1; i <= N; i++) {
        if (A[i][k]) {
            if (X[i] >= v) {
                return false;
            }
        }
    }
    return true;
}

void TRY(int k) { // tim ky cho khoa hoc k
    for (int v = 1; v <= M; v++) { // v la ky
        if (check(k, v)) {
            X[k] = v;
            // update data structure
            load[v] += C[k];
            int tmp = curMaxLoad;
            curMaxLoad = *std::max_element(load + 1, load + N + 1);

            if (k == N) {
                solution();
            } else if (curMaxLoad + (N-k)/M < minMaxLoad) { // cat nhanh o day
                TRY(k+1);
            }

            // khoi phuc data structure
            curMaxLoad = tmp;
            load[v] -= C[k];
            X[k] = 0;
        }
    }
    return;
}

void solve() {
    input();
    TRY(1);
    std::cout << minMaxLoad << std::endl;
}

int main()
{
    solve();
    return 0;
}
