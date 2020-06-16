# Xây dựng cây Min-heap
```
vector<int> h;
// Hàm chuẩn hóa cây thành Min-heap
void minHeapify(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < h.size() && h[left] < h[smallest])
        smallest = left;
    if (right < h.size() && h[right] < h[smalles])
        smallest = right;
    if (smallest != i)
    {
        swap(h[i], h[smallest]);
        minHeapify(smallest);
    }
}
// Hàm xây dựng Min-heap từ mảng h[] có n phần tử: thực hiện chuẩn hóa cây từ vị trí cuối cùng có node lá
void buildHeap(int n)
{
    for (int i = n/2 - 1; i >=0; i--)
        minHeapify(i);
}

int main()
{
    h = {7, 12, 6, 10, 17, 15, 2, 4};
    buildHeap(h.size());
    
    return 0;
}
```