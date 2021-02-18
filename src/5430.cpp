#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for (int tc = 1; tc <= n; tc++) {
		string com;
		string numStr;
		cin >> com;
		int size; cin >> size;
		cin >> numStr;
		istringstream ss(numStr);
		string stringBuffer;
		deque<int> nums;
		if (size != 0) {
			getline(ss, stringBuffer, '[');
			for (int i = 0; i < size - 1; i++) {
				getline(ss, stringBuffer, ',');
				nums.push_back(stoi(stringBuffer));
			}
			getline(ss, stringBuffer, ']');
			nums.push_back(stoi(stringBuffer));
		}

		bool isErr = false;
		bool mode = true;
		for (int i = 0; i < com.length(); i++) {
			if (com.at(i) == 'R') {
				mode = !mode;
			}
			else if(com.at(i) == 'D') {
				if (nums.empty()) {
					isErr = true;
					break;
				}
				if (mode) {
					// 앞에서 삭제
					nums.pop_front();
				}
				else {
					// 뒤에서 삭제
					nums.pop_back();
				}
			}
		}
		
		if (isErr) {
			cout << "error\n";
		}
		else {
			cout << '[';
			int nsize = nums.size();
			for (int i = 0; i < nsize - 1; i++) {
				if (mode) {
					cout << nums.front() << ',';
					nums.pop_front();
				}
				else {
					cout << nums.back() << ',';
					nums.pop_back();
				}
			}
			if(!nums.empty())
				cout << nums.front();
			cout << "]\n";
		}
	}

	return 0;
}