#include <bits/stdc++.h>

using namespace std;
int board[502][502];
int visited[502][502];
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0, m = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	int paintCount = 0;
	int maxArea = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || visited[i][j] == 1)
				continue;
			if (board[i][j] == 1 && visited[i][j] == 0)
			{
				paintCount++;
				queue<pair<int, int>> Q;
				visited[i][j] = 1;
				Q.push({ i, j });
				int paintArea = 0;
				while (!Q.empty())
				{
					paintArea++;
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int check = 0; check < 4; check++)
					{
						int nx = cur.first + dx[check];
						int ny = cur.second + dy[check];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (visited[nx][ny] == 1 || board[nx][ny] != 1)
							continue;
						visited[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				if (maxArea < paintArea)
					maxArea = paintArea;
			}
		}
	}

	cout << paintCount << "\n";
	cout << maxArea << "\n";
	return 0;
}