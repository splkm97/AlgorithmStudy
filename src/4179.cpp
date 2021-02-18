#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char board[1002][1002];
int fdist[1002][1002];
int jdist[1002][1002];
bool visit[1002][1002];
bool jvisit[1002][1002];
queue<pair<int, int> > jQ;
queue<pair<int, int> > fQ;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int seg = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				fQ.push({ i, j });
			}
			if (board[i][j] == 'J') {
				jQ.push({ i, j });
			}
		}
	}
	int seq = 1;
	int cnt = 0;
	int time = 1;

	while (!fQ.empty()) {

		cnt = 0;
		for (int i = 0; i < seq; i++) {
			pair<int, int> cur = fQ.front();
			fQ.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue; 
				if (visit[nx][ny] == 1 || (board[nx][ny] != '.' && board[nx][ny] != 'J'))
					continue;

				visit[nx][ny] = 1;
				cnt++;
				fQ.push({ nx, ny });
				fdist[nx][ny] = time;
			}
		}

		time++;
		seq = cnt;
		
	}
	seq = 1;
	cnt = 0;
	time = 1;

	bool ans = false;
	while (!jQ.empty()) {
		cnt = 0;
		if (ans) {
			break;
		}
		for (int i = 0; i < seq; i++) {
			if (ans) {
				break;
			}
			pair<int, int> cur = jQ.front();
			jQ.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					ans = true;
					break;
				}
				if (jvisit[nx][ny] == 1 || (board[nx][ny] != '.' && board[nx][ny] != 'J'))
					continue;
				if (fdist[nx][ny] != 0 && fdist[nx][ny] <= time)
					continue;

				jvisit[nx][ny] = 1;
				cnt++;
				jQ.push({ nx, ny });
				jdist[nx][ny] = time;
			}
		}

		time++;
		seq = cnt;
	}

	if (ans) {
		cout << time-1;
	}
	else {
		cout << "IMPOSSIBLE";
	}
	
	return 0;
}