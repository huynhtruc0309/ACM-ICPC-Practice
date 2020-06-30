#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bsFirst(const vector<int> &a, int left, int right, int x)
{
    if (left <= right)
    {
        int mid = left + (right - left)/2;
        if ((mid == left || x > a[mid - 1]) && a[mid] == x)
            return mid;
        else if (x > a[mid])
            return bsFirst(a, (mid + 1), right, x);
        else
            return bsFirst(a, left, (mid - 1), x);
    }
    return -1;
}
int main()
{
    int N, Q;
    int c = 0;
    while (true)
    {
        cin >> N >> Q;
        if (N == 0 && Q == 0)
            break;
        vector<int> a(N), q(Q);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        c++;
        cout << "CASE# " << c << ":" << endl;
        for (int i = 0; i < Q; i++)
        {
            cin >> q[i];
            int pos = bsFirst(a, 0, N, q[i]);;
            if (pos == -1)
                cout << q[i] << " not found" << endl;
            else
                cout << q[i] << " found at " << pos + 1 << endl;
        }
    }
    return 0;
}