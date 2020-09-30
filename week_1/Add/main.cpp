#include<bits/stdc++.h>
using namespace std;

string a;
string b;

void input() {
    cin >> a >> b;
    return;
}

void solve() {
    // dam bao a dai hon b
    if (a.size() < b.size()) {
        swap(a, b); // swap nhan tham chieu nen doi cho truc tiep
    }

    // chen 0 phia truoc b
    int lenA = a.size();
    int lenB = b.size();
    for (int i = 0; i < (lenA - lenB); i++) {
        b.insert(0, "0"); // insert(index, string) --> tham so thu hai khong the la ky tu
    }

    string result = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0 ; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum/10;
        result.append(to_string(sum%10));
    }

    // kiem tra xem phep cong co tran khong
    if (carry != 0) {
        result.append(to_string(carry));
    }

    reverse(result.begin(), result.end()); // reverse nhan tham chieu nen dao nguoc truc tiep
    cout << result << endl;
    return;
}

int main()
{
    input();
    solve();
    return 0;
}
