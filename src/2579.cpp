#include <bits/stdc++.h>

using namespace std;

int dp[305][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num; cin >> num;
	vector<int> vec;
	vec.push_back(0);
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	dp[1][0] = vec[1];	// 1
	dp[2][0] = vec[2];	// 2
	dp[2][1] = dp[1][0] + vec[2];	// 1 2
	for (int i = 3; i <= num; i++) {
		dp[i][0] = max({ dp[i - 2][0], dp[i - 2][1] }) + vec[i];
		dp[i][1] = dp[i - 1][0] + vec[i];
	}
	cout << max({ dp[num][0], dp[num][1] }) << '\n';

	return 0;
}
