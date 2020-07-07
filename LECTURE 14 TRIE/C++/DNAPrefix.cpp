#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define MAX 4

struct Node {
    struct Node *child[MAX];
    int prefix;
    int level;
};

struct Node *newNode(int level)
{
    struct Node *node = new Node;
    node->prefix = 0;
    node->level = level;
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
        if (s[i] == 'A')
            ch = 0;
        else if (s[i] == 'C')
            ch = 1;
        else if (s[i] == 'G')
            ch = 2;
        else if (s[i] == 'T')
            ch = 3;

        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode(temp->level + 1);
        }
        temp = temp->child[ch];
        temp->prefix++;
    }
}

long long dfs(struct Node *root)
{
    long long mx = 0;
	
	stack<struct Node *> s;
	s.push(root);
	
	struct Node *node;
	while(!s.empty())
	{
		node = s.top();
		s.pop();
		if(node->level * node->prefix > mx) 
            mx = node->level * node->prefix;

		for(int i = 0; i < MAX; i++)
			if(node->child[i] != NULL) s.push(node->child[i]);
	}
	
	return mx;
}

int main()
{
    int testcase, n;
    string s;
    int i = 0;
    cin >> testcase;
    while(testcase--)
    {
        struct Node *root = newNode(0);
        i++;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            addWord(root, s);
        }
        cout << "Case " << i <<  ": " << dfs(root) << endl;
    }
    return 0;
}