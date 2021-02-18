#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> ans;

void spreadStar(int num, int line, int type) {
	if (num == 0) {
		if (type == 1) {
			ans[line].push_back('*');
		}
		else {
			ans[line].push_back(' ');
		}
		return;
	}
	// type1 type1
	// type1 type2
	int point = 1;
	point = point << (num - 1);
	if (type == 1) {
		spreadStar(num - 1, line, 1);
		spreadStar(num - 1, line, 1);
		spreadStar(num - 1, line+point, 1);
		spreadStar(num - 1, line+point, 0);
	}
	else {
		spreadStar(num - 1, line, 0);
		spreadStar(num - 1, line, 0);
		spreadStar(num - 1, line+point, 0);
		spreadStar(num - 1, line+point, 0);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int number; cin >> number;
	for (int i = 0; i <= (1 << number) -1; i++) {
		vector<char> temp;
		ans.push_back(temp);
	}
	if (number == 0) {
		spreadStar(number, 0, 1);
	}
	else {
		spreadStar(number, 0, 1);
	}
	int size = ans.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			ans[i].pop_back();
		}
	}
	for (auto vec : ans) {
		for (auto item : vec) {
			cout << item;
		}
		cout << "\n";
	}

	return 0;
}