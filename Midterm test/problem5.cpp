#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, b;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    cout << a[n/2];
    
    return 0;
}