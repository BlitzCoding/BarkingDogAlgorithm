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

t_node *splitNode(t_node *T, int m, t_node *x, t_node *y, int &newKey)
{
    t_node *tmpNode = x;
    insertKey(T, m, tmpNode, y, newKey);

    int centerKey = (tmpNode->n / 2);
    newKey = centerKey;

    x->n = 0;
    int i = 1;
    while (tmpNode->K[i] < centerKey)
    {
        x->K[i] = tmpNode->K[i];
        x->P[i - 1] = tmpNode->P[i - 1];
        i++;
        x->n = x->n + 1;
    }
    x->P[i - 1] = tmpNode->P[i - 1];

    t_node *newNode = getBTNode(m);
    i++;
    while (i <= tmpNode->n)
    {
        newNode->K[i] = tmpNode->K[i];
        newNode->P[i - 1] = tmpNode->P[i - 1];
        i++;
        newNode->n = newNode->n + 1;
    }
    newNode->P[i - 1] = tmpNode->P[i - 1];
    return newNode;
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
    stk.pop();
    t_node *y = NULL;

    do
    {
        if (x->n < m - 1)
        {
            insertKey(*T, m, x, y, newKey);
            finished = true;
        }
        else
        {
            y = splitNode(*T, m, x, y, newKey);
            if (!stk.empty())
            {
                x = stk.top();
                stk.pop();
            }
            else
            {
                *T = getBTNode(m);
                (*T)->K[1] = newKey;
                (*T)->P[0] = x;
                (*T)->P[1] = y;
                finished = true;
            }
        } 
    } while (!finished);
}

void inorderBT(t_node *T)
{
	if (T == NULL)
        return ;
    int i;
	for (i = 0; i < T->n; i++)
    {
		inorderBT(T->P[i]);
		cout << T->K[i] << ' ';
	}
	inorderBT(T->P[i]);
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
            {
                insertBT(&node, 3, num);
                inorderBT(node);
                cout << '\n';
            }
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
            {
                insertBT(&node, 3, num);
                inorderBT(node);
                cout << '\n';
            }
            // else if (cmd == 'd')
                // deleteBT(&node, 3, num);
        }
    }
    file.close();
}
