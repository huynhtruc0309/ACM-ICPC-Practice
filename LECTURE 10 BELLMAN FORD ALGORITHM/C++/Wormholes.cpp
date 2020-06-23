# include <iostream>
# include <vector>
using namespace std;

const int INF = 1e9;
struct Edge
{
    int source;
    int target;
    int weight;
};


bool BellmanFord(vector<Edge> graph, vector<int> dist, vector<int> path, int n, int m, int s)
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
    int ncases;
    cin >> ncases;

    for (int i = 0; i < ncases; i++)
    {
        
        vector<Edge> graph;
        
        int n, m;

        cin >> n >> m;
        vector<int> dist(n + 1, INF);
        vector<int> path(n + 1, -1);
        int s, u, v, w;

        for (int j = 0; j < m; j++)
        {
            cin >> u >> v >> w;
            graph.push_back(Edge{u, v, w});
        }
        s = 0;
        bool res = BellmanFord(graph, dist, path, n, m, s);
        if (res == false)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}