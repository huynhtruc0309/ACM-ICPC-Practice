#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    
    return 0;
}

/* Sửa bài:
B1: Đọc vào dãy a       |O(n)
B2: Tạo mảng sorted_a (=a)      O(nlog(n))
-> Sắp xếp sorted_a tăng dần       
B3: Tìm vị trí đầu tiên (l) và cuối cùng (r) mà a và sorted_a khác nhau         O(n)
B4: Đảo [l, r] trong a          O(n)
B5: So sánh a và sorted_a
- a == sorted_a -> yes          O(nlogn)
- a != sorted_a -> no
*/