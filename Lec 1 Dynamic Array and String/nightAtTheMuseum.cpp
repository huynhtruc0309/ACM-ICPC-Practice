#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    char prev = 'a';

    for (int i = 0; i < s.size(); i++) {
        if (abs(s[i] - prev) > ('z'-'a')/2)
            count += ('z'-'a') + 1 - abs(s[i] - prev);
        else
            count += abs(s[i] - prev);
            
        prev = s[i];
    }

    cout << count;
    return 0;
}