#include <iostream>
#include <vector>
using namespace std;

int numberPrepare(vector<int> A, vector<int> B, int N, int M) {
    int idxA = 0, idxB = 0;

    while (idxA < N) {
        while (idxB < M && B[idxB] < A[idxA]) {
            idxB++;
        }
        if (idxB == M)
            break;
        idxA++;
        idxB++;
    }
    return N - idxA;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    cout << numberPrepare(A, B, N, M);

    return 0;
}