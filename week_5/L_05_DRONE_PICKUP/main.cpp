#include <iostream>
#include <bits/stdc++.h>

/*
 * Ta sẽ đi ngược từ N về 1, đứng tại điểm j ta có thể lùi sang điểm i nếu j <= i + a[i]
 * Gọi dp[i][k] là số lượng hàng tối đa thu được khi xét các điểm từ i về N, lấy hàng ở điểm i và số địa điểm đã lấy không vượt quá k
 * dp[i][k] = max(dp[j][k-1] + c[i] với j = i+1)
*/

const int max_N = 4096;
const int max_K = 128;
int N = 0, K = 0;
int a[max_N] = {}, c[max_N] = {};
int dp[max_N][max_K] = {};

void input() {
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        std::cin >> c[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }
    // std::fill(&dp[0][0], &dp[0][0] + max_N*max_K, -1);
}

// Dynamic Programming
// Khong chac chan luon dung tai N
int res[max_N][max_K] = {}; // path
void solve() {
    for (int i = N; i >= 1; i--) {
        for (int k = 1; k <= K+1; k++) {
            for (int j = i+1; j <= i+a[i] && j <= N; j++) {
                if (dp[i][k] < dp[j][k-1] + c[i]) {
                    dp[i][k] = dp[j][k-1] + c[i];
                    res[i][k] = i;
                }
            }
            std::cout << "dp[" << i << "][" << k << "] = " << dp[i][k] <<"\n";
            std::cout << "res[" << i << "][" << k << "] = " << res[i][k] <<"\n";
        }
        std::cout << "\n";
    }
    int ans = *std::max_element(dp[1] + 1, dp[1] + K + 1);
    std::cout << ans <<"\n";

}

// BRUTE FORCES
//int res[max_N] = {};
//int cnt = 0;
//
//bool check(int v, int k) {
//    if (cnt <= K) { // vi lan toi khong check cnt nua
//        return true;
//    }
//    return false;
//}
//
//int ans = 0;
//void solution() {
//    int total = 0;
//    for (int i = 1; i <= max_N; i++) {
//        if (res[i]) {
//            total += c[res[i]];
//        } else {
//            break;
//        }
//    }
//    ans = std::max(ans, total);
//}
//
//void TRY(int k) {
//    for (int v = res[k-1] + 1; v <= res[k-1] + a[res[k-1]]; v++) {
//        if (check(v, k)) {
//            res[k] = v;
//            cnt++;
//            if (v == N) {
//                solution();
//                cnt--;
//                return;
//            } else {
//                TRY(k+1);
//            }
//            cnt--;
//        }
//    }
//}
//
//void solve() {
//    res[1] = 1;
//    cnt = 1;
//    TRY(2);
//    std::cout << ans;
//}

int main()
{
    input();
    solve();
    return 0;
}

