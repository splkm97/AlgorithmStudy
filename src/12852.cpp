#include <bits/stdc++.h>

using namespace std;

int dp[1000002];
int pre[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	dp[0] = INT_MAX;
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		int minv = dp[i - 1] + 1;
		int mini = i - 1;
		if (i % 2 == 0) {
			if (minv > dp[i / 2] + 1) {
				minv = dp[i / 2] + 1;
				mini = i / 2;
			}
		}
		if (i % 3 == 0) {
			if (minv > dp[i / 3] + 1) {
				minv = dp[i / 3] + 1;
				mini = i / 3;
			}
		}
		dp[i] = minv;
		pre[i] = mini;
	}

	cout << dp[N] << '\n';
	while (N != 0) {
		cout << N << ' ';
		N = pre[N];
	}

	return 0;
}