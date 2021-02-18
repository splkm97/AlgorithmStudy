#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool area[102][102];
bool vis[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> ans;
	queue<pair<int, int> > q;

	int n, m, k;

	cin >> n >> m >> k;
	deque<pair<int, int> > points;

	for (int i = 0; i < 2*k; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back({ x, y });
		// 0-1번 2-3번 4-5번 인덱스끼리 쌍으로 직사각형이다.
	}
	
	while (!points.empty()) {
		pair<int, int> p1;
		pair<int, int> p2;

		p1 = points.front();
		points.pop_front();
		p2 = points.front();
		points.pop_front();
		
		for (int i = n-p2.Y;  i < n-p1.Y; i++) {
			for (int j = p1.X; j < p2.X; j++) {
				area[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || area[i][j])
				continue;
			q.push({ i, j });
			int cnt = 1;
			vis[i][j] = true;
			while (!q.empty()) {
				pair<int, int> cur;
				cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
						continue;
					}
					if (vis[nx][ny] || area[nx][ny]) {
						continue;
					}
					cnt++;
					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}