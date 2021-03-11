#include <bits/stdc++.h>
using namespace std;

int cost[1002][3];
int dp[1002][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	int minval = min(dp[N - 1][0], dp[N - 1][1]);
	minval = min(minval, dp[N - 1][2]);
	cout << minval;

	return 0;
}