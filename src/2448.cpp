#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> ans;

void spreadStar(int num, int line, int type) {
	if (num == 3) {
		if (type == 1) {
			ans[line].push_back(' ');
			ans[line].push_back(' ');
			ans[line].push_back('*');
			ans[line].push_back(' ');
			ans[line].push_back(' ');
			ans[line + 1].push_back(' ');
			ans[line + 1].push_back('*');
			ans[line + 1].push_back(' ');
			ans[line + 1].push_back('*');
			ans[line + 1].push_back(' ');
			ans[line + 2].push_back('*');
			ans[line + 2].push_back('*');
			ans[line + 2].push_back('*');
			ans[line + 2].push_back('*');
			ans[line + 2].push_back('*');
		}
		if (type == 2) {
			for (int i = 0; i < num; i++) {
				ans[line].push_back(' ');
				ans[line+1].push_back(' ');
				ans[line+2].push_back(' ');
			}
		}
		return;
	}
	// t2 t1 t2
	// t1 t1
	if (type == 1) {
		int point = num / 2;
		spreadStar(point, line, 2);
		spreadStar(point, line, 1);
		spreadStar(point, line, 2);
		spreadStar(point, line + point, 1);
		for (int i = point; i < num; i++) {
			ans[line + i].push_back(' ');
		}
		spreadStar(point, line + point, 1);
	}
	if (type == 2) {
		int point = num / 2;
		spreadStar(point, line, 2);
		spreadStar(point, line, 2);
		spreadStar(point, line + point, 2);
		spreadStar(point, line + point, 2);
	}
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int number; cin >> number;
	for (int i = 0; i < number; i++) {
		vector<char> temp;
		ans.push_back(temp);
	}
	spreadStar(number, 0, 1);

	for (auto vec : ans) {
		for (auto item : vec) {
			cout << item;
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}