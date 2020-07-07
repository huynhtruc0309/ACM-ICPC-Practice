#include <iostream>
#include <vector>
using namespace std;

void findSegment(vector<int> arr, int N, int K) {
    vector<int> count(100001, 0);
    int cnt = 0; // số p tử phân biệt đang có
    int R = 0, L = 0;
 
    while (R < N) {
        count[arr[R]]++;
        if (count[arr[R]] == 1)
            cnt++;
        while (cnt == K) {
            count[arr[L]]--;
            if (count[arr[L]] == 0) {
                cnt--;
                cout << L + 1 << ' ' << R + 1;
                return;
            }
            L++;
        }
        R++;
    }
    cout << -1 << ' ' << -1;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    findSegment(arr, N, K);

    return 0;
}

//Tìm R đầu tiên mà 1-> R có đúng K phần tử
//Tăng L lên cho đến khi số p tử đặc biệt giảm
// dùng 1 mảng count để đếm số lượng phần tử phân biệt và số lần xuất hiện của từng phần tử
/*
count = [0] * 100001
cnt = 0 // số p tử phân biệt đang có

R = 1
while (R <= N)
    count[A[R]] ++
    if count[A[R]] == 1
        cnt++;
    while cnt == K:
        count[A[L]]--;
        if count[A[L]] == 0
            cnt--
            Xuất L+1, R
            Exit

// Độ phức tạp O(n)
*/