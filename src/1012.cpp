#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int board[52][52];
bool vis[52][52];

queue<pair<int, int> > q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int m, n, k;
		int cnt = 0;

		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
			// k 개의 배추 넣기
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j]) {
					continue;
				}
				if (board[i][j] == 0) {
					continue;
				}
				cnt++;

				q.push({ i, j });

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx > m || ny < 0 || ny > n)
							continue;
						if (vis[nx][ny])
							continue;
						if (board[nx][ny] == 0)
							continue;

						vis[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}

		cout << cnt << '\n';

		while (!q.empty()) {
			q.pop();
		}
		memset(board, 0, sizeof(board));
		memset(vis, 0, sizeof(vis));
	}

	return 0;
}