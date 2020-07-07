#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int sScore = 0, dScore = 0;

    int left = 0, right = A.size()-1;
    int score;
    int i = 0;
    while (left <= right) {
        if (A[left] > A[right]) {
            score = A[left];
            left++;
        }
        else {
            score = A[right];
            right--;
        }
        if (i%2 == 0)
            sScore += score;
        else
            dScore += score;
        i++;
    }

    cout << sScore << ' ' << dScore;

    return 0;
}