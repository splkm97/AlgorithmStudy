#include <bits/stdc++.h>

using namespace std;

int dp[10][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	
	int N; cin >> N;
	
	dp[0][0] = 0;
	for(int i = 1; i < 10; i ++) {
		dp[i][0] = 1;
	}
	for(int i = 1; i < N; i ++)	
	{
		dp[0][i] = dp[1][i-1];
		for(int j = 1; j < 9; j ++) {
			dp[j][i] = dp[j-1][i-1] + dp[j+1][i-1];
		}
		dp[9][i] = dp[8][i-1];
		for(int j = 0; j < 10; j ++)
		{
			dp[j][i] %= 1000000000;
		}
	}
	int sum = 0;
	for(int i = 0; i < 10; i ++)
	{
		sum += dp[i][N-1];
		sum %= 1000000000;
	}
	cout << sum;
	
	return 0;
}
