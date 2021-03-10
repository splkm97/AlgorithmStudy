#include <bits/stdc++.h>

using namespace std;

bool vis[100002];
bool teamed[100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tests;
	cin >> tests;

	for (int tc = 1; tc <= tests; tc++) {
		int num; cin >> num;
		vector<int> vec;
		for (int i = 0; i < num; i++) {
			int temp;
			cin >> temp;
			vec.push_back(temp-1);
			teamed[i] = false;
		}
		int remains = vec.size();
		
		for (int i = 0; i < vec.size(); i++) {
			if (teamed[i])
				continue;
			for (int i = 0; i < vec.size(); i++) {
				vis[i] = 0;
			}
			bool isLoop = false;
			queue<int> st;
			
			int start = i;
			st.push(vec[i]);
			vis[i] = true;
			while (!st.empty()) {
				int index = st.front();
				st.pop();
				if (start == vec[index]) {
					int cnt = 0;
					vis[index] = true;
					for (int j = 0; j < vec.size(); j++) {
						if (vis[j]) {
							cnt++;
							teamed[j] = true;
						}
					}
					remains -= cnt;
					break;
				}
				if (vis[index])
					continue;
				vis[index] = true;
				st.push(vec[index]);
			}
		}

		cout << remains << "\n";
	}

	return 0;
}