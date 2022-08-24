#include <iostream>
#include <queue>

using namespace std;
int walk[100001];

int main()
{
	int N, K;

	cin >> N >> K;

	walk[N] = 1;
	queue<int> q;
	q.push(N);
	while (q.size())
	{
		int x = q.front();
		q.pop();
		if (x == K)
		{
			cout << walk[x] - 1 << '\n';
			return 0;
		}
		if (x + 1 <= 100000 && !walk[x + 1])
		{
			walk[x + 1] = walk[x] + 1;
			q.push(x + 1);
		}

		if (x - 1 >= 0 && !walk[x - 1])
		{
			walk[x - 1] = walk[x] + 1;
			q.push(x - 1);
		}

		if (x * 2 <= 100000 && !walk[x * 2])
		{
			walk[x * 2] = walk[x] + 1;
			q.push(x * 2);
		}
		
	}
}