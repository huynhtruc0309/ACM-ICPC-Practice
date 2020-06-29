# BINARY SEARCH
## Binary Search
### C++
```
#include <iostream>
#include <vector>
using namespace std;
int binarySearch(const vector<int> &a, int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            right = mid - 1;
        else if (x)> a[mid])
            left = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> a;
    int n, x, value;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        a.push_back(value);
    }
    int result = binarySearch(a, 0, n-1, x);
    cout << result;
    return 0;
}
```
### Python
```
def binarySearch(a, left, right, x):
    while left <= right:
        mid = left + (right - left)//2
        if (x == a[mid])
            return mid
        elif x < a[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return -1
if __name__ == '__main__':
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    result = binarySearch(a, 0, n-1, x)
    print(result)
```
### Binary Search Đệ quy
### C++
```
int binarySearch(const vector<int> &a, int left, int right, int x)
{
    if (left <= right)
    {
        int mid = left + (right - left)/2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binarySearch(a, left, mid - 1; x);
        return binarySearch(a, mid + 1, right, x);
    }
    return -1;
}
```
### Python
```
def binarySearch(a, left, right, x):
    if left <= right:
        mid = (left + right)//2
        if a[mid] == x:
            return mid
        if a[mid] > x:
            return binarySearch(a, left, mid-1, x)
        return binarySearch(a, mid+1, right, x)
    return -1
```
## Hàm Binary Search khác cần chú ý
## Binary Search First (tìm phần tử đầu tiên)
### C++
```
int bsFirst(const vector<int> &a, int left, int right, int x)
{
    int mid = left + (right - left)/2;
    if ((mid == left || x > a[mid - 1])
}
```