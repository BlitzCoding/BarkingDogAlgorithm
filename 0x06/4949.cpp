#include <iostream>
#include <stack>
using namespace std;

int main()
{
    while(true)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        string str;
        bool flag = true;
        getline(cin, str);
        if (str == ".")
            break;
        stack<char> stk;
        for (auto it : str)
        {
            if (it == '(' || it == '[')
                stk.push(it);
            else if (it == ')')
            {
                if (stk.empty() || stk.top() != '(')
                {
                    cout << "no\n";
                    flag = false;
                    break; 
                }
                else if (stk.top() == '(')
                {
                    stk.pop();
                }
            }
            else if (it == ']')
            {
                if (stk.empty() || stk.top() != '[')
                {
                    cout << "no\n";
                    flag = false;
                    break; 
                }
                else if (stk.top() == '[')
                {
                    stk.pop();
                }
            }
        }
        if (stk.empty() && flag)
            cout << "yes\n";
    }
}