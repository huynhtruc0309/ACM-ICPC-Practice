#include <isotream>
using namespace std;

int main()
{

    return 0;
}

/*
Bước 1: Đọc
Bước 2: 1 (xa nhất) -> v
Bước 3: v (xa nhất) -> w
Bước 4: in d(v, w)
Độ phức tạp O(N)
DFS(v, len):
    if (len > maxLen):
        maxLen = len
        furthest = v
    for v -> (u, v, w):
        dfs(v, len + w)

    
DFS(1, 0)
DFS(furthest, 0)
print(maxlen)
*/