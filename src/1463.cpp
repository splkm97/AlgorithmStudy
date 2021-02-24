#include <bits/stdc++.h>

using namespace std;

int dp[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num; cin >> num;
	dp[1] = 0;
	for (int i = 2; i <= num; i++) {
		int case1 = INT_MAX;
		int case2 = INT_MAX;
		int case3 = dp[i - 1] + 1;
		if (i % 2 == 0) {
			case1 = dp[i / 2] + 1;
		}
		if (i % 3 == 0) {
			case2 = dp[i / 3] + 1;
		}
		dp[i] = min({ case1, case2, case3 });
	}
	cout << dp[num];
	return 0;
}
