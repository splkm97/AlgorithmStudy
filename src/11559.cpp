#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;

char board[14][8];
bool vis[14][8];

bool checkAndPopPuyo() {
	bool isEnd = true;
	queue<pair<int, int> > Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vis[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			queue<pair<int, int> > popLoc;
			if (!vis[i][j] && board[i][j] != '.') {
				Q.push({ i, j });
				popLoc.push({ i, j });
				vis[i][j] = true;
				char color = board[i][j];
				int colorcnt = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
							continue;
						}
						if (vis[nx][ny] || board[nx][ny] != color) {
							continue;
						}
						Q.push({ nx, ny });
						popLoc.push({ nx, ny });
						vis[nx][ny] = true;
						colorcnt++;
					}
				}
				if (colorcnt >= 4) {
					isEnd = false;
					while (!popLoc.empty()) {
						pair<int, int> cur = popLoc.front();
						popLoc.pop();
						board[cur.X][cur.Y] = 'x';
					}
				}
				else {
					while (!popLoc.empty()) {
						popLoc.pop();
					}
				}
			}
		}
	}
	return isEnd;
}

int checkUpside(int x, int y) {
	if (x == 0) {
		return -1;
	}
	char item = board[x - 1][y];
	if (item == 'x') {
		return checkUpside(x - 1, y);
	}
	else {
		return x - 1;
	}
}

void calGravity() {
	for (int i = N; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'x') {
				int k = checkUpside(i, j);
				if (k == -1) {
					for (int l = i; l >= 0; l--) {
						if (board[l][j] == '.') {
							break;
						}
						board[l][j] = '.';
					}
				}
				else {
					for (int l = i; l >= k; l--) {
						if (k < 0) {
							break;
						}
						char temp = board[l][j];
						board[l][j] = board[k][j];
						board[k][j] = temp;
						k--;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	N = 12;
	M = 6;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line.at(j);
		}
	}

	int cnt = 0;
	while (!checkAndPopPuyo()) {
		calGravity();
		cnt++;
	}
	cout << cnt;

	return 0;
}