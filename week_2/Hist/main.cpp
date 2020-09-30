#include <bits/stdc++.h>

using namespace std;

bool input(int &n, int* &l) { // input(int &n, int* &l) -->  n la so nguyen con l la bien tham chieu con tro so nguyen
    cin >> n;
    if (n != 0) {
        l = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }
        return true;
    }
    return false;
}

void solve(int &n, int* &l) { // neu chi la int *l thi cx chi la tham tri thoi (tao ra ban sao bien con tro l)
    while (input(n, l)) {
        long long maxArea = 0;
        stack<long long> s; // luu chi so i cua li thoa man dk
        int i = 0;
        while (i < n) {
            if (s.empty() || l[s.top()] <= l[i]) { // luy y l la con tro
                s.push(i);
                i++;
            } else {
                int top = s.top(); s.pop();
                long long areaWithTop = l[top] * (s.empty() ? i : (i - s.top() - 1)); // thay s.top() + 1 bang top thi sai ??? vi thang ben phai gan nhat be hon top cach xa top chu khong phai ben canh top
                maxArea = (areaWithTop > maxArea) ? areaWithTop : maxArea;
            }
        }
        while (!s.empty()) {
            int top = s.top(); s.pop();
            long long areaWithTop = l[top] * (s.empty() ? i : (i - s.top() - 1));
            maxArea = (areaWithTop > maxArea) ? areaWithTop : maxArea;
        }
        cout << maxArea << endl;
    }

}


int main() {
    int n;
    int *l;
    solve(n, l);
    return 0;
}
