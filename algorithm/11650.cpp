#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	int a, b;
	while (n--)
	{
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end(), cmp);
	for (auto it : v)
	{
		cout << it.first << " " << it.second << '\n';
	}
}