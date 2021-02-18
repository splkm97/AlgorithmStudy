#include <bits/stdc++.h>
using namespace std;

int N, r, c;
int cnt = 0;

void search(int size, int curx, int cury) {
	if (size == 1) {
		if (curx == c && cury == r) {
		}
		else if (curx + 1 == c && cury == r) {
			cnt++;
		}
		else if (curx == c && cury + 1 == r) {
			cnt += 2;
		}
		else {
			cnt += 3;
		}
		return;
	}
	int point = 1;
	point = point << (size-1);

	if (c < curx + point && r < cury + point) {
		search(size - 1, curx, cury);
	}
	else if (c >= curx + point && r < cury + point) {
		cnt += point * point;
		search(size - 1, curx + point, cury);
	}
	else if (c < curx + point && r >= cury + point) {
		cnt += 2 * point * point;
		search(size - 1, curx, cury + point);
	}
	else {
		cnt += 3 * point * point;
		search(size - 1, curx + point, cury + point);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;
	search(N, 0, 0);
	cout << cnt;

	return 0;
}