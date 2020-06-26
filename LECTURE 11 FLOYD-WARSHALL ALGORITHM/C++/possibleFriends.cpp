#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 50
#define INF 1e9
vector<vector<int>> graph;
vector<vector<int>> dist;
int V;


void FloyWarshall(vector<vector<int>> &graph, vector<vector<int>> &dist)
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main()
{
    int testcase;
    string temp;
    cin >> testcase;
    while(testcase--)
    {
        cin >> temp;
        V = temp.size();

        graph = vector<vector<int>> (MAX, vector<int>(MAX));
        dist = vector<vector<int>> (MAX, vector<int>(MAX)); 
        
        for (int i = 0; i < V - 1; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (temp[j] == 'N' && i != j)
                    graph[i][j] = INF;
                else if (i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = 1;
            }
            cin >> temp;
        }
            
        FloyWarshall(graph, dist);
        
        int ID = 0, numFriend = 0, cnt;
        for (int i = 0; i < V; i++)
        {
            cnt = 0;
            for (int j = 0; j < V; j++)
            {
                cout << dist[i][j] << ' ';
                if (dist[i][j] == 2)
                    cnt++;
            }
            cout << endl;
            if (cnt > numFriend)
            {
                numFriend = cnt;
                ID = i;
            }
            else if (cnt == numFriend && i < ID)
                ID = i;
        }
        cout << ID << ' ' << numFriend << endl;
    }
    return 0;
}