#include <bits/stdc++.h>

using namespace std;

int north = 0, east = 2, west = 6;
deque<bool> geardeq[4];
bool link[3];

void calLink() {
	for (int i = 0; i < 3; i++) {
		if (geardeq[i][east] == geardeq[i+1][west]) {
			link[i] = false;
		}
		else {
			link[i] = true;
		}
	}
}

void spinGear(int num, int dir) {
	if (dir == 1) {
		int item = geardeq[num].back();
		geardeq[num].pop_back();
		geardeq[num].push_front(item);
	}
	else {
		int item = geardeq[num].front();
		geardeq[num].pop_front();
		geardeq[num].push_back(item);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	for (int i = 0; i < 4; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			if (temp.at(j) == '0')
			{
				geardeq[i].push_back(0);
			}
			else {
				geardeq[i].push_back(1);
			}
		}
	}

	int N;
	cin >> N;
	for (int tc = 1; tc <= N; tc++) {
		int num, dir;
		cin >> num >> dir;
		if (dir == -1) {
			dir = false;
		}
		num--;
		calLink();
		if (num == 0) {
			spinGear(0, dir);
			if (link[0]) {
				spinGear(1, !dir);
				if (link[1]) {
					spinGear(2, dir);
					if (link[2]) {
						spinGear(3, !dir);
					}
				}
			}
		}
		if (num == 1) {
			spinGear(1, dir);
			if (link[0]) {
				spinGear(0, !dir);
			}
			if (link[1]) {
				spinGear(2, !dir);
				if (link[2]) {
					spinGear(3, dir);
				}
			}
		}
		if (num == 2) {
			spinGear(2, dir);
			if (link[2]) {
				spinGear(3, !dir);
			}
			if (link[1]) {
				spinGear(1, !dir);
				if (link[0]) {
					spinGear(0, dir);
				}
			}
		}
		if (num == 3) {
			spinGear(3, dir);
			if (link[2]) {
				spinGear(2, !dir);
				if (link[1]) {
					spinGear(1, dir);
					if (link[0]) {
						spinGear(0, !dir);
					}
				}
			}
		}
	}
	int cur = 1;
	int score = 0;
	for (int i = 0; i < 4; i++) {
		if (geardeq[i][north]) {
			score += cur;
		}
		cur *= 2;
	}
	cout << score;

	return 0;
}