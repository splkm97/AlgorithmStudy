#include <bits/stdc++.h>

using namespace std;

int board[10][10];
int N, M;

// dir 0:up 1:right 2:down 3:left
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cnt = 0;

void checkDir(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
		return;
	}
	if (board[nx][ny] != 6) {
		cnt++;
		checkDir(nx, ny, dir);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	vector<pair<int, int> > cctv;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) {
				cctv.push_back({ i, j });
			}
		}
	}

	int lim = cctv.size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

		}
	}

	return 0;
}