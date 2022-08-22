#include <utility>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, ny, nx;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[501][501];
int board[501][501];
int res, mx_res, tmp;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
            {
                res++;
                q.push({i, j});
                tmp = 0;
                while(q.size())
                {
                    tmp++;
                    int cur_x = q.front().second;
                    int cur_y = q.front().first;
                    q.pop();
                    visited[i][j] = 1;
                    for (int i = 0; i < 4; i++)
                    {
                        ny = cur_y + dy[i];
                        nx = cur_x + dx[i];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                            continue;
                        if (visited[ny][nx] || board[ny][nx] != 1)
                            continue;
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
                mx_res = max(mx_res, tmp);
            }
        }
    }

    cout << res << '\n' << mx_res << '\n';
}