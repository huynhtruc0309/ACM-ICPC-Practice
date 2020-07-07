# STACK
Lecture: https://drive.google.com/file/d/1-2JR9nZkJJqGL7Jas9Gtd5n3F--KUZLQ/view
## Cách khai báo và sử dụng
### C++
``` cpp
#include <stack>
using namespace std;
stack<int> s;
```
### Python
``` python
# Python sử dụng list để biểu diễn stack
s = []
```
## Thêm phần tử vào stack
### C++
``` cpp
stack<int> s;
s.push(5);
s.push(7);
s.push(3);
```
### Python
``` python
s = []
s.append(5)
s.append(7)
s.append(3)
```
## Xóa phần tử trên cùng của stack
### C++
``` cpp
s.pop(); // chỉ xóa, không lấy được giá trị trả về
```
### Python
``` python
value = s.pop()
print(value)
```
## Lấy giá trị trên cùng stack
### C++
``` cpp
int value = s.top();
cout << value;
```
### Python
``` python
value = s[-1]
print(value)
```
## Lấy kích thước của stack
### C++
``` cpp
int n = s.size();
cout << n;
```
### Python
``` python
n = len(s)
print(n)
```
## Kiểm tra stack rỗng
### C++
``` cpp
stack<int> s;
if (s.empty() == true)
    cout << "stack is empty!";
else
    cout << "stack is not empty!";
```
### Python
``` python
s = []
if len(s) == 0:
    cout << "stack is empty!"
else
    cout << "stack is not empty!"
```
## Hoán đổi 2 stack với nhau
### C++
``` cpp
s1.swap(s2)
```
### Python
``` python
s1, s2 = s2, s1
```
# QUEUE
## Cách khai báo và sử dụng
### C++
``` cpp
#include <iostream>
using namespace std;
queue<int> q;
```
### Python
``` python
import queue
import Queue
q = queue.Queue() # Py 3.x
q = Queue.Queue() # Py 2.x
```
## Thêm phần tử vào queue
### C++
``` cpp
queue<int> q;
q.push(5);
q.push(7);
q.push(3);
```
### Python
``` python
q = queue.Queue()
q.put(5)
q.put(7)
q.put(3)
```
## Xóa phần tử khỏi queue
### C++
``` cpp
q.pop();
```
### Python
```
value = s.get();
print(value)
```
## Lấy phần tử đầu queue
### C++
``` cpp
int value = q.front();
cout << value;
```
### Python
``` python
value = q.queue[0]
print(value)
```
## Lấy kích thước của queue
### C++
``` cpp
int n = q.size();
cout << n;
```
### Python
``` python
n = q.qsize()
print(n)
```
## Kiểm tra queue rỗng
### C++
``` cpp
queue<int> q;
if (q.empty() == true)
    cout << "queue is empty!";
else
    cout << "queue is not empty!";
```
### Python
``` python
q = queue.Queue
if q.empty():
    cout << "queue is empty!"
else
    cout << "queue is not empty!"
```
## Hoán đổi 2 queue với nhau
### C++
``` cpp
q1.swap(q2)
```
### Python
``` python
q1, q2 = q2, q1
```
