#include <iostream>
#include <vector>
using namespace std;
/*
void timePassword(vector<string> arr, int n, int k) {
    vector<int> len(100, 0);

    for (int i = 0; i < n; i++) {
        len[arr[i].length()]++;
    }

    int best = 0, worst = 0;
    int passLen = arr[n].length();
    for (int i = 0; i < len.size(); i++) {
        if (len[i] != 0) {
            if (i < passLen) {
                while (len[i] >= k) { //5 -> 3 -> 1
                    len[i] -= k;
                    worst += k; // 0 -> 2 -> 5 -> 7 -> 9 -> 
                    worst += 5;

                    best += k;
                    best += 5;
                }
                
                worst += len[i];
                best += len[i];
            }
            
            else if (i == passLen){
                best += 1;
                while (len[i] >= k) { //4-2-0
                    len[i] -= k;
                    worst += k; //
                    worst += 5;
                }
                
                worst += len[i];
            }
        }
        
    }

    cout << best << ' ' << worst;
}
*/
int main() {
    int n, k;
    cin >> n >> k;
    int cnt[101] = {0};
    string s, password;

    for (int i = 0; i < n ; i++) {
        cin >> s;
        cnt[s.size()]++;
    }
    cin >> password;

    int bestTime = 0, worstTime = 0;
    for (int i = 0; i < password.size(); i++) {
        bestTime += cnt[i];
    }
    worstTime =  bestTime + cnt[password.size()] - 1;
    bestTime += (bestTime/k)*5 + 1;
    worstTime += (worstTime/k)*5 + 1;

    cout << bestTime << ' ' << worstTime;
    
    return 0;
}
/* Nhận xét:
- Thử tất cả chuỗi có độ dài < len(pass)
    time = thời gian...
- best_time = time + (time/k)* 5 + 1
trial_worst_time = time + tổng thời gian thử các chuỗi có độ dài bằng len(pass) khác pass
worst_time = trial_worst_time + (trial_worst_time/k)*5 + 1


Mã giả:
- Nhập n, K. Khởi tạo cnt[101] = {0}
- For i = 0-> n:
    Nhập s
    cnt[len(s)]++
- Nhập pass
- time = 0
    for i = 1 -> i < len(pass)
        time += cnt[i]

- best_time = time + (time/k) * 5 + 1
- time += cnt[len(s)] - 1
- worst_time = time + (time/k) * 5 + 1
*/