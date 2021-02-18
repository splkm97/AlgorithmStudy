#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
bool vis[10002];
int counts[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	queue<int> Q;
	std::unordered_map<int, vector<int>> belMap;
	std::unordered_map<int, vector<int>> visMap;
	vector<int> ans;
	int cntMax = 0;

	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;

		if (belMap.find(temp2) == belMap.end()) {
			vector<int> vec;
			vec.push_back(temp1);
			belMap.insert({ temp2, vec });
		}
		else {
			belMap[temp2].push_back(temp1);
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		vector<int> visVector;
		for (int j = 1; j <= n; j++) {
			vis[j] = false;
		}
		Q.push(i);
		vis[i] = true;
		visVector.push_back(i);
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			if (belMap.find(cur) == belMap.end())
				continue;
			for (int j = 0; j < belMap[cur].size(); j++) {
				int nx = belMap[cur][j];
				if (vis[nx]) {
					continue;
				}
				if (counts[nx] > 0) {
					cnt += counts[nx];
					for (auto item : visMap[nx]) {
						if (vis[item]) {
							cnt--;
						}
					}
					continue;
				}
				Q.push(nx);
				vis[nx] = true;
				visVector.push_back(nx);
				cnt++;
			}
		}
		counts[i] = cnt;
		visMap[i] = visVector;
	}

	for (int i = 1; i <= n; i++) {
		cntMax = max(cntMax, counts[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (cntMax == counts[i]) {
			ans.push_back(i);
		}
	}
	for (auto item : ans) {
		cout << item << " ";
	}
	cout << "\n";

	return 0;
}