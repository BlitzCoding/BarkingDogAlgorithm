#include <iostream>

using namespace std;

int N, M;

int flag[10] = {0, };
int arr[10] = {0, };

void func (int idx, int num)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = num; i <= N; i++)
	{
		if (!flag[i])
		{
			arr[idx] = i;
			flag[i] = 1;
			func(idx + 1, i + 1);
			flag[i] = 0;
		}
	}
}

int main()
{
	cin >> N >> M;
	func(0, 1);
}