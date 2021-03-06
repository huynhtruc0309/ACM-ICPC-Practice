#include <iostream>
#include <string>
using namespace std;
#define MAX 10
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
        ch = s[i] - '0';
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
    int testcase, n;
    string s;
    bool has;
    int i = 0;
    cin >> testcase;
    while(testcase--)
    {
        struct Node *root = newNode();
        has = false;
        i++;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            //cout << has << endl;
            if (!has)
                has = addWord(root, s);
        }
        cout << "Case " << i <<  ": ";
        if (has)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}