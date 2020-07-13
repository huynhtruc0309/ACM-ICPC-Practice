#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 30000
int parent[MAX + 5];
int ranks[MAX + 5];
int sizeSet[MAX + 5];

void makeSet()
{
    for (int i = 1; i <= MAX; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
        sizeSet[i] = 1;
    }
}

int findSet(int u)
{
    if (parent[u] != u)
        parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v)
{
    int up = findSet(u);
    int vp = findSet(v);
    if (up == vp)
        return;
    if (ranks[up] > ranks[vp])
    {
        parent[vp] = up;
        sizeSet[up] += sizeSet[vp]; 
    }
    else if (ranks[up] < ranks[vp])
    {
        parent[up] = vp;
        sizeSet[vp] += sizeSet[up]; 
    }
    else
    {
        parent[up] = vp;
        sizeSet[vp] += sizeSet[up];
        ranks[vp]++;
    }
}

int main()
{
    int tc, u, v, N, M;
    cin >> tc;
    while(tc--)
    {
        makeSet();
        int maxSet = 0;
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
            cin >> u >> v;
            unionSet(u, v);
        }

        for (int i = 0; i < N; i++)
            maxSet = max(maxSet, sizeSet[i + 1]);
        cout << maxSet << endl;
    }
    return 0;
}