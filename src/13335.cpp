#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, W, L;
	cin >> N >> W >> L;
	queue<int> input;
	deque<pair<int, int> > onbridge;
	int weightSum = 0;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		input.push(temp);
	}

	int time = 1;
	int cur = input.front();
	weightSum += cur;
	input.pop();
	onbridge.push_back({ 0, cur });
	while (!onbridge.empty()) {
		int size = onbridge.size();
		for (int i = 0; i < size; i ++) {
			pair<int, int> item = onbridge.front();
			onbridge.pop_front();
			item.first++;
			if (item.first == W) {
				weightSum -= item.second;
			}
			else {
				onbridge.push_back(item);
			}
		}
		if (!input.empty()) {
			cur = input.front();
			if (weightSum + cur <= L) {
				input.pop();
				onbridge.push_back({ 0, cur });
				weightSum += cur;
			}
		}
		time++;
	}
	cout << time;

	return 0;
}