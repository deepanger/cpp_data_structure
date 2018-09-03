#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define MAX 100001
int position[MAX];
int h[MAX];
//一系列有高度的多米诺骨牌，计算推倒某一个之后倒掉的总数
//输入
//4
//16 5
//20 5
//10 10
//18 2
//
//输出 3 1 4 1
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> position[i] >> h[i];
    map<int, int >m;
    for (int i = 0; i < n; i++)
        m.insert(pair<int, int>(position[i], h[i]));

    int* d=new int[n];
    d[n-1] = 1;

    vector<int> p_order, h_order;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        p_order.push_back(it->first);
        h_order.push_back(it->second);
    }
        

    
    for (int i = n - 2; i>=0;  i--)
    {
        int max = 0;
        int reach = 1;
        int count = 0;//这里如果用while控制循环的话，因为有两个条件，会很麻烦，不知道到底是啥
        for (; i + reach < n; reach++)
        {
            if ((p_order[i] + h_order[i] - 1 >= p_order[i + reach]))
            {
                count++;
                max = (d[i + count] + count) > max ? (d[i + count] + count) : max;
            }
            else break;
        }
        if (count == 0)
        {
            d[i] = 1;
        }
        else
        {
            d[i] = max ;
        }
    }
    for (int i = 0; i < n; i++)
        cout << d[find(p_order.begin(),p_order.end(),position[i])-p_order.begin()] << ' ';

    return 0;
}