#include <bits/stdc++.h>
using namespace std;

bool board[102][102];
vector<int> prevDir;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int x, y, d, g;

void printBoard() {
    cout << "==================================\n";
    for (int i = 0 ; i < 100 ; i ++) {
        for (int j = 0 ;j < 100; j ++) {
            if (board[i][j])
                cout << "x";
            else
                cout << " ";
        }
        cout << "\n";
    }
    cout << "==================================\n";
}

void makeCurve() {
    int depth = prevDir.size();
    for (int i = depth - 1 ; i >= 0 ; i -- ) {
        int nd = (prevDir[i] + 1) % 4;
        x = x + dx[nd];
        y = y + dy[nd];
        board[x][y] = true;
        prevDir.push_back(nd);
    }
}

int cntSquare() {
    int cnt = 0;
    for (int i = 0 ;i < 99 ;i ++) {
        for (int j = 0 ;j < 99 ; j ++) {
            if (board[i][j] && board[i+1][j+1] && board[i+1][j] && board[i][j+1]) {
                cnt ++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int tc = 0 ; tc < n ; tc ++) {
        prevDir.clear();
        cin >> x >> y >> d >> g;
        board[x][y] = true;
        x = x + dx[d];
        y = y + dy[d];
        board[x][y] = true;
        prevDir.push_back(d);
        for (int i = 0 ; i < g ; i ++) {
            makeCurve();
        }
    }
    int cnt = cntSquare();
    cout << cnt;
    return 0;
}
