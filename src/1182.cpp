#include <bits/stdc++.h>

using namespace std;

int N, S;
int cnt = 0;
int arr[22];
int curSum = 0;
int usedcnt = 0;

void backtrack(int k) {
	if (k == N) {
		if (curSum == S && usedcnt != 0) {
			cnt++;
		}
		return;
	}
	backtrack(k + 1);
	curSum += arr[k];
	usedcnt++;
	backtrack(k + 1);
	curSum -= arr[k];
	usedcnt--;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	backtrack(0);

	cout << cnt;

	return 0;
}