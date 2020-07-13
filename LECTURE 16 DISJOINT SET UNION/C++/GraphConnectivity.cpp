#include <iostream>
using namespace std;
#define MAX 26
int parent[MAX + 5];
int ranks[MAX + 5];

void makeSet()
{
    for (int i = 1; i < MAX; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}
int findSet(int u)
{
    if (u != parent[u])
        parent[u] = findSet(parent[u]);
    return u;
}
void unionSet(int u, int v)
{
    int up = findSet(u);
    int vp = findSet(v);
    if (up == vp)
        return;
    if (ranks[up] > ranks[vp])
        parent[vp] = up;
    else if (ranks[up] < ranks[vp])
        parent[up] = vp;
    else
    {
        parent[up] = vp;
        ranks[vp]++;
    }
}
int countSub(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (parent[i] == i)
            count++;
    return count;
}
int main()
{
    int tc;
    char u, v, n;
    cin >> tc;
    while (tc--)
    {
        makeSet();
        cin >> u;
        cin >> n;
        while (cin >> u)
        {
            if (u == '\n')
            {
                cout << countSub(n - 'A');
                break;
            }
            cin >> v;
            unionSet(u - 'A', v - 'A');
        }
    }
    return 0;
}