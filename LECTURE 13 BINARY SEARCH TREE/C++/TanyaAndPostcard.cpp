#include <iostream>
#include <map>
#include <string>

using namespace std;
map<char, int> cntS, cntT
int main()
{
    string s, t;
    cin >> s >> t;
    for (char ch: s)
        cntS[ch]++;
    for (char ch: t)
        cntT[ch]++;
    return 0;
}