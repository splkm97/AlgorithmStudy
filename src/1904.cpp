#include "bits/stdc++.h"

using namespace std;

int N;
int dp[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3 ;i <= N ;i ++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[N];

    return 0;
}
