#include <bits/stdc++.h>

using namespace std;

bool board[130][130];
int cnt[2] = { 0, 0 };

void checkAndCount(int num, int curx, int cury) {
	bool color;
	bool isEnd = true;
	color = board[cury][curx];
	for (int i = cury; i < cury + num; i++) {
		for (int j = curx; j < curx + num; j++) {
			if (color != board[i][j]) {
				isEnd = false;
				break;
			}
		}
	}
	if (isEnd) {
		cnt[color]++;
		return;
	}
	else {
		int point = num / 2;
		checkAndCount(point, curx, cury);
		checkAndCount(point, curx + point, cury);
		checkAndCount(point, curx, cury + point);
		checkAndCount(point, curx + point, cury + point);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	checkAndCount(n, 0, 0);

	cout << cnt[0] << "\n" << cnt[1] << "\n";

	return 0;
}