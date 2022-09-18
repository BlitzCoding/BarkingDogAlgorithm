#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ny, nx, y, x;
int arr[101][101];
int visited[101][101];
int island[101][101];
int N;

void print(int arr[101][101])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void dfs(int y, int x, int num)
{
	visited[y][x] = 1;
	island[ny][nx] = num;

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		if (visited[ny][nx] || arr[ny][nx] == 0)
			continue;
		
		dfs(ny, nx, num);
	}
}

int main()
{
	cin >> N;
	fill(&visited[101][101], &visited[101][100], 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	int island_num = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] && !visited[i][j])
			{
				dfs(i, j, island_num--);
			}
		}
	}

	print(island);
}