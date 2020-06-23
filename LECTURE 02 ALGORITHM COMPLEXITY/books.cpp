#include <iostream>
#include <vector>
using namespace std;

int numberOfBook(vector<int> A, int N, int T) {
    int maxBook = 0;
    int time;
    int j;
    for (int i = 0; i < N; i++) {
        if (N - 1 - i < maxBook)
            break;
        time = 0;
        j = i;
        while (time + A[j] <= T && j < N) {
            time += A[j];
            j++;
        }

        if (j - i > maxBook)
            maxBook = j - i;
    }
    return maxBook;
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << numberOfBook(A, N, T);
    return 0;
}