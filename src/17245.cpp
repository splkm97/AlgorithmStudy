include "bits/stdc++.h"

using namespace std;

typedef unsigned long long ull;

int N;
ull board[1002][1002];

ull count(ull height) {
	ull sum = 0;
	for (int i = 0 ;i < N ;i ++ ) {
		for (int j = 0 ;j < N ;j ++) {
			if (board[i][j] <= height) {
				sum += board[i][j];
			} else {
				sum += height;
			}
		}
	}
	return sum;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	ull maxH = 0, sum = 0;

	cin >> N;
	for (int i = 0 ;i < N; i ++) {
		for (int j = 0 ;j < N ;j ++) {
			cin >> board[i][j];
			if (board[i][j] > maxH) {
				maxH = board[i][j];
			}
			sum += board[i][j];
		}
	}
	ull halfOfSum = sum / 2;
	if (sum % 2 == 1) {
		halfOfSum ++;
	}


	ull lt, rt;
	lt = 1;
	rt = maxH;
	ull mid;
	while (lt < rt) {
		mid = (lt + rt) / 2;
		if (count(mid) >= halfOfSum) {
			rt = mid;
		} else {
			lt = mid + 1;
		}
	}
	cout << rt << "\n";

	return 0;
}

