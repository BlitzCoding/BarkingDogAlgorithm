#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int R, C, res, ny, nx, y, x;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int jin[1001][1001];
int fire[1001][1001];
char board[1001][1001];

int main()
{
	cin >> R >> C;
	queue<pair<int, int> > ji;
	queue<pair<int, int> > fi;
	for (int i = 0 ; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'J')
			{
				ji.push({i, j});
				jin[i][j] = 1;
			}
			else if (board[i][j] == 'F')
			{
				fi.push({i, j});
				fire[i][j] = 1;
			}
		}
	}

	// 불 BFS
	while (fi.size())
	{
		y = fi.front().first;
		x = fi.front().second;
		fi.pop();
		for (int i = 0 ; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue;
			if (board[ny][nx] == '#' || fire[ny][nx])
				continue;
			fire[ny][nx] = fire[y][x] + 1;
			fi.push({ny, nx});
		}
	}

	while (ji.size())
	{
		y = ji.front().first;
		x = ji.front().second;
		ji.pop();
		for (int i = 0 ; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			{
				cout << jin[y][x] << '\n';
				return 0;
			}
			if (board[ny][nx] == '#' || jin[ny][nx])
				continue;
			if (jin[y][x] + 1 >= fire[ny][nx] && fire[ny][nx] != 0)
				continue;
			jin[ny][nx] = jin[y][x] + 1;
			ji.push({ny, nx});
		}
	}
	cout << "IMPOSSIBLE";
}
