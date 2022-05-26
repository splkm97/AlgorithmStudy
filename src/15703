#include "bits/stdc++.h"

using namespace std;

int N;

int dices[1002];
vector<vector<int>> towers;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0 ; i < N ; i ++) {
        cin >> dices[i];
    }

    sort(dices, dices + N);
    vector<int> firstTower;
    firstTower.push_back(dices[0]);
    towers.push_back(firstTower);

    int cnt = 0;

    for (int i = 1; i < N ;i ++) {
        cnt = 1;
        for (int j = 0 ; j < towers.size() ; j ++) {
            if (towers[j].size() <= dices[i]) {
                // 기존 탑에 끼울 수 있는 경우
                towers[j].push_back(dices[i]);
                break;
            }
            else
                cnt ++;
        }
        if (cnt == towers.size() + 1)
        {
            // 새 탑 생성하는 경우
            vector<int> newone;
            newone.push_back(dices[i]);
            towers.push_back(newone);
        }
    }
    cout << towers.size();

    return 0;
}
