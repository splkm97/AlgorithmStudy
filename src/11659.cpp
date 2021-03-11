#include <bits/stdc++.h>
using namespace std;

int arr[1000002];
int dp[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << dp[y-1] - dp[x-2] << '\n';
	}

	return 0;
}