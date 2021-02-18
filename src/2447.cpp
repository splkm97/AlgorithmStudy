#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> ans;

void spreadStar(int num, int line, int type) {
	if (num == 1) {
		if (type == 1) {
			ans[line].push_back('*');
		} 
		else {
			ans[line].push_back(' ');
		}
		return;
	}
	int point = num / 3;
	if (type == 1) {
		spreadStar(point, line, 1);
		spreadStar(point, line, 1);
		spreadStar(point, line, 1);
		spreadStar(point, line+point, 1);
		spreadStar(point, line+point, 2);
		spreadStar(point, line+point, 1);
		spreadStar(point, line + (2 * point), 1);
		spreadStar(point, line + (2 * point), 1);
		spreadStar(point, line + (2 * point), 1);
	}
	else if (type == 2) {
		spreadStar(point, line, 2);
		spreadStar(point, line, 2);
		spreadStar(point, line, 2);
		spreadStar(point, line + point, 2);
		spreadStar(point, line + point, 2);
		spreadStar(point, line + point, 2);
		spreadStar(point, line + (2 * point), 2);
		spreadStar(point, line + (2 * point), 2);
		spreadStar(point, line + (2 * point), 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<char> temp;
		ans.push_back(temp);
	}

	spreadStar(n, 0, 1);

	for (auto line : ans) {
		for (auto item : line) {
			cout << item;
		}
		cout << "\n";
	}

	return 0;
}