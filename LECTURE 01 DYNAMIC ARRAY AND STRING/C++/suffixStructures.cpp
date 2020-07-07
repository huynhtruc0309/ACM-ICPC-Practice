#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    string s, t;
	cin >> s >> t;

	bool need_tree = false, automaton = false, array = false;
	char sCount[26] = {0}, tCount[26] = {0};

	for (int i = 0; i < s.size(); i++) {
		sCount[s[i] - 'a']++;
	}
	for (int i = 0; i < t.size(); i++) {
		tCount[t[i] - 'a'] ++;
	}

	for (int i = 0; i < 26; i++) {
		if (tCount[i] > sCount[i])
			need_tree = true;
		else if (tCount[i] < sCount[i])
			automaton = true;
	}

	int indexFound = 0, match = -1;
	for (int i = 0; i < t.size(); i++) {
		indexFound = s.find_first_of(t[i], match + 1);
		if (indexFound > match)
			match = indexFound;
		else {
			array = true;
			break;
		}
	}

	if (need_tree)
		cout << "need tree";
	else if (automaton && array)
		cout << "both";
	else if (automaton)
		cout << "automaton";
	else
		cout << "array";

    return 0;
}

/* Nhận xét:
- Biến s-> t: s có tất cả kt trong t.
- s không chứa tất cả kt của t: -> "need tree"
- s chứa tất cả kt của t:
	+ s không có kt thừa -> "array"
	+ s có kt thừa -> "automation"
		+ kiểm tra có cần dùng array
			+ có: both
			+ khong: automaton      

Cách giải:
B1: Đọc 2 chuỗi s, t
B2: Kiểm tra a b ... z
	+ Nếu skt > tkt: automaton = true
	+ Nếu skt < tkt: need_tree = true
B3: Kiểm tra thứ tự xuất hiện của kt trong t có trùng trong s"
	+ có -> array = false
	+ ko -> array = true
B4: In kết quả  

Gợi ý sử dụng hàm find_first_of

s = input()
*/