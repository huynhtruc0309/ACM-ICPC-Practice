#include <iostream>
#include <string>
using namespace std;
#define MAX 26
struct Node {
    struct Node *child[MAX];
    int countWord;
};

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
        temp->countWord++;
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
        {
            return 0;
        }
        temp = temp->child[ch];
    }
    return temp->countWord;
}

int main()
{
    int n;
    cin >> n;
    string query, s;
    struct Node *root = newNode();;
    for (int i = 0; i < n; i++)
    {
        cin >> query >> s;
        if (query == "add")
            addWord(root, s);
        else if (query == "find")
            cout << findWord(root, s) << endl;
    }
    return 0;
}