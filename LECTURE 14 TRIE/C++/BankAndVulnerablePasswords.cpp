#include <iostream>
#include <string>
using namespace std;
#define MAX 50
struct Node {
    struct Node *child[MAX];
    bool check;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->check = false;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

bool addWord(struct Node *root, string s)
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
        if (temp->check)
            return true;
    }
    
    for (int i = 0; i < MAX; i++)
        if (temp->child[i] != NULL)
            return true;
        
    temp->check = true;
    return false;
}

int main()
{
    int n;
    string s;
    cin >> n;
    struct Node *root = newNode();
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (addWord(root, s))
        {
            cout << "vulnerable";
            return 0;
        }
    }
    cout << "non vulnerable";
    return 0;
}   