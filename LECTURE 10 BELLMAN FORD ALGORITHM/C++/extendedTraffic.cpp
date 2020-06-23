#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int INF = 1e9;
struct Edge
{
    int source;
    int target;
    int weight;
};

bool BellmanFord(const vector<Edge>& graph, vector<int>& dist, vector<int>& path, int n, int m, int s)
{
    int u, v, w;
    dist[0] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v])
        return false;
    }
    return true;
}

int main()
{
    int T, n, m, q, k, u, v, s = 1;
    
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        vector<int> busyness;
        vector<Edge> graph;

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> k;
            busyness.push_back(k);
        }

        vector<int> dist(n, INF), path(n, -1);

        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> u >> v;
            graph.push_back(Edge{u - 1, v - 1, int(pow(busyness[v-1] - busyness[u-1], 3))});
        }

        cin >> q;
        bool res = BellmanFord(graph, dist, path, n, m, s);

        cout << "Case " << i << ":" << endl;
        for (int j = 0; j < q; j++)
        {
            cin >> k;
            k--;
            if (dist[k] == INF || dist[k] < 3)
                cout << "?" << endl;
            else
                cout << dist[k] << endl;
        }
    }
    return 0;
}