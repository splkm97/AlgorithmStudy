#include "bits/stdc++.h"

using namespace std;

int K;
int num[15];
int picked[15];
bool visited[15];

void printRecur(int cur, int depth) {
    if (depth == 6) {
        for (int i = 0 ;i < 6 ; i ++) {
            cout << picked[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = cur ; i < K ; i ++) {
        if (visited[i])
            continue;
        picked[depth] = num[i];
        visited[i] = true;
        printRecur(i+1, depth + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (1) {
        cin >> K;
        if (K == 0)
            break;
        for (int i = 0; i < K; i++) {
            cin >> num[i];
        }

        printRecur(0, 0);
        cout << "\n";
    }


    return 0;
}
