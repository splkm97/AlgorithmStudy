#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<pair<int, int> > v;

void hanoi(int num, int src, int path, int dest) {
	int result;

	if (num == 1) {
		cnt++;
		v.push_back({ src, dest });
		return;
	}
	
	hanoi(num - 1, src, dest, path);
	cnt++;
	v.push_back({ src, dest });
	hanoi(num - 1, path, src, dest);

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	hanoi(n, 1, 2, 3);
	cout << cnt << "\n";
	for (auto item : v) {
		cout << item.first << " " << item.second << "\n";
	}

	return 0;
}