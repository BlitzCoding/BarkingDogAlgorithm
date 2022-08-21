#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> stk;
    int res = 0;
    while (n--)
    {
        int num;
        cin >> num;
        if (num == 0)
            stk.pop();
        else
            stk.push(num);
    }
    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }
    cout << res << endl;
}