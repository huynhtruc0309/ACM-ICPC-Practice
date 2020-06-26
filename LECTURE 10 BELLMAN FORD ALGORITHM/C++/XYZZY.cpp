#include <iostream>
#include <vector>
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
    int n;
    cin >> n;
    while (n != -1)
    {
        int energy, num, door;
        for (int i = 0; i < n; i++)
        {
            cin >> energy >> num;
            if (num != 0)
                cin >> num;
            
            
        }

        cin >> n;
    }
    return 0;
}