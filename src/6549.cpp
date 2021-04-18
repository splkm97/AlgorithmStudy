#include <bits/stdc++.h>

using namespace std;

long long board[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<long long> stk;
	long long n;
	cin >> n;
	while (n != 0)
	{
		for (long long i = 0; i < n; i++) {
			cin >> board[i];
		}
		board[n] = 0;
		long long maxv = 0;
		long long area = 0;
		long long curi = 0;
		stk.push(-1);
		for (long long i = 0; i < n; i++) {
			while (!stk.empty() && board[i] < board[stk.top()])
			{
				curi = stk.top();
				stk.pop();
				if (!stk.empty())
					maxv = max(maxv, board[curi] * (i - stk.top() - 1));
			}
			stk.push(i);
		}
		while (!stk.empty()) {
			curi = stk.top();
			stk.pop();
			if (!stk.empty())
			{
				long long area = (n - stk.top() - 1) * board[curi];
				if (maxv < area)
					maxv = area;
			}
		}
		cout << maxv << "\n";
		cin >> n;
	}

	return 0;
}
