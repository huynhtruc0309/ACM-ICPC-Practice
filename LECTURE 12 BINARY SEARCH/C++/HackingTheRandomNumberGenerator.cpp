#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    long long count = 0;
    vector<int>::iterator it;
    for (int i = 0; i < n; i++) 
    {
        it = lower_bound(a.begin(), a.end(), a[i] + k);
        if (it != a.end() && *it == a[i] + k) 
            count++;
    }
    cout << count;
    return 0;
}