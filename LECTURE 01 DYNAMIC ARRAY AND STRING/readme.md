# DYNAMIC ARRAY AND STRING
Lecture: https://drive.google.com/file/d/1JBxARynm8subBHm61mqeS2jXqO-k6Wur/view?fbclid=IwAR0aVtVV4LrurQoIoNaa6Y4Vf-Nu59f_9sHY2XRJoqOwjqgJ4-ismUrE0RM
## Thêm phần tử vào Dynamic Array
```cpp
vector<int> v;
v.push_back(5);
```
## Chèn giá trị vào Dynamic Array
```cpp
vector<int>::iterator it;
it = v.begin() + 2;
v.insert(it, 9);
```cpp
## Lấy kích thước của Dynamic Array
```cpp
int n = v.size();
cout << n;
```
## Truy cập phần tử trong Dynamic Array
```cpp
int result = v[2];
cout << result;

v[4] = 9

int result = v.front();
cout << result;

int result = v.back();
cout << result;
```
## Xoá phần tử cuối khỏi Dynamic Array
```cpp
v.pop_back();
```
## Xoá phần tử ở vị trí bất kì trong Dynamic Array
```cpp
vector<int>::iterator it;
it = v.begin() + 2;
v.erase(it);
```
## Xoá toàn bộ các phần tử trong Dynamic Array
```cpp
v.clear();
```
## Tăng kích thước của Dynamic Array
```cpp
v.resize(7);
```
## Giảm kích thước của Dynamic Array
```cpp
v.resize(2);
```
## Kiểm tra xem Dynamic Array có trống không
```cpp
if (v.empty() == true)
    cout << "DA is empty!";
else
    cout << "DA is not empty!";
```
## Duyệt xuôi trong Dynamic Array
```cpp
for (int i = 0; i < v.size(); i++)
    cout << v[i] << ", ";

vector<int>::iterator it;
for (it = v.begin(); it != v.end(); it++)
    cout << *it << ", ";
```
## Duyệt ngược trong Dynamic Array
```cpp
for (int i = v.size() - 1; i >= 0; i--)
    cout << v[i];

vector<int>::reverse_iterator it;
for (it = v.rbegin(); it != v.rend(); it++)
    cout << *it << ", ";
```
## Các hàm cơ bản thông dụng trong string
```cpp
size()/length()
empty()
clear()
insert(pos, string)
erase(pos, len)
find(string)
substr(pos, len)
append(string, pos, len)
```
## Kiểm tra ký tự số
```cpp
string s("123abc);
if (s[0] >= 48 && s[0] <= 57)
    cout << "digit";
```
## Một số hàm kiểm tra ký tự
```cpp
isalpha(char c)
isdigit(char c)
islower(char c)
isupper(char c)
```
## Chuyển chuỗi thành số
```cpp
string s("12");
int number = atoi(s.c_str());
cout << number;
```
## Chuyển số thành chuỗi
```cpp
string s;
int number = 15789;
s = to_string(number);
```
## In hoa và in thường ký tự
```cpp
string s("algorithm");
char c = toupper(s[2]);
cout << c;

char c = s[2] - 32; //Chuyển thành hoa
//char c = s[2] + 32; //Chuyển thành thường
cout << c;
// => G
```
## Đọc từng từ và nguyên dòng
```cpp
string s0;
cin >> s0;
cout << s0; //nothing

string s1;
getline(cin, s1);
cout << s1; //nothing is impossible
```



