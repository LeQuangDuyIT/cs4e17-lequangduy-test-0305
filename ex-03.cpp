#include <iostream>
#include <stack>
#include <string>

using namespace std;

string encodeString(const string& s) {
    if (s.empty()) return "";

    string result = "";
    stack<pair<char, int>> stk;

    for (int i = 0; i < s.length(); ++i) {
        if (!stk.empty() && stk.top().first == s[i]) {
            stk.top().second++;
        } else {
            if (!stk.empty()) {
                result += stk.top().first;
                result += to_string(stk.top().second);
                stk.pop();
            }
            stk.push(make_pair(s[i], 1));
        }
    }

    while (!stk.empty()) {
        result += stk.top().first;
        result += to_string(stk.top().second);
        stk.pop();
    }

    return result;
}

int main() {
    string s;
    cout << "Nhap chuoi s: ";
    getline(cin, s);

    string encodedString = encodeString(s);
    cout << "Chuoi ma hoa: " << encodedString << endl;

    return 0;
}
