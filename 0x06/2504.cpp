#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    bool start = false;
    stack<char> stk;
    int tmp = 1;
    int res = 0;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            tmp *= 2;
            stk.push(str[i]);
        }
    }
    if (!stk.empty())
        cout << "error stack" << '\n';
    else
        cout << res << '\n';
}