#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testcase;
    int t = 0;
    cin >> testcase;
    while (testcase--)
    {
        t++;
        int n, ans;
        cin >> n;
        vector<int> a(n + 1);
        a[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int low = 1, high = a[n];
        bool check = true;

        while (low <= high)
        {
            int mid = (low + high)/2;
            int k = mid;
            check = true;
            cout << low << ' ' << mid << ' ' << high << ' ' << ans << endl;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] - a[i-1] > k)
                {
                    check = false;
                    break;
                }
                else if (a[i] - a[i-1] == k)
                    k--;
            }
            
            if (check == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}