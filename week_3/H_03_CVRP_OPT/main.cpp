#include <bits/stdc++.h>

const int LIM = 50;

int n = 0, K = 0, Q = 0;
int d[LIM] = {};
int c[LIM][LIM] = {};
int route[LIM][LIM]; // route[i][j] diem den thu j trong tuyen cho xe i
bool visited[LIM]; // visited[i] = true tuc la thanh pho i da di qua
int curCap = 0;
int R = 0; // result

void input() {
    std::cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) {
        std::cin >> d[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            std::cin >> c[i][j];
        }
    }
}

void solve() {
    for (int truckIth = 1; truckIth <= n; truckIth++) { // voi moi xe chon 1 so diem di qua cho no
        for (int numOfClients = 1; numOfClients <= n; numOfClients++) { // voi moi xe no can di qua bao nhieu diem

        }

    }
}


int main()
{
    input();
    return 0;
}
