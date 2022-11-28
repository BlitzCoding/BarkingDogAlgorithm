#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct s_node
{
    int n;          // 해당 노드가 가지고 있는 키의 개수;
    int *K;         // 해당 노드가 가지고 있는 키들을 담고있는 배열;
    struct s_node **P;        // 해당 노드가 가지고 있는 포인터들(자식 노드)을 담고있는 배열
}   t_node;

stack<t_node *> stk;
bool found, finished;
t_node *newNode;

t_node *getBTNode(int m)
{
    t_node *node = new t_node;
    node->n = 0;
    node->K = new int[m - 1];
    node->P = new t_node*[m];
    for (int i = 0; i < m; i++)
    {
        node->P[i] = NULL;
    }
    return node;
}

bool searchPath(t_node *T, int m, int key)
{
    t_node *x = T;
    int     i;

    do
    {
        i = 1;
        while (i <= x->n && key > x->K[i])
            i++;
        if ((i <= x->n) && (key == x->K[i]))
            return true;
        stk.push(x);
    } while ((x = x->P[i - 1]) != NULL);
    return false;
}

void insertKey(t_node *T, int m, t_node *x, t_node *y, int newKey)
{
    int i = x->n;
    while (i >= 1 && newKey < x->K[i])
    {
        x->K[i + 1] = x->K[i];
        x->P[i + 1] = x->P[i];
        i--;
    }

    x->K[i] = newKey;
    x->P[i] = y;
    x->n = x->n + 1;
}

void insertBT(t_node **T, int m, int newKey)
{
    if (*T == NULL)
    {
        *T = getBTNode(m);
        (*T)->K[0] = newKey;
        (*T)->n = 1;
        return ;
    }
    
    bool found = searchPath(*T, m, newKey);
    if (found)
        return ;
    
    bool finished = false;
    t_node *x = stk.top();
    t_node *y = NULL;
}

int main()
{
    t_node *node = NULL;
    char cmd;
    int num;
    ifstream file;
    file.open("BT-input.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            if (file.eof())
                break;
            file >> cmd >> num;
            if (cmd == 'i')
                insertBT(&node, 3, num);
            // else if (cmd == 'd')
                // deleteBT(&node, 3, num);
        }
    }
    // 테스트를 위한 표준입력
    else
    {
        while (1)
        {
            cin >> cmd >> num;
            if (cmd == 'i')
                insertBT(&node, 3, num);
            // else if (cmd == 'd')
                // deleteBT(&node, 3, num);
        }
    }
    file.close();
}