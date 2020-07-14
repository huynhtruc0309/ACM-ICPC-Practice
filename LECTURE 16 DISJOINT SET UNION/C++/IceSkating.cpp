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
bool isConnect(int x1, int y1, int x2, int y2)
{
    return x1 == x2 || y1 == y2;
}

int main()
{
    int n, x, y, ans = 0;
    cin >> n;
    cin >> x >> y;
    makeSet();
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        unionSet();
    }
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            ans++;
    }
    ans--;

    cout << ans;

    return 0;
}