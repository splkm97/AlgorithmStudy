#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

bool board[7][7];
bool curCase[7][7];
bool vis[7][7];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int ans;
int sx, sy;

bool chkAdj() {
    for (int i = 0 ;i < 5;i ++) {
        for (int j = 0 ;j < 5 ;j ++) {
            vis[i][j] = false;
        }
    }
    queue<pair<int, int> > q;
    q.push({sx, sy});
    int cnt = 0;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for (int dir = 0 ; dir < 4 ; dir ++) {
            int nx = now.X + dx[dir];
            int ny = now.Y + dy[dir];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                continue;
            if (!curCase[nx][ny] || vis[nx][ny])
                continue;
            q.push({nx, ny});
            vis[nx][ny] = true;
            cnt ++;
        }
    }
    return (cnt == 7);
}

void printCurCase() {
    for (int i = 0 ;i < 5;i ++) {
        for (int j = 0;j < 5; j++) {
            if (curCase[i][j])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

void find(int cur, int depth, int ycnt) {
    if (ycnt >= 4) {
        return;
    }
    if (depth == 7) {
        if (chkAdj())
            ans++;
        return;
    }
    for (int idx = cur ;idx < 25 ; idx ++) {
        int i = idx / 5;
        int j = idx % 5;
        curCase[i][j] = true;
        if (depth == 0) {
            sx = i;
            sy = j;
        }
        if (board[i][j])
            find(idx + 1, depth+1, ycnt);
        else
            find(idx + 1, depth+1, ycnt+1);
        curCase[i][j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    for (int i = 0;i < 5; i ++) {
        cin >> line;
        for (int j = 0 ;j < 5 ;j ++) {
            if (line[j] == 'S')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }

    find(0,0,0);
    cout << ans;

    return 0;
}
