#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0 ,1 ,0};
int dy[4] = {0, 1, 0, -1};
int ny, nx, y, x, N;
int house, num;
int board[26][26];
int visited[26][26];

void dfs(int y, int x)
{
    visited[y][x] = 1;
    num++;
    for (int i = 0; i < 4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue ;
        if (visited[ny][nx] || board[ny][nx] == 0)
            continue ;
        dfs(ny, nx);
    }
}

int main()
{
    cin >> N;
    vector<int> house_num;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &board[i][j]);
        }
    }


    fill(&visited[0][0], &visited[N-1][N], 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && board[i][j] != 0)
            {
                num = 0;
                dfs(i, j);
                if (num)
                {
                    house_num.push_back(num);
                    house++;
                }
            }
        }
    }
    sort(house_num.begin(), house_num.end());
    printf("%d\n", house);
    for (auto i : house_num)
        printf("%d\n", i);
}
