#include <bits/stdc++.h>

using namespace std;

int dist[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	int dx[2] = { U, -1 * D };
	queue<int> q;
	q.push(S);
	bool isEnd = false;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int dir = 0; dir < 2; dir++) {
			int next = cur + dx[dir];
			if (next < 1 || next > F)
				continue;
			if (dist[next] != 0 || next == S)
				continue;
			
			q.push(next);
			dist[next] = dist[cur] + 1;
			if (next == G) {
				isEnd = true;
				break;
			}
		}
		if (isEnd) {
			break;
		}
	}
	if (!isEnd && S != G) {
		cout << "use the stairs\n";
	}
	else if (S == G) {
		cout << "0\n";
	} else {
		cout << dist[G] << "\n";
	}

	return 0;
}