#include <cstdio>
#include <iostream>
#include<cstring>
using namespace std;
struct coordinate
{
    int bfx, bfy; //上一步的位置
    int sum;
};
coordinate coor[5][5];

int max_num(int a, int b)
{
    return a < b ? b : a;
}
int main()
{
    int m = 3, n = 4;
    int mapp[4][4] = {3, 0, 0, 5, 2, 4, 7, 0, 5, 0, 1, 1, 0, 0, 0, 1}; //这是我的例子
    coor[0][0].bfx = 0;
    coor[0][0].bfy = 0;
    coor[0][0].sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != 0 && j != 0)
            {
                if (coor[i - 1][j].sum > coor[i][j - 1].sum)
                {
                    coor[i][j].sum = coor[i - 1][j].sum + mapp[i][j];
                    coor[i][j].bfx = i - 1;
                    coor[i][j].bfy = j;
                }
                else
                {
                    coor[i][j].sum = coor[i][j - 1].sum + mapp[i][j];
                    coor[i][j].bfx = i;
                    coor[i][j].bfy = j - 1;
                }
            }
            if (i == 0 && j >= 1)
            {
                coor[i][j].sum = coor[i][j - 1].sum + mapp[i][j];
                coor[i][j].bfx = i;
                coor[i][j].bfy = j - 1;
            }
            if (j == 0 && i >= 1)
            {
                coor[i][j].sum = coor[i - 1][j].sum + mapp[i][j];
                coor[i][j].bfx = i - 1;
                coor[i][j].bfy = j;
            }
        }
    }
    //print
    int tx, ty, ttx, tty;
    tx = ty = 3;
    while (tx != 0 || ty != 0) //为什么是||而不是&&    因为0||1=1，而0&&1=0 ，拿（1，0）坐标试下看就知道了-----以后实在不明白就是一生。。。
    {
        printf("(%d,%d)\n", tx, ty);
        ttx = tx;
        tty = ty;
        tx = coor[ttx][tty].bfx;
        ty = coor[ttx][tty].bfy;
    }
    printf("(0,0)\n");
    cout << coor[4][4].sum << endl;
    system("pause");



    //这部分开始才是我自己写的不计算中间路径的动态规划，说实话写的比他好一些
    //更可以用int A[MAX][MAX],max设定为一个很大的数，直接用就行，不考虑这些东西
    int *A = (int*)malloc(5 * 5 * sizeof(int));
    memset(A, 0, 5 * 5 * sizeof(int));
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4;j++)
            A[i * 5 + j] = max_num(A[(i-1)*5+j] + mapp[i-1][j-1], A[i*5+j-1] + mapp[i-1][j-1]);

    cout << A[25-1] << endl;
    system("pause");
    return 0;
}
