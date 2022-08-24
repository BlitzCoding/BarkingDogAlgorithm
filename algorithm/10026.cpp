#include <iostream>
#include <queue>

using namespace std;

int N;
int ny, nx, y, x;
int dx[4] = {0, -1, 0 ,1};
int dy[4] = {1, 0, -1, 0};
int normal, disable;
char board[101][101];
bool nor[101][101];

void dfs(int y, int x)
{
	nor[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (nor[ny][nx] || board[ny][nx] != board[y][x])
			continue;
		dfs(ny, nx);
	}
}

int main()
{
	cin >> N;
	queue<pair<int, int> > q;

	for (int i = 0 ; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!nor[i][j])
			{
				dfs(i , j);
				normal++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 'R')
				board[i][j] = 'G';
		}
	}

	fill(&nor[0][0], &nor[N -1][N], 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!nor[i][j])
			{
				dfs(i , j);
				disable++;
			}
		}
	}
	
	std::cout << normal << ' ' << disable << '\n';

}