#include <iostream>
#include <vector>
using namespace std;

int main() {
    return 0;
}

/*
Cách 1: Dùng mảng count
Code
A[N]
count[10^5+1] = {0}
i = 0, diff
for j = 0, j < N:
    count[A[j]]++
    if count[A[j]] == 1
        diff++
    
    while (i < n && diff > 2)
        count[A[i]]++
        if count[A[i]] == 0
            diff--
        i++

    maxLen = max(maxLen, j-i+1)

    O(2N) = O(N) 

Cách 2: Dùng 2 biến val1 val2 lưu con số max, min và số lần nó xuất hiện trong mảng con đang xét. 
*/

















