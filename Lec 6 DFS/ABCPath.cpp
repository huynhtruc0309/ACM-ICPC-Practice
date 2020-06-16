#include <iostream>
using namespace std;

int main()
{
    return 0;
}

/*
Bước 1: Nhập dữ liệu
Bước 2:
Tạo mảng rd, cd
Bước 3:
BFS(ô ký tự A)
Bước 4:
In ra kết quả
int DFS(int x, int y)
{
    int maxDepth = 0;
    for (int i = 0: 7)
    {
        new_x = x + rd[i];
        new_y = y + cd[j];
        if (new_x < 1 || new_x > n || new_y < 1 || new_y > m)
            continue;
        if (A(new_x, new_y) == A(x, y) + 1)
            maxDepth = max(maxDepth, DFS(new_x, new_y))
    }
    return maxDepth + 1;
}
*/