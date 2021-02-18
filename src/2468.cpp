#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[102][102];
bool visit[102][102];
int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int min_h =101, max_h = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			min_h = min(min_h, board[i][j]);
			max_h = max(max_h, board[i][j]);
		}
	}
	int ans = 1;
	int cnt = 0;
	stack<pair<int, int> > s;
	for (int h = max_h; h > min_h; h--){
		cnt = 0;
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				visit[k][l] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				if (!visit[i][j] && board[i][j] >= h) {
					visit[i][j] = true;
					cnt++;
					s.push({ i, j });
				}
				while (!s.empty()) {
					pair<int, int> cur = s.top();
					s.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
							continue;
						}
						if (visit[nx][ny] || board[nx][ny] < h) {
							visit[nx][ny] = true;
							continue;
						}
						visit[nx][ny] = true;
						s.push({ nx, ny });
					}
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}