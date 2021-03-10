#include <bits/stdc++.h>

using namespace std;

int N;
bool col[20];
bool ldash[40];
bool rdash[40];
int cnt = 0;

void backtrack(int k) {
	if (k == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		int lp = k - i + N;
		int rp = k + i;
		if (!col[i] && !ldash[lp] && !rdash[rp]) {
			col[i] = 1;
			ldash[lp] = 1;
			rdash[rp] = 1;
			backtrack(k + 1);
			col[i] = 0;
			ldash[lp] = 0;
			rdash[rp] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	backtrack(0);
	cout << cnt;

	return 0;
}