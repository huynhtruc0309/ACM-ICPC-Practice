# BINARY SEARCH TREE
## 0. Khai báo cấu trúc một node trong BST
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