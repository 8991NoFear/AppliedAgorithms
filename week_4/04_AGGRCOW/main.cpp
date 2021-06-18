#include <bits/stdc++.h>

int N = 0, C = 0;
int *x = nullptr;

void input() {
    std::cin >> N >> C;
    x = new int[N+1];
    for(int i = 1; i <= N; ++i) {
        std::cin >> x[i];
    }
    std::sort(x+1, x+N+1);
    return;
}

// Ham co tinh chat tim kiem nhi phan
// tra ve true tuc la can tang distance len
bool binarySearchCharacteristicFunction(int distance)
{
    /*
     * Ta co nhan xet sau day (thuc ra la search github moi biet co cai nay)
     * So luong lon nhat cac chuong ma vi tri cac chuong thoa man khoang cach giua 2 chuong lien tiep >= distance khi chuong dau tien o vi tri 1 (co the dung phan chung de chung minh)
     */
     int counter = 1;
     int curr = x[1];
     for (int i = 2; i <= N; i++) {
        if (x[i] - curr >= distance) {
            counter++;
            curr = x[i];
        }
     }
     return counter >= C;
}

// tim kiem nhi phan tren so nguyen
// dang di tim kiem largest minimum distance
void solve()
{
    input();

    int l = 0, r = INT_MAX; // cho l = 0 neu cho l = 1 thi l + r bi tran do
    while(r - l > 1) {
        double mid = (l+r)/2;
        if(binarySearchCharacteristicFunction(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << l << std::endl;
    delete [] x;
    return;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
