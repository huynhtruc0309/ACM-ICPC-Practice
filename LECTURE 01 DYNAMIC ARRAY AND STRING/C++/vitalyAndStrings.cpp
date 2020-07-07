#include <iostream>
#include <string>

using namespace std;

bool isSmaller(string s1, string s2) {
    int len = s1.size();

    if (s1[len - 1] + 1 < s2[len - 1])
        return true;

    for (int i = s1.size() - 2; i >= 0; i--) {
        if (s1[i] < s2[i]) 
            return true;
    }
    return false;
}

string betweenString(string s1, string s2) {
    string s(s1);
    int i = 0;
    int mem = 0;
    do {
        if (s[s1.size() - 1 - i] + 1 > 'z') {
            s[s1.size() - 1 - i] = 'a';
            mem = 1;
        }
        else {
            s[s1.size() - 1 - i] = s[s1.size() - 1 - i] + 1;
            mem = 0;
        }
        i++;
        
    } while (mem);
    return s;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (isSmaller(s1, s2) == false)
        cout << "No such string";
    else {
        string s = betweenString(s1, s2);
        cout << s;
    }

    return 0;
}