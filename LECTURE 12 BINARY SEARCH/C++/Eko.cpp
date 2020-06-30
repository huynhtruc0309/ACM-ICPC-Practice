#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, max = -1;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
    }
    long long int low = 0, high = max;
    long long int count = 0, mid;
    long long int h = 0;

    while (low <= high)
    {
        mid = (high + low) /2;
        count = 0;

        for (int i = 0; i < N; i++)
        {
            long long int temp = a[i] - mid;
            count += (temp > 0 ? temp : 0);
        }
        if (count == M)
        {
            h = mid;
            break;
        }
        else if (count < M)
            high = mid -1;
        else
        {
            low = mid + 1;
            if (mid > h)
				h = mid;
        }
    }
    cout << h;
    return 0;
}