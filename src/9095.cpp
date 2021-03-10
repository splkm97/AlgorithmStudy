#include <bits/stdc++.h>

using namespace std;

int dp[15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tests; cin >> tests;
	for (int tc = 1; tc <= tests; tc++) {
		int num; cin >> num;
		dp[1] = 1;
		dp[2] = 2; // 2 11
		dp[3] = 4; // 3 21 12 111
		for (int i = 4; i <= num; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[num] << '\n';
	}
	return 0;
}