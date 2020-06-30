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
## Binary Search Đệ quy
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
#### Binary Search First (tìm phần tử đầu tiên)
### C++
```
int bsFirst(const vector<int> &a, int left, int right, int x)
{
    if (left <= right)
    {
        int mid = left + (right - left)/2;
        if ((mid == left || x > a[mid - 1]) && a[mid] == x)
            return mid;
        else if (x > a[mid])
            return bsFirst(a, (mid + 1), right, x);
        else
            return bsFirst(a, left, (mid - 1), x);
    }
    return -1;
}
```
### Python
```
def bsFirst(a, left, right, x):
    if left <= right:
        mid = left + (right - left)//2
        if (mid == left or x > a[mid - 1]) and a[mid] == x:
            return mid
        elif x > a[mid]:
            return bsFirst(a, mid + 1, right, x)
        else:
            return bsFirst(a, left, mid - 1, x)
    return -1
```
#### Binary Search Last (tìm phần tử cuối cùng)
```
int bsLast(const vector<int> &a, int left, int right, int x)
{
    if (left <= right)
    {
        int mid = left + (right - left)/2;
        if ((mid == right || x < a[mid + 1]) && a[mid] == x)
            return mid;
        else if (x < a[mid])
            return bsLast(a, left, (mid - 1), x);
        else
            return bsLast(a, (mid + 1), right, x);
    }
    return -1;
}
```
### Python
```
def bsLast(a, left, right, x):
    if left <= right:
        mid = left + (right - left)//2
        if (mid == right or x < a[mid + 1]) and a[mid] == x:
            return mid
        elif x < a[mid]:
            return bsLast(a, left, mid - 1, x)
        else:
            return bsLast(a, mid + 1, right, x)
    return -1
```
## Dùng Binary Search trong thư viện của C++/Python
### C++
```
int a[] = {1, 1, 2, 2, 2, 3, 4, 5, 7};
int n = 9;
vector<int> v(a, a + n);
int x = 3;
bool result = binary_search(v.begin(), v.end(), x);
```
### Python
```
Không có
```
## Hàm tìm cận dưới >=
### C++
```
int a[] = {1, 1, 2, 2, 2, 3, 4, 5, 7};
int n = 9;
vector<int> v(a, a + n);
int x = 3;
vector<int>::iterator low_value;
low_value = lower_bound(v.begin(), v.end(), x);
int index = low_value - v.begin();
```
### Python
```
if __name__ == '__main__':
    a = [1, 1, 2, 2, 2, 3, 4, 5, 7]
    n, x = 9, 3
    pos = bisect.bisect_left(a, x, 0, n);
    # hoặc pos = bisect.bisect_left(a, x);
    print(pos)
```
## Hàm tìm cận trên >
### C++
```
int a[] = {1, 1, 2, 2, 2, 3, 4, 5, 7};
int n = 9;
vector<int> v(a, a + n);
int x = 3;
vector<int>::iterator upp_value;
upp_value = upper_bound(v.begin(), v.end(), x);
int index = upp_value - v.begin();
```
### Python
```
if __name__ == '__main__':
    a = [1, 1, 2, 2, 2, 3, 4, 5, 7]
    n, x = 9, 3
    pos = bisect.bisect_right(a, x, 0, n);
    # hoặc pos = bisect.bisect_right(a, x);
    print(pos)
```