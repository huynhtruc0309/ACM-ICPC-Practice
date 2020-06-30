#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort (a.begin(), a.end());
        int count  = 0;
        for (int i = 0; i < n; i++)
        {
            if (binary_search(a.begin() + i + 1, a.end(), m - a[i]))
                count++;
        }
        cout << count << endl;
    }
    return 0;
}