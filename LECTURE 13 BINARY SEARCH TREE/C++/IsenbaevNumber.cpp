#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;
vector<int> adj[300];
int dist[300];

void bfs()
{
    int Q[300], head = 0, tail = 0;
    memset(dist, -1, sizeof(dist));

    if (m.find("Isenbaev") != m.end())
    {
        int s = m["Isenbaev"];

        dist[s] = 0;
        Q[tail] = s;
        tail++;

        while(head < tail)
        {
            int cur = Q[head];
            head++;

            for (int i = adj[cur].size()-1; i >= 0; i--)
            {
                int nxt = adj[cur][i];
                if (dist[nxt] == -1)
                {
                    dist[nxt] = dist[cur] + 1;
                    Q[tail] = nxt;
                    tail++;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string a, b, c;
    int V = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (m.find(a) == m.end()) m[a] = V++;
        if (m.find(b) == m.end()) m[b] = V++;
        if (m.find(c) == m.end()) m[c] = V++;

        int k1 = m[a], k2 = m[b], k3 = m[c];

        adj[k1].push_back(k2); adj[k1].push_back(k3);
        adj[k2].push_back(k1); adj[k2].push_back(k3);
        adj[k3].push_back(k1); adj[k3].push_back(k2);  
    }
    
    bfs();

    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " ";
        if (dist[it->second] == -1) cout << "undefined" << endl;
        else cout << dist[it->second] << endl;
    }
    return 0;
}