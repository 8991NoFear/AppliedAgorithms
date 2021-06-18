#include <bits/stdc++.h>
#define PI 3.141592653589793

int N,F;
int *rad = nullptr;

void input() {
    std::cin >> N >> F;
    rad = new int[N+1];
    for(int i = 1; i <= N; ++i) {
        std::cin >> rad[i];
    }
    return;
}

// Ham co tinh chat tim kiem nhi phan
// tra ve true tuc la can tang s len
bool binarySearchCharacteristicFunction(double s) {
    long long numOfPieces = 0; // cai banh nao cung cat ra cac mieng co kich thuoc s
    for(int i = 1; i <= N; ++i) {
        numOfPieces += (long long) (PI*rad[i]*rad[i]/s); // banh nao cung cat ra cac mieng kich thuoc s
    }
    return numOfPieces >= F+1; // so luong banh co chia du cho (F+1) nguoi hay khong
}

// tim kiem nhi phan tren so thuc
// dang di tim kiem so kich thuoc mieng banh can cat
void solve() {
    input();

    double l = 0, r = 1e8*PI; // max radii = 10^4
    while(r - l > 1e-6) {
        double mid = (l+r)/2;
        if(binarySearchCharacteristicFunction(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << std::fixed << std::setprecision(6) << l << std::endl;

    delete [] rad;
    return;
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
