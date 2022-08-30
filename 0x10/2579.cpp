#include <iostream>

using namespace std;

int testcase;
int str[301];
int dp[301][3];

int main()
{
	int num;
	cin >> testcase;
	for (int i = 1; i <= testcase; i++)
	{
		cin >> str[i];
	}
	if (testcase == 1)
	{
		cout << str[1];
		return 0;
	}
	dp[1][1] = str[1];
	dp[1][2] = 0;
	dp[2][1] = str[2];
	dp[2][2] = str[1] + str[2];

	for (int i = 3; i <=testcase; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + str[i];
		dp[i][2] = dp[i-1][1] + str[i];

	}
	cout << max(dp[testcase][1], dp[testcase][2]);
}