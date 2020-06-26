#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s.empty())
        cout << 0;
    else
    {
        int i = 1;
        for (char c:s)
        {
            if (isupper(c))
                i++;
        }
        cout << i;
    }
    
    return 0;
}