#include <iostream>

using namespace std;

long long A, B, C;

long long algo(long long B)
{
	if (B == 0) return 1;
	if (B == 1) return A % C;
	long long tmp = algo(B / 2) % C;
	if (B % 2 == 0) return tmp * tmp % C;
	return ((tmp * tmp % C) * (A % C)) % C;
}

int main()
{
	cin >> A >> B >> C;

	cout << algo(B);
}