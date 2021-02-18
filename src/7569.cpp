#include <bits/stdc++.h>

using namespace std;

int tomato[102][102][102];
bool vis[102][102][102];

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h;
	queue<vector<int> > q;

	cin >> m >> n >> h;

	int nTom = 0;
	bool isTomAll = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				vector<int> temp;
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					temp.push_back(i);
					temp.push_back(j);
					temp.push_back(k);
					q.push(temp);
					nTom++;
				}
				if (tomato[i][j][k] == 0) {
					isTomAll = false;
				}
			}
		}
	}

	if (isTomAll) {
		cout << "0\n";
		return 0;
	}

	int newNTom = 0;
	int day = 0;
	while (!q.empty()) {
		for (int r = 0; r < nTom; r++) {
			vector<int> cur = q.front();
			q.pop();

			for (int dir = 0; dir < 6; dir++) {
				int nx = cur[2] + dx[dir];
				int ny = cur[1] + dy[dir];
				int nz = cur[0] + dz[dir];

				if (nx < 0 || nx >= m)
					continue;
				if (ny < 0 || ny >= n)
					continue;
				if (nz < 0 || nz >= h)
					continue;
				if (vis[nz][ny][nx])
					continue;
				if (tomato[nz][ny][nx] != 0)
					continue;
				vis[nz][ny][nx] = true;
				tomato[nz][ny][nx] = 1;
				vector<int> temp;
				temp.push_back(nz);
				temp.push_back(ny);
				temp.push_back(nx);
				q.push(temp);
				newNTom++;
			}
		}
		nTom = newNTom;
		newNTom = 0;
		day++;
	}

	bool isTomCant = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0)
					isTomCant = true;
			}
		}
	}
	
	if (isTomCant) {
		cout << "-1\n";
		return 0;
	}
	
	cout << day-1 << "\n";

	return 0;
}