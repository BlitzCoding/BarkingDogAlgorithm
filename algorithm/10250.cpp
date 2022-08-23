#include <iostream>

using namespace std;

int main()
{
	int H, W, N, testcase;
	int floor, room;
	cin >> testcase;
	while (testcase--)
	{
		cin >> H >> W >> N;
		floor = N % H;
		room = N / H;
		if (floor > 0)
			room++;
		else
			floor = H;
		cout<< floor * 100 + room <<'\n';
	}
}