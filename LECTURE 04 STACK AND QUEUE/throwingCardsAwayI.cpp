#include <iostream>
#include <queue>
using namespace std;

void throwCards(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    bool discardTurn = true;
    cout << "Discarded cards:";
    while(q.size() > 1) {
        if (discardTurn) {
            cout << ' ' << q.front();
            if (q.size() > 2) 
                cout << ",";
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
        discardTurn = !discardTurn;
    }
    cout << endl;
    cout << "Remaining card: " << q.front() << endl;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        throwCards(n);
        cin >> n;
    }
    return 0;
}
