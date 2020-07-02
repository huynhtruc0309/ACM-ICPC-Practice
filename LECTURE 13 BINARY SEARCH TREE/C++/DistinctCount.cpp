#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int X, N, temp, count;
        unordered_set<int> s;
        cin >> N >> X;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            s.insert(temp);
        }
        if (s.size() > X)
            cout << "Average\n";
        else if (s.size() == X)
            cout << "Good\n";
        else cout << "Bad\n";   
    }
    return 0;
}