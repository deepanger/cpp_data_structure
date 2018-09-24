#include<iostream>
using namespace std;

int main()
{
    int a[101];
    for (int i = 0; i < 100;i++)
        a[i] = i;
    a[100] = 20;//重复数字是10

    //一共有101个数，假设无序排列，范围是0-99，但是有一个数出现了2次，其他都是1次，找出出现2次的数
    //这里是用异或的方法实现的，既然其他数只出现了一次，那么就再异或一次，变成0，出现了2次变成3次
    //另外一个方法是加起来减去0-99的和，可能会溢出，不好
    int res = 0;
    for (int i = 0; i < 100;i++)
        res = res ^ i;
    for (int i = 0; i < 101;i++)
        res ^= a[i];
    cout << res;
    return 0;
}
