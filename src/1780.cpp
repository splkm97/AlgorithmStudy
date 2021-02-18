#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int cnt[3] = { 0 };

void calCount(int num, int curx, int cury) {
	if (num == 1) {
		int type = board[curx][cury];
		if (type == -1) {
			cnt[2] ++;
		}
		else {
			cnt[type] ++;
		}
		
		return;
	}
	int point = num / 3;
	bool isFalse = false;
	int type = board[curx][cury];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (board[curx + i][cury + j] != type) {
				isFalse = true;
				break;
			}
		}
		if (isFalse) {
			break;
		}
	}
	if (!isFalse) {
		if (type == -1) {
			cnt[2] ++;
		}
		else {
			cnt[type] ++;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				calCount(point, curx + (i * point), cury + (j * point));
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int number; cin >> number;

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cin >> board[i][j];
		}
	}
	calCount(number, 0, 0);

	cout << cnt[2] << "\n" << cnt[0] << "\n" << cnt[1] << "\n";

	return 0;
}