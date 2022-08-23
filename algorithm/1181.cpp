#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main()
{
	int num;
	vector<string> v;
	cin >> num;
	while(num--)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto i : v)
		cout << i << '\n';
}