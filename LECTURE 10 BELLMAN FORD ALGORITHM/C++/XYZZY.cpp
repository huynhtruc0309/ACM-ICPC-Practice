#include <iostream>
#include <vector>
#include <queue>
#define MAX 105
using namespace std;
const int INF = 1e9 + 7;

<<<<<<< HEAD
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
=======
int n, m;
bool visited[MAX];
int dist[MAX], energy[MAX];
vector<pair<int, int>> graph;

bool hasPathBFS(int s, int f)
{
    fill(visited, visited + (n + 1), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (pair<int, int> &edge: graph)
        {
            if (edge.first == u)
            {
                int v = edge.second;

                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);

                    if (v == f)
                        return true;
                }
            }
        }
    }
    return false;
}

bool BellmanFord(int s, int f)
{
    fill(dist, dist + (n + 1), -INF);
    dist[1] = 100;

    for (int i = 0; i < n - 1; i++)
    {
        for (pair<int, int> &edge: graph)
        {
            int u = edge.first;
            int v = edge.second;
            if (dist[u] > 0)
            {
                dist[v] = max(dist[v], dist[u] + energy[v]);
>>>>>>> 5bd7dee0d9e309a0785266527e6f5295b16cad42
            }
        }
    }

<<<<<<< HEAD
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

=======
    for (pair<int, int> &edge: graph)
    {
        int u = edge.first;
        int v = edge.second;

        if (dist[u] > 0 && dist[u] + energy[v] > dist[v] && hasPathBFS(u, f))
            return true;
    }
    return dist[f] > 0;
}
>>>>>>> 5bd7dee0d9e309a0785266527e6f5295b16cad42
int main()
{
    int v;

    while (cin >> n, n != -1)
    {
<<<<<<< HEAD
        int energy, num, door;
        for (int i = 0; i < n; i++)
        {
            cin >> energy >> num;
            if (num != 0)
                cin >> num;
            
            
        }

        cin >> n;
=======
        graph.clear();
        for (int u = 1; u <= n; u++)
        {
            cin >> energy[u] >> m;
            for (int i = 0; i < m; i++)
            {
                cin >> v;
                graph.push_back(make_pair(u, v));
            }
        }

        bool canGo = BellmanFord(1, n);
        cout << (canGo ? "winnable" : "hopeless") << endl;
>>>>>>> 5bd7dee0d9e309a0785266527e6f5295b16cad42
    }
    
    return 0;
}