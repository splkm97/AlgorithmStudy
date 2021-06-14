#include <bits/stdc++.h>

using namespace std;

bool check[22];
vector<vector<pair<int, int> > > avail;

int backtrack(int depth, int line)
{
	int ret = 0;
	if (depth >= 2 * line)
		return 0;
	for (int i = 0; i < avail[depth].size(); i ++) {
		pair<int, int> cur;
		cur = avail[depth][i];
		int nx = cur.first;
		int ny = cur.second;
		if (check[nx - ny + line])
			continue;
		check[nx - ny + line] = true;
		ret = max(ret, backtrack(depth + 2, line) + 1);
		check[nx - ny + line] = false;
	}
	ret = max(ret, backtrack(depth + 2, line));
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int line;
	cin >> line;

	avail.resize(2 * line + 1);
	for (int i = 0; i < line; i ++) {
		for (int j = 0 ; j < line ; j ++ ) {
			bool temp;
			cin >> temp;
			if (temp)
				avail[i+j].push_back({i, j});
		}
	}

	int res = backtrack(0, line) + backtrack(1, line);
	cout << res;

	return 0;
}
