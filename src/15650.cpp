#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int k, int cur) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = cur + 1; i <= N; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1, i);
			isused[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0, 0);

	return 0;
}