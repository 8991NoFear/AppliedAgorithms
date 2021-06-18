//#include <bits/stdc++.h>
//
//const int LIM = 11;
//
//int n = 0, K = 0, Q = 0;
//int d[LIM] = {};
//int route[LIM][LIM]; // route[i][j] diem den thu j trong tuyen cho xe i
//bool visited[LIM]; // visited[i] = true tuc la thanh pho i da di qua
//int curCap = 0;
//int R = 0; // result
//
//void input() {
//    std::cin >> n >> K >> Q;
//    for (int i = 1; i <= n; i++) {
//        std::cin >> d[i];
//    }
//}
//
//void solution() {
//
//}
//
//void solution_k() {
//
//}
//
//// kiem tra xem diem den thu ith cua xe k co the la v hay khong
//void check(int k, int ith, int v) {
//    // neu v da di qua
//    if (visited[v]) {
//        return false;
//    }
//    // neu vuot qua tai trong
//    if (curCap - d[v] < 0) {
//        return false;
//    }
//    return true;
//}
//
//// chon tuyen cho tung xe
//void TRY() {
//    for (int k = 1; k <= K; k++) {
//        curCap = Q;
//        TRY_K(k, 1);
//    }
//}
//
//// chon diem den thu ith trong tuyen danh cho xe k
//void TRY_K(int k, int ith) {
//   for (int v = n; v >= 0; v--) { // v la diem den
//       if (check(k, ith, v)) {
//            route[k][ith] = v;
//            visited[v] = true;
//            curCap -= d[v];
//            if (!v) { // neu quay ve diem xuat phat thi dung
//                solution_k();
//            } else { // cat nhanh o day
//                TRY_K(k, ith + 1);
//            }
//            curCap += d[v];
//            visited[v] = false;
//       }
//   }
//}
//
//void solve() {
//    input();
//}

int main()
{
    //solve();
    int arr[] = {-3, 2, 1, 5, 0, -5};
    int n = 6;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
