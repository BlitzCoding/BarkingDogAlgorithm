#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int N, M;
char board[1001][1001];
int escape[1001][1001];
int fire[1001][1001];
int flag;
int testcase, ny, nx, y, x;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0 ,-1};

int main()
{
	cin >> testcase;
	for (int t = 0; t < testcase; t++)
	{
		queue< pair<int, int>> es;
		queue< pair<int, int>> fi;
		fill(&escape[0][0], &escape[1001][1001], 0);
		fill(&fire[0][0], &fire[1001][1001], 0);
		cin >> N >> M;
		flag = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '*')
				{
					fire[i][j] = 1;
					fi.push({i, j});
				}
				else if (board[i][j] == '@')
				{
					escape[i][j] = 1;
					es.push({i, j});
				}
			}
		}

		// fire
		while (fi.size())
		{
			tie(y, x) = fi.front();
			fi.pop();
			for (int i = 0; i < 4; i++)
			{
				ny = y + dy[i];
				nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= M || nx >= N)
					continue;
				if (fire[ny][nx] || board[ny][nx] == '#')
					continue;
				fire[ny][nx] = fire[y][x] + 1;
				fi.push({ny, nx});
			}
		}

		while (es.size())
		{
			tie(y, x) = es.front();
			es.pop();
			for (int i = 0; i < 4; i++)
			{
				ny = y + dy[i];
				nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= M || nx >= N)
				{
					cout << escape[y][x] << '\n';
					flag = 1;
					while (es.size())
						es.pop();
					break;
				}
				if (escape[ny][nx] || board[ny][nx] == '#' || board[ny][nx] == '*')
					continue;
				if (escape[y][x] + 1 >= fire[ny][nx] && fire[ny][nx] != 0)
					continue;
				escape[ny][nx] = escape[y][x] + 1;
				es.push({ny, nx});
			}
		}

		// for (int i = 0; i < M; i++)
		// {
		// 	for (int j = 0; j < N; j++)
		// 	{
		// 		cout << escape[i][j] << ' '; 
		// 	}
		// 	cout << '\n';
		// }

		if (flag)
			continue;
		else
			cout << "IMPOSSIBLE\n";

	}
}