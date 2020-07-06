#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 26

struct Node {
    struct Node *child[MAX];
    int weight;
};

struct Node *newNode()
{
    struct Node *node = new Node;
    node->weight = 0;
    for (int i = 0; i < MAX; i++)
        node->child[i] = NULL;
    return node;
}

void addWord(struct Node *root, string s, int weight)
{
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            temp->child[ch] = newNode();
            
        temp = temp->child[ch];
        temp->weight = max(temp->weight, weight);
    }
}

int findWord(Node *root, string s)
{
    int ch;
    struct Node *temp = root;

    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            return -1;

        temp = temp->child[ch];
    }
    return temp->weight;
}

int main()
{
    int n, q, w;
    string s;
    cin >> n >> q;
    struct Node *root = newNode();

    for (int i = 0; i < n; i++)
    {
        cin >> s >> w;
        addWord(root, s, w);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> s;
        cout << findWord(root, s) << endl;
    }
    return 0;
}