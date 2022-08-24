#include <iostream>

using namespace std;

int result[3];
int board[2200][2200];

bool check(int row, int col, int num)
{
	int tmp = board[row][col];
	for (int i = row; i < row + num; i++)
	{
		for (int j = col; j < col + num; j++)
		{
			if (tmp != board[i][j])
				return false;
		}
	}
	return true;
}

void func(int row, int col, int num)
{
	if (check(row, col, num))
		result[board[row][col]]++;
	else
	{
		int size = num / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				func(row + size * i, col + size * j, size);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			input++;
			board[i][j] = input;
		}
	}
	func(0, 0 , N);
	cout << result[0] << '\n' << result[1] << '\n' << result[2] << '\n';

}