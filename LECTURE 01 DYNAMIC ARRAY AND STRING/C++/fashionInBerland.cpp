#include <iostream>
#include <vector>
using namespace std;

void checkFashion(vector<int> arr, int n) {
    if (n == 1) {
        if (arr[0] == 1)
            cout << "YES";
        else
            cout << "NO";
    }
    else {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0)
                count ++;
        }
        if (count == 1)
            cout << "YES";
        else
            cout << "NO";
    }
 
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    checkFashion(arr, n);

    return 0;
}