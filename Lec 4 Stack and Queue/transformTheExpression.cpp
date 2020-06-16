#include <iostream>
#include <stack>
#include <string>
using namespace std;

void transform(string expression) {
    stack<char> s;
    for(char c:expression) {
        if (isalpha(c))
            cout << c;
        else if (c == ')') {
            cout << s.top();
            s.pop();
        }
        else if (c != '(')
            s.push(c);
    }
    cout << endl;
}

int main() {
    int t;
    string expression;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> expression;
        transform(expression);        
    }
    return 0;
}