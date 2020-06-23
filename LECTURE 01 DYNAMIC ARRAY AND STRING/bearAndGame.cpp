#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int minute = 0;

    vector<int> arr(n);
    for (int i = 0 ; i < n; i++) {
        cin >> arr[i];

        if (minute + 15 >= arr[i]) {
            minute = arr[i];
        }        
        else {
            minute += 15;
            break;
        }

        if (i == n-1) {
            if (arr[i] + 15 <= 90)
                minute = arr[i] + 15;
            else
                minute = 90;
        }
    }
    cout << minute;

    return 0;
}