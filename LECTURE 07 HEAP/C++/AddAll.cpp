#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
    long long N;
    cin >> N;
    long long a, b, result, sum;

    while (N != 0)
    {
        result = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> a;
            pq.push(a); 
        }
        
        a = pq.top(); pq.pop();
        while (!pq.empty())
        {
            b = pq.top(); pq.pop();
            result += a + b;
            //cout << '=' << result << ' ' << a << ' ' << b << ' ' << endl;
            a += b;
        }
        cout << result << endl;
        cin >> N;
    }
    return 0;
}