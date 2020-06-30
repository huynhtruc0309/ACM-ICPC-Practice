#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, Q, q;
    cin >> N;
    vector<int> n(N);
    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> q;
        int left = 0, right = N-1;
        int maxLower = -1;

        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (n[mid] < q)
            {
                left =  mid + 1;
                if (mid > maxLower)
                    maxLower = mid;
            }
            else
            {
                right = mid - 1;
            }
        } 
        
        if (maxLower == -1){
            if (n[0] > q)
                cout << "X " << n[0] << "\n";
            else cout << "X X\n";
        }
        else {
            cout << n[maxLower] << " ";
            if (maxLower + 1 < N && n[maxLower + 1] > q) 
                cout << n[maxLower + 1] << "\n";
            else {
                if (maxLower + 2 < N && n[maxLower + 2] > q) 
                    cout << n[maxLower + 2] << "\n";
                else cout << "X\n";
            }
        }
        /*
        else 
            cout << n[maxLower];
        
        cout << ' ';
        if (minHigher == INT_MAX)
            cout << 'X' << endl;
        else 
            cout << n[minHigher] << endl;
        //cout << maxLower << ' ' << N << 'a';
        
        if (maxLower + 1 >= N)
            cout << 'X' << endl;
        else if (n[maxLower + 1] > q)
            cout << n[maxLower + 1] << endl;
        else
            cout << n[maxLower + 2] << endl;    
            */
    }
    return 0;
}