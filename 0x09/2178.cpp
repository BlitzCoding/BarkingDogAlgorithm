#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[101][101];
int board[101][101];
int ny, nx, y, x;

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &board[i][j]);
        }
    }
    queue<pair<int, int> > q;
    visited[0][0] = 1;
    q.push({0, 0});
    while(q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (visited[ny][nx] || board[ny][nx] == 0)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    printf("%d", visited[n - 1][m - 1]); 
}