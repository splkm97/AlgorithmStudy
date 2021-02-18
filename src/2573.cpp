#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int prevmap[304][304];
int curmap[304][304];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> prevmap[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (prevmap[i][j] < 1) {
				continue;
			}
			int temp = prevmap[i][j];
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (prevmap[nx][ny] > 0) {
					continue;
				}
				
				temp--;
			}
			curmap[i][j] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			prevmap[i][j] = curmap[i][j];
		}
	}

	return 0;
}