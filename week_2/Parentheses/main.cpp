#include <bits/stdc++.h>

using namespace std;

void input(vector<string> &dataset);
void solve(vector<string> &dataset);
bool isParenthesesCorrect(string str);
bool isOpenParenthese(char ch);
bool is2ParentheseFit(char ch1, char ch2);

int T;

void input(vector<string> &dataset) {
    cin >> T;
    string str; // string str = NULL la anlondo
    for (int i = 0; i < T; i++) {
        cin >> str;
        dataset.push_back(str);
    }

    return;
}

void solve(vector<string> &dataset) {
    for (int i = 0; i < T; i++) {
        cout << isParenthesesCorrect(dataset[i]) << endl;
    }

    return;
}

bool isParenthesesCorrect(string str) {
    stack<char> s;
    int len = str.size();

    for (int i = 0; i < len; i++) {
        if (isOpenParenthese(str[i])) {
            s.push(str[i]);
        } else if (s.empty()) {
            return false;
        } else {
            char open = s.top(); s.pop();
            if (!is2ParentheseFit(open, str[i])) {
                return false;
            }
        }
    }

    if (!s.empty()) {
        return false;
    }

    return true;
}

bool isOpenParenthese(char ch) {
    return (ch == '(' || ch == '{' || ch == '[') ? true : false;
}

bool is2ParentheseFit(char ch1, char ch2) {
    bool res = false;
    if (ch1 == '(' && ch2 == ')') {
        res = true;
    } else if (ch1 == '{' && ch2 == '}') {
        res = true;
    } else if (ch1 == '[' && ch2 == ']') {
        res = true;
    }

    return res;
}

int main()
{
    vector<string> dataset;
    input(dataset);
    solve(dataset);

    return 0;
}
