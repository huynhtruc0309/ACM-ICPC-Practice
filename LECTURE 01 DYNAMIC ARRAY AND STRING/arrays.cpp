#include <iostream>
#include <vector>
using namespace std;

void arrays(vector<int> a, vector<int> b, int Na, int Nb, int K, int M) {
    if (a[K - 1] < b[Nb - M])
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    int Na, Nb;
    int K, M;
    cin >> Na >> Nb;
    cin >> K >> M;
    vector<int> a(Na), b(Nb);
    for (int i = 0; i < Na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Nb; i++) {
        cin >> b[i];
    }
    arrays(a, b, Na, Nb, K, M);
    
    return 0;
}
//3 3
//1 2 3
//4 5 6