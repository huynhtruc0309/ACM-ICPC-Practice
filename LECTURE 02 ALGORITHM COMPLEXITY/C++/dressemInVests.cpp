/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> A(N), B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int c = 0;
    vector<vector<int>> pair;
    int idxB = 0;
    for (int idxA = 0; idxA < N; idxA++) {
        if (B[idxB] >= A[idxA] - X && B[idxB] <= A[idxA] + Y) {
            pair.push_back({idxA + 1, idxB + 1});
            c++;
            idxB++;
        }
        else if (B[idxB] < A[idxA])
            idxB++;

        if (idxB >= M)
            break;
    }
    cout << c << endl;
    for (int i = 0; i < pair.size(); i++) {
        cout << pair[i][0] << ' ' << pair[i][1]  << endl;
    }
    return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m, x, y, a[100005]={0}, b[100005]={0}, cnt=0, k=0, c[100005]={0}, d[100005]={0};
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int j=0; j<m; j++) scanf("%d", &b[j]);
    sort(a, a+n), sort(b, b+m);
    for(int i=0; i<n; i++) {
        while(a[i]-x>b[k] && k<m) k++; 
        if(a[i]+y<b[k]) continue;
        if(k==m) break;
        c[cnt]=i+1, d[cnt]=k+1, cnt++, k++;
    }
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++) printf("%d %d\n", c[i], d[i]);
    return 0;
}