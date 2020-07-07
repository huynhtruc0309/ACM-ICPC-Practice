#include <iostream>
#include <vector>
using namespace std;

int bigSegment(vector<vector<int>> arr, int n) {
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (arr[i][0] > arr[j][0] || arr[i][1] < arr[j][1])
                break;
        }
        if (j == n)
            return i + 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << bigSegment(arr, n);
    return 0;
}