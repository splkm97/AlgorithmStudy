#include <bits/stdc++.h>

using namespace std;

int dp[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[N];

	return 0;
}