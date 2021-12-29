#include <iostream>
#include <string>
#include <stack>
using namespace std;
void print(stack<char> &s) {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
int main() {
    string str;
    getline(cin, str);
    bool tag = false;
    stack<char> s;
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '<') {
            print(s);
            tag = true;
            cout << str[i];
        } else if (str[i] == '>') {
            tag = false;
            cout << str[i];
        } else if (tag) {
            cout << str[i];
        } else {
            if (str[i] == ' ') {
                print(s);
                cout << str[i];
            } else {
                s.push(str[i]);
            }
        }
    }
    return 0;
}
