#include <bits/stdc++.h>

using namespace std;

const int MAX = 901;

int a, b, c;

void input() {
    cin >> a >> b >> c;
    return;
}


int getExtraSteps(int target) {
    queue< pair<int,int> > Q;
    map< pair<int,int>,pair<int,int> > pred;
    bool color[MAX][MAX];// khong dung map< pair<int,int>,bool > color;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            color[i][j] = false;
        }
    }

    // init
    pair<int,int> initState = pair<int,int>(0, 0);
    pred[initState] = initState;
    color[0][0] = true;
    Q.push(initState);

    pair<int,int> finish = initState;
    while (!Q.empty()) {
        pair<int,int> fr = Q.front(); Q.pop();

        // trang thai hien tai
        int x, y;
        x = fr.first;
        y = fr.second;

        // neu tim thay
        if (x == target || y == target) {
            finish = fr;
            break;
        }

        // 8 truong hop bien doi
        int new_a, new_b;

        for (int i = 0; i < 6; i++) {
            switch (i) {
                case 0:
                    new_a = a;
                    new_b = y;
                    break;
                case 1:
                    new_a = x;
                    new_b = b;
                    break;
                case 2:
                    new_a = 0;
                    new_b = y;
                    break;
                case 3:
                    new_a = x;
                    new_b = 0;
                    break;
                case 4:
                    if ((x + y) <= a) {
                        new_a = x + y;
                        new_b = 0;
                    } else {
                        new_a = a;
                        new_b = x + y -a;
                    }
                    break;
                case 5:
                    if ((x + y) <= b) {
                        new_a = 0;
                        new_b = x + y;
                    } else {
                        new_a = x + y - b;
                        new_b = b;
                    }
                    break;
            }

            if (!color[new_a][new_b]) {
                pair<int,int> current = pair<int,int>(new_a, new_b); // luy y toan tu gan khi sd pair
                Q.push(current);
                pred[current] = fr;
                color[new_a][new_b] = true;
            } else {
                continue;
            }
        }
    }

    // dem so buoc
    int counter = 0;
    pair<int,int> iter = finish;
    while (iter != initState) { // luu y phep so sanh trong pair
        counter++;
        iter = pred[iter];
    }

    return (counter > 0) ? counter : -1;
}

void solve() {
    int steps = 0;
    int extraSteps = 0;
    if (c > a || c > b) {
        if (a > b) {
            extraSteps = getExtraSteps(c%a);
            steps = (extraSteps > 0) ? extraSteps + c/a : -1;
        } else {
            extraSteps = getExtraSteps(c%b);
            steps = (extraSteps > 0) ? extraSteps + c/b : -1;
        }
    } else {
        steps = getExtraSteps(c);
    }

    cout << steps << endl;
}

int main()
{
    input();
    solve();

    return 0;
}
