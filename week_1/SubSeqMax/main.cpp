#include <iostream>

using namespace std;

int n;
int *a;

void input() {
    cin >> n;
    a = new int[n]; // cap phat tren heap (khac voi int a[n] se bi tran stack khi n > mot trieu phan tu)
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return;
}

long long maxLeft(int beginIdx, int endIdx) {
    long long sum = 0;
    long long maxSum = 0;
    for (int i = endIdx; i >= beginIdx; i--) {
        sum += a[i];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

long long maxRight(int beginIdx, int endIdx) {
    long long sum = 0;
    long long maxSum = 0;
    for (int i = beginIdx; i <= endIdx; i++) {
        sum += a[i];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

long long getSubSeqMax(int beginIdx, int endIdx) {
    long long subSeqMax = 0;
    if (beginIdx == endIdx) {
        subSeqMax = a[beginIdx];
    } else {
        int middleIdx = (beginIdx + endIdx) / 2;
        long long wLeft = getSubSeqMax(beginIdx, middleIdx);
        long long wRight = getSubSeqMax(middleIdx + 1, endIdx);
        long long wMiddle = maxLeft(beginIdx, middleIdx) + maxRight(middleIdx + 1, endIdx);
        subSeqMax = max(max(wLeft, wRight), wMiddle);
    }
    return subSeqMax;
}

void solve() {
    cout << getSubSeqMax(0, n - 1) << endl;
}

int main()
{
    input();
    solve();
    return 0;
}
