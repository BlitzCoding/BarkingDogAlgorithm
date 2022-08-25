#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int ny, nx, y, x;
int testcase, I, s_row, s_col, e_row, e_col;
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int board[301][301];

int main()
{
	cin >> testcase;

	while(testcase--)
	{
		fill(&board[0][0], &board[300][300], 0);
		queue<pair <int, int> > q;
		cin >> I >> s_row >> s_col >> e_row >> e_col;

		q.push({s_row, s_col});
		board[s_row][s_col] = 1;
		while (q.size())
		{
			tie(y, x) = q.front();
			q.pop();
			if (y == e_row && x == e_col)
			{
				cout << board[y][x] - 1 << '\n';
				break; 
			}
			for (int i = 0 ; i < 8; i++)
			{
				ny = y + dy[i];
				nx = x + dx[i];

				if (ny < 0 || ny >= I || nx < 0 || nx >= I)
					continue;
				if (board[ny][nx])
					continue;
				board[ny][nx] = board[y][x] + 1;
				q.push({ny, nx});
			}
		}


	}
}