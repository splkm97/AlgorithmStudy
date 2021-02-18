#include <bits/stdc++.h>

using namespace std;

vector<int> sizelist;
int cnt = 0;

void findMoo(int num, int index) {
	if (index == 0) {
		if (num == 0) {
			cout << "m\n";
		}
		else {
			cout << "o\n";
		}
		return;
	}
	if (num < sizelist[index]) {
		findMoo(num, index - 1);
	}
	else if (num < ((2 * sizelist[index]) + index + 3)) {
		num -= sizelist[index];
		if (num == 0) {
			cout << "m\n";
		}
		else {
			cout << "o\n";
		}
	}
	else {
		num -= sizelist[index] + index + 3;
		findMoo(num, index - 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int number; cin >> number;

	sizelist.push_back(3);
	while (sizelist.back() <= number) {
		int temp;
		temp = 2 * sizelist.back() + 4 + cnt;
		sizelist.push_back(temp);
		cnt++;
	}

	findMoo(number-1, cnt);

	return 0;
}