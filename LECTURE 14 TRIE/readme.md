# TRIE
## Cấu trúc cây Trie
### C++
```
#include <iostream>
#include <string>
using namespace std;
#define MAX 26
struct Node {
    struct Node *child[MAX];
    int countWord;
};
```
### Python
```
class Node:
    def __init__(self):
        self.countWord = 0
        self.child = dict()
```
## Thao tác trên cây Trie
### 1. Thêm từ vào cây
### C++
```
struct Node *newNode()
{
    struct Node *node = new Node;
    node->countWord = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node *root, string s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countWord++;
}
```
### Python
```
def addWord(root, s):
    temp = root
    for ch in s:
        if ch not in temp.child:
            temp.child[ch] = Node()
        temp = temp.child[ch]
    temp.countWord += 1
```
## 2. Tìm kiếm từ trong cây
### C++
```
bool findWord(Node *root, string s)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            return false;
        }
        temp = temp->child[ch];
    }
    return temp->countWord > 0;
}
```
### Python
```
def findWord(root, s):
    temp = root
    for ch in s:
        if ch not in temp.child:
            return False
        temp = temp.child[ch]
    return temp.countWord > 0
```
## Xoá từ trong cây
### C++
```
bool isWord(struct Node *node)
{
    return (node->countWord != 0);
}

bool isEmpty(struct Node *node)
{
    for (int i = 0; i < MAX; i++)
    {
        if (node->child[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

bool removeWord(struct node *root, string s, int level, int len)
{
    if (!root)
        return false;
    int ch = s[level] - 'a';
    if (level == len)
    {
        if (root->countWord > 0)
        {
            root->countWord--;
            return true;
        }
        return false;
    }
    int flag = removeWord(root->child[ch], s, level + 1, len);
    if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch]))
    {
        delete root->child[ch];
        root->child[ch] == NULL;
    }
    return flag;
}
```
### Python
```
def isWord(node):
    return node.countWord != 0

def isEmpty(node):
    return len(node.child) == 0

def removeWord(root, s, level, len):
    if root == None:
        return False
    if level == len:
        if root.countLeaf > 0:
            root.countLeaf -= 1
            return True
        return False
    ch = s[level]

    if ch not in root.child:
        return False
    
    flag = removeWord(root.child[ch], s, level + 1, len)
    if flag == True and isWord(root.child[ch]) == False and isEmpty(root.child[ch]) == True:
        del root.child[ch]
    return flag
```
## In toàn bộ từ trong cây
### C++
```
void printWord(struct Node* root, string s)
{
    if (isWord(root))
    {
        cout << s << endl;
    }
    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i])
        {
            printWord(root->child[i], s + (char)('a' + i));
        }
    }
}
```
### Python
```
def printWord(root, s):
    if isWord(root):
        print(s)
    for ch in root.child:
        printWord(root.child[ch], s + ch)
```