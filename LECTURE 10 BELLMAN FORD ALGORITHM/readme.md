# BELLMAN FORD ALGORITHM
## C++
```
# include <iostream>
# include <vector>
# define MAX 100
using namespace std;

const int INF = 1e9;
struct Edge
{
    int source;
    int target;
    int weight;
};
vector<Edge> graph;
vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);
int n, m;

bool BellmanFord(int s)
{
    int u, v, w;
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
    cin >> n >> m;
    int s, t, u, v, w;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph.push_back(Edge{u, v, w});
    }
    s = 0, t = 4;
    bool res = BellmanFord(s);
    if (res == false)
        cout << "Graph contains negative weight circle" << endl;
    else
        cout << dist[t] << endl;

    return 0;
}
```
## Python
```
INF = 10**9
MAX = 105

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight
    
dist = [INF for _ in range(MAX)]
path = [-1 for _ in range(MAX)]
graph = []

def BellmanFord(s):
    dist[s] = 0
    for i in range(1, n):
        for j in range(m):
            u = graph[j].source
            v = graph[j].target
            w = graph[j].weight
            if (dist[u] != INF and dist[u] + w < dist[v]):
                dist[v] = dist[u] + w
                path[v] = u
    
    for i in range(m):
        if (dist[u] != INF and dist[u] + w < dist[v]):
            return False
        return True

if __name__ == '__main__':
    n, m = map(int, input().split())
    for i in range(m):
        u, v, w = map(int, input().split())
        graph.append(Edge(u, v, w))
    s, t = 0, 4
    res = BellmanFord(s)
    if (not res):
        print("Graph contains negative weight circle")
    else:
        print(dist[t])


```