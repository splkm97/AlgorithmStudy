#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num; cin >> num;
	int count = 0;
	string str;
	vector<bool> flag(26, false);
	for (int tc = 1; tc <= num; tc++) {
		bool isOK = true;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (flag[str.at(i) - 'a']) {
				isOK = false;
				break;
			}
			else {
				for (int j = i; j < str.length(); j++) {
					if (str.at(i) == str.at(j)) {
						continue;
					}
					else {
						flag[str.at(i) - 'a'] = true;
						i = j - 1;
						break;
					}
				}
			}
		}

		if (isOK) {
			count++;
		}
		flag.assign(26, false);
	}
	cout << count << '\n';

	return 0;
}