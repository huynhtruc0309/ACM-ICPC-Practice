#include <iostream>
#include <vector>
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

void pop()
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

void buildHeap(int n)
{
    for (int i = n/2-1; i >= 0; i--)
        minHeapify(i);
}

int main()
{
    h = {7, 12, 6, 10, 17, 15, 2, 4};
    buildHeap(h.size());

    for (int i = 0; i < h.size(); i++)
        cout << h[i] << ' ';

    return 0;
}