#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long> pq;

int main()
{
    long long N, a, b, c;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        pq.push(a);

        if (i < 2)
            cout << -1 << endl;
        else 
        {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            c = pq.top(); 

            cout << a*b*c << endl;
            pq.push(a);
            pq.push(b);
        }
    }
    return 0;
}