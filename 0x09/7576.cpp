#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int ny, nx, n, m, y, x, res;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[1001][1001];
int board[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int> > q;
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    while(q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (visited[ny][nx] || board[ny][nx] != 0)
                continue;
            board[ny][nx] = board[y][x] + 1;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    int res = 0;
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = max(res, board[i][j]);
            if (board[i][j] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << res - 1 << '\n';

}