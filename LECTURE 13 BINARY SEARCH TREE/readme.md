# BINARY SEARCH TREE
## 0. Khai báo cấu trúc một node trong BST
#### Độ phức tạp: O(1)
### C++
```
struct Node
{
    int key;
    Node *left;
    Node *right;
}
```
### Python
```
class Node:
    def __init__(self):
        self.key = 0
        self.left = None
        self.right = None
```
## 1. Tạo một node mới
#### Độ phức tạp: O(1)
### C++
```
Node* createNode(int x)
{
    Node *newNode = new Node;
    newNode->key = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}
```
### Python
```
def createNode(x):
    newNode = Node()
    newNode.key = x
    return newNode
```
## 2. Chèn một giá trị mới vào BST
#### Độ phức tạp: O(h) với h là chiều cao cây (Lưu ý: worst case O(n))
### C++
```
Node* createNode(Node* root, int x)
{
    if (root == NULL)
        return createNode(x);
    if (x < root->key)
        root->left = insertNode(root->left, x);
    else if (x > root->key)
        root->right = insertNode(root->right, x);
    return root;
}
```
### Python
```
def insertNode(root, x):
    if root == None:
        return createNode(x)
    if x < root.key:
        root.left = insertNode(root.left, x)
    elif x > root.key:
        root.right = insertNode(root.right, x)
    return root
```
## 3. Tạo Binary Search Tree
#### Độ phức tạp: O(N*h) với h là chiều cao cây
### C++
```
void createTree(Node* &root, int a[], int n)
{
    for (int i = 0; i < n; i++)
        root = insertNode(root, a[i]);
}
```
### Python
```
def createTree(a, n):
    root = None
    for i in range(n):
        root = insertNode(root, a[i])
    return root
```
## 4. Tìm kiếm một giá trị trong BST
#### Độ phức tạp: O(h) với h là chiều cao cây (Lưu ý: worst case O(n))
### C++
```
Node* searchNode(Node *root, int x)
{
    if (root == NULL || root->key == x)
        return root;
    if (root->key < x)
        return searchNode(root->right, x);
    return searchNode(root->left, x);
}
```
### Python
```
def searchNode(root, x):
    if root == None or root.key == x:
        return root
    if root.key < x:
        return searchNode(root.left, x)
    return searchNode(root.right, x)
```
## 5. Xóa một giá trị trong BST
#### Độ phức tạp: O(h) với h là chiều cao cây (Lưu ý: worst case O(n))
### C++
```
Node* deleteNode(Node* &root, int x)
{
    if (root == NULL)
        return root;
    if (x < root->key)
        root->left = deleteNode(root->left, x);
    else if (x > root->key)
        root->right = deleteNode(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
```
### Python
```
def deleteNode(root, x):
    if root == None:
        return root
    if x < root.key:
        root.left = deleteNode(root.left, x)
    elif x > root.key:
        root.right = deleteNode(root.right, x)
    else:
        if root.left == None:
            temp = root.right
            del root
            return temp
        elif root.right == None:
            temp = root.left
            del root
            return temp
        temp = minValueNode(root.right)
        root.key = temp.key
        root.right = deleteNode(root.right, temp.key)
    return root

def minValueNode(node):
    current = node
    while current.left != None:
        current = current.left
    return current
```
# Các hàm khác liên quan Binary Search Tree
## 6. Duyệt Binary Search Tree
#### Độ phức tạp: O(N)
### C++
```
void traversalTree(Node *root)
{
    if (root != NULL)
    {
        traversalTree(root->left);
        cout << root->key << " ";
        traversalTree(root->right);
    }
}
```
### Python
```
def traversalTree(root):
    if root != None:
        traversalTree(root.left)
        print(root.key, end = ' ')
        traversalTree(root.right)
```
## 7. Tính kích thước của BST
#### Độ phức tạp: O(N)
### C++
```
int size(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return (size(node->left) + 1 + size(node->right));
}
```
### Python
```
def size(root):
    if root == None:
        return 0
    return size(root.left) + 1 + size(root.right)
```
## 8. Xoá Binary Search Tree
#### Độ phức tạp: O(N)
### C++
```
void deleteTree(Node* root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete(root);
}
```
### Python
```
def deleteTree(root):
    if root == None:
        return
    deleteTree(root.left)
    deleteTree(root.right)
    del root
```
# Sử dụng Binary Search Tree bằng thư viện
## Cách sử dụng set và map
### C++
```
#include <set>
using namespace std;

int a[] = {10, 70, 20, 90, 50};
set<int> s(a, a + 5);

//Thêm phần tử
s.insert(60);

//Tìm phần tử
set<int>::iterator it;
it = s.find(50);
if (it != s.end())
    cout << "found";
else
    cout << "not found";

//Xoá phần tử
s.erase(20);
```
```
#include <map>
using namespace std;

map<int, string> m;
m[10] = "abc";
m[20] = "def";
m[10] = "mpk";

//Thêm phần tử
pair<int, string> p(14, "abc");
m.insert(p);

//Tìm phần tử
map<int, string>::iterator it;
it = m.find(20);
if (it != m.end())
    cout << "found";
else
    cout << "not found";

//Xoá phần tử
m.erase(14);
```
## Hàm tìm cận dưới
```
set <int>::iterator it;
it = s.lower_bound(29);
cout << *it;
```
```
map<int, string>::iterator it;
it = s.lower_bound(14);
cout << it->first << " " << it->second;
```
## Hàm tìm cận trên >
```
set <int>::iterator it;
it = s.upper_bound(29);
cout << *it;
```
```
map<int, string>::iterator it;
it = s.upper_bound(14);
cout << it->first << " " << it->second;
```
## Duyệt các phần tử của set và map
```
set<int>::iterator it;
for (it = s.begin(); it != s.end(); it++)
    cout << *it << ", ";
```
```
map<int, string>::iterator it;
for (it = m.begin(); it != m.end(); it++)
    cout << it->first << " " << it->second << ", ";
```
## Duyệt ngược các phần tử của set và map
```
set<int>::reverse_iterator it;
for (it = s.rbegin(); it != s.rend(); it++)
    cout << *it << ", ";
```
```
map<int, string>::reverse_iterator it;
for (it = m.rbegin(); it != m.rend(); it++)
    cout << it->first << " " << it->second << ", ";
```