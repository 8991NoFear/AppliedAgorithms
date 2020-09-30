#include <iostream>

using namespace std;

int n, b, *arr;

void input() {
    cin >> n >> b;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return;
}

int getMax(int *arr, int start, int finish) {
    int maximum = 0;
    for (int i = start; i <= finish; i++) {
        if (*(arr + i) > maximum) {
            maximum = *(arr + i);
        }
    }

    return maximum;
}

void solve() {
    int res = -1;

    for (int i = 1; i < n - 1; i++) {
        int left = getMax(arr, 0, i-1) - arr[i];
        int right = getMax(arr, i+1, n-1) - arr[i];
        if (left >= b && right >= b) {
            res = left + right;
        }
    }
    cout << res;

    return;
}

int main()
{
    input();
    solve();

    return 0;
}
