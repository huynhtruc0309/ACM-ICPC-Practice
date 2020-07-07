#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int s = 1;
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j])
                s++;
        }
        cout << s << " ";
    }

    return 0;
}

//5 6 4  2  9 7 6 6 6 6 7
//9 4 10 11 1 2 4 4 4 4 2
//4 3 5  6  1 2 3 3 3 3 2 
//9 7 7  6 6 6 6 6 5 4
//1 2 2  4 4 4 4 4 9  
//sum 7  