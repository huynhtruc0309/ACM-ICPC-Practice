# DIJKSTRA ALGORITHM
## C++
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100
const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void Dijktra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while(!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first();
        int w = top.second();

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
                path[neighbor.first] = u;
            }
        }
    }
}

int main()
{
    int n, s, t;
    cin >> n;
    s = 0, t = 4;
    graph = vector<vector<pair<int, int>>> (MAX + 5, vector<pair<int, int>>());
    int d = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> d;
            if (d > 0)
                graph[i].push_back(pair<int, int>(j, d));
        }

    Dijkstra(s);
    int ans = dist[t];
    cout << ans;

    return 0;
}
```
## Python
```
import queue
MAX = 100
INF = int(1e9)
class Node:
    def __init__(self, id, dist):
        self.dist = dist
        self.id = id
    def __lt__(self, other):
        return self.dist <= other.dist

def Dijkstra(s):
    pq = queue.PriorityQueue()
    pq.put(Node(s, 0))
    dist[s] = 0
    while pq.empty() == False:
        top = pq.get()
        u = top.id
        w = top.dist
        for neighbor in graph[u]:
            if w + neighbor.dist < dist[neighbor.id]:
                dist[neighbor.id] = w + neighbor.dist
                pq.put(Node(neighbor.id, dist[neighbor.id]))
                path[neighbor.id] = u

if __name__ == '__main__':
    n = int(input())
    s, t = 0, 4
    graph = [[] for i in range(n + 5)]
    dist = [INF for i in range(n + 5)]
    path = [-1 for i in range(n + 5)]
    for i in range(n):
        d = list(map(int, input().split()))
        for j in range(n):
            if d[j] > 0:
                graph[i].append(Node(j, d[j]))

    Dijkstra(s)
    ans = dist[t]
    print(ans)
```