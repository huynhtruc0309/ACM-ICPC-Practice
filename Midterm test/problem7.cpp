#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <string>
using namespace std;

void BFS()
{

}

int main()
{
    int n;
    string s;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        vector<string> vocab;
        cin >> s;
        while(s != "*")
        {
            vocab.push_back(s);
        }
        string a, b;
        while(getline(cin, a) && getline(cin, b))
        {
            if (a[0] == '\n')
                break;
        }
    }
    return 0;
}