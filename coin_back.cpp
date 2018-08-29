#include <iostream>

using namespace std;
#define INF 0x3f3f3f3f
// 假设有几种硬币，如1、3、5，并且数量无限。请找出能够组成某个数目的找零所使用最少的硬币数
// sum[k] = min(sum[k - coin[0]], sum[k - coin[1]], ...) + 1

struct state
{
    int nCoin; //使用硬币数量
    //以下两个成员是为了便于构造出求解过程的展示
    int lastSum; //上一个状态
    int addCoin; //从上一个状态达到当前状态所用的硬币种类
} ;

int coin[] = {1, 2, 5};

int coin_back(int total, int n)
{
    state *sum = (state*)malloc(sizeof(state) * (total + 1));
    for (int i = 0; i <= total; i++)
        sum[i].nCoin = INF;
    sum[0].nCoin = 0;
    sum[0].lastSum = 0;

    for (int i = 1; i <= total; i++)
        for (int j = 0; j < n; j++)
            if (i - coin[j] >= 0 && sum[i - coin[j]].nCoin + 1 < sum[i].nCoin) //这里本质上还是那个min表达式，为了保存状态所以来了个循环
            //为了前面的方便，其实也可以i从数字5开始，前面的自己填好就行
            {
                sum[i].nCoin = sum[i - coin[j]].nCoin + 1;
                sum[i].lastSum = j;
                sum[i].addCoin = coin[j];
            }

    if (sum[total].nCoin == INF)
    {
        printf("can't make change.\n");
        return 0;
    }
    else
        cout << sum[total].nCoin << endl;
    return sum[total].nCoin;

}

int main()
{
    coin_back(17, 3);
    
    system("pause");
    return 0;
}