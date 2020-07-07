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
    }
    temp->countWord++;
}

int main()
{
    return 0;
}