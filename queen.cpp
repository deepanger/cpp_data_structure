#include <iostream>
#include <stack>
#include <string>

using namespace std;
int n = 8;
int total = 0;
int *c = new int(n);
//本身C的数据设计也是非常经典，c[i]==j的数值表示第i行上的皇后放在第j列
bool is_ok(int row)
{
    for (int j = 0; j != row;j++)
    {
        if(c[row]==c[j]||row-c[row]==j-c[j]||row+c[row]==j+c[j])
        //这句是判断是否成立的精髓
        //第一句判断是否在同一列
        //第二三判断斜线的两种情况，主对角线和副对角线
            return false;
    }
    return true;
}
void queen(int row)
{
    if(row==n)
        total++;
        else
        for(int col=0;col!=n;col++)
        {
            c[row] = col;
            if(is_ok(row))
                queen(row + 1);
        }
}
int main()
{
    queen(0);
    cout << total;
    system("pause");
    return 0;
}