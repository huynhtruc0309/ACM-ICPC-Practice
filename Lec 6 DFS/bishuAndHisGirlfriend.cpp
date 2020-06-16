#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 100

bool visited[MAX];
vector<int> graph[MAX];
int path[MAX];
int V, E;

void DFS(int s)
{
    visited[s] = true;
    for (int i = 0; i < graph[s].size(); i++)
    {
        int v = graph[s][i];
        if (!visited[v])
        {
            path[v] = s;
            DFS(v);
        }
    }
}

int calDistance(int s, int f)
{
    if (s == f)
        return 1;
    else
    {
        if (path[f] == -1)
            return 0;
        else
            return calDistance(s, path[f]);
    }
}

int main()
{
    int u, v;
    cin >> V;
    
    E = V-1;

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int numGF, GF;
    cin >> numGF;
    for (int i = 0; i < numGF; i++)
    {
        cin >> GF;

    }

    return 0;
}

/*
dist1 = [0 0 ... 0]
DFS(1)

với mỗi bạn q:
    dist = dist1[q]
    Nếu (dist < dist_min) hoặc (dist == dist_min và q < min_q)
        dist = dist_min
        min_q = q

def DFS(s):
    visisted[s] = True
    Với mỗi đỉnh u kề s:
        Nếu visited[u] == false
            dist1[u] = dist1[s] + 1
            DFS(u)
*/