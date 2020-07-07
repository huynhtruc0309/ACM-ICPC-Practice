#include <iostream>
#include <queue>
using namespace std;
vector<int> h;

int top()
{
    return h[0];
}

void push(int value)
{
    h.push_back(value);
    int i = h.size()-1;
    while (i != 0 && h[(i-1)/2] > h[i])
    {
        swap(h[i], h[(i-1)/2]);
        i = (i-1)/2;
    }
}

void pop(int value)
{
    int length = h.size();
    if (length == 0)
        return;
    h[0] = h[length-1];
    h.pop_back();
    minHeapify(0);
}

void minHeapify(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < h.size() && h[left] < h[smallest])
        smallest = left;
    if (right < h.size() && h[right] < h[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(h[i], h[smallest]);
        minHeapify(smallest);
    }
}

int main()
{
    int N;
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        if (a == 1)
        {
            push(b);
        }
        else if (a == 2)
        {
            pop(b);
        }
        else
        {
            cout << top() << endl;
        }
        
    }
    return 0;
}