#include <bits/stdc++.h>

using namespace std;

int dp[1002][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	// 0: 2x1 1개
	// 1: 1x2 2개
	// 2: 2x2 1개
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 10007;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2]) % 10007;
		dp[i][2] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2]) % 10007;
	}

	int sum = dp[n][0] + dp[n][1] + dp[n][2];
	sum %= 10007;
	cout << sum;

	return 0;
}
