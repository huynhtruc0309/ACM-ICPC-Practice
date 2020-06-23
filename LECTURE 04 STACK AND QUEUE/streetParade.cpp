#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void streetParade(queue<int> mainQ, int n) {
    stack<int> supportS;

    int need = 1;
    for (int i = 0; i < n; i++) {
        if (!mainQ.empty() && mainQ.front() == need) {
            need++;
            mainQ.pop();
        }
        else {
            if (!supportS.empty() && supportS.top() == need) {
                need++;
                supportS.pop();
            }
            else {
                supportS.push(mainQ.front());
                mainQ.pop();
            }
        }
    }
    while (!supportS.empty() && supportS.top() == need) {
        need++;
        supportS.pop();
    }
    if (supportS.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
int main() {
    int n, a;
    cin >> n;
    while(n != 0) {
        queue<int> mainQ;
        for (int i = 0; i < n ; i++) {
            cin >> a;
            mainQ.push(a);
        }
        streetParade(mainQ, n);
        cin >> n;
    }
    

    return 0;
}