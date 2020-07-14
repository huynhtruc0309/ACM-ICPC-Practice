#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
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
    int u, v, N, Q;
    makeSet();
    int maxSet = 0, minSet = INT_MAX;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> u >> v;
        unionSet(u, v);
        
        for (int i = 0; i < N; i++)
        {
            maxSet = max(maxSet, sizeSet[i + 1]);
            minSet = min(minSet, sizeSet[i + 1]);
        }
        cout << maxSet << ' ' << minSet << endl;
        cout << maxSet - minSet << endl;
    }

    return 0;
}