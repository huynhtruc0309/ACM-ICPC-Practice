#include <iostream>
#include <string>
using namespace std;
#define MAX 26
int parent[MAX + 5];
int ranks[MAX + 5];

void makeSet()
{
    for (int i = 0; i < MAX; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}
int findSet(int u)
{
    if (parent[u] != u)
        parent[u] = findSet(parent[u]);
    return parent[u];
}
int unionSet(int u, int v)
{
    int up = findSet(u);
    int vp = findSet(v);
    if (up != vp)
    {
        if (ranks[up] > ranks[vp])
            parent[vp] = up;
        else if (ranks[up] < ranks[vp])
            parent[up] = vp;
        else
        {
            parent[up] = vp;
            ranks[vp]++;
        }
        return 1;
    }
    return 0;
}
int main()
{
    int T, u, v, ans, n;
    string s;
    scanf("%d\n\n", &T);
    while(T--)
    {
        getline(cin, s);
        makeSet();
        n = s[0] - 'A' + 1;
        ans = n;
        while(1)
        {
            if (!getline(cin, s) || s.empty())
                break;
            u = s[0] - 'A';
            v = s[1] - 'A';
            ans -= unionSet(u, v);
        }
        cout << ans << endl;
        if (T)
            cout << endl;
    }
    return 0;
}