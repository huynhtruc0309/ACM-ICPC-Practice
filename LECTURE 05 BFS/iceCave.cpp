#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool DFS(int s, int t, int n, int m) 
{
    queue<vector<int>> qu;
    vector<vector<bool>> b;
    for (int i = 0; i < n; i++)
    {
        
    }
}
int main() {
    int n, m;
    vector<vector<char>> A(n, vector<char>(m));
    vector<int> s(2);
    vector<int> t(2);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cin >> s[0] >> s[1];
    cin >> t[0] >> t[1];

    vector<int> ri{-1, 0, 1, 0};
    vector<int> ci{0, -1, 0, 1};

    if (A[t[0]][t[1]] == '.')
    {
        int cnt = 0;
        for (int i = 1; i <= 4; i++)
        {
            int new_r = t[0] + ri[i];
            int new_c = t[1] + ci[i];

            if (A[new_r][new_c] == '.')
                cnt++;
        }
        if (cnt < 2)
            cout << "NO";
            return 1;
    }

    /*
    if (BFS(s, t, n, m))
        cout << "YES";
    else 
        cout << "NO";
        */
    return 0;
}

/*
Bước 1:
Nhập dữ liệu n, m
A[][]
s: int[2]
t: int[2]

Bước 2:
Kiểm tra A[t(0)][t(1)]
+ Nếu A[t(0)][t(1)] == "."
Số lượng ô xung quanh t == "." < 2
-> Kết quả "No"

Bước 3:
Kiểm tra tồn tại đường đi s->t
BFS
*/