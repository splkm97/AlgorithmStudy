#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
bool visit[1002][1002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
queue<pair<int, int> > Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int seq = 0;
	int zeroCnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push({ i, j });
				seq++;
			}
			if (board[i][j] == 0) {
				zeroCnt++;
			}
		}
	}
	if (zeroCnt == 0 && Q.empty()) {
		cout << 0;
		return 0;
	}
	if (Q.empty()) {
		cout << -1;
		return 0;
	}
	int cnt = 0;
	int ans = 0;
	while (!Q.empty()) {
		cnt = 0;
		for (int i = 0; i < seq; i++) {
			pair<int, int> cur = Q.front();
			Q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;
				if (visit[nx][ny] == 1 || board[nx][ny] == -1)
					continue;

				board[nx][ny] = 1;
				visit[nx][ny] = 1;
				cnt++;
				Q.push({ nx, ny });
			}
		}
		seq = cnt;
		ans++;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				ans = 0;
			}
		}
	}

	cout << ans-1;

	return 0;
}