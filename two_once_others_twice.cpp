#include<stdio.h>
//数组中，只有两个数出现一次，剩下都出现两次，找出出现一次的数
//这是利用了异或运算的规律，x^x^y=y
#define MAX 20 //数组最大长度
int res[2] = {-1, -1};
int a[MAX], b[MAX];

int find_one(int *a, int n)
{
    int res = 0;
    for (int i = 0; i < n;i++)
    {
        res = res^a[i];
    }
    return res;
}
void find_once(int *a, int n)//数组中有n个数
{
    int xor_res = 0;
    for (int i = 0; i < n;i++)
        xor_res = xor_res^a[i];
    int pos = 0;
    while(((1<<pos)&xor_res)!=1)
        pos++;
    int a_index = 0, b_index = 0;
    for (int i = 0; i < n;i++)
    {
        if(a[i]&(1<<pos))
        {
            a[a_index++] = a[i];
        }
        else
        {
            b[b_index++] = a[i];
        }
    }
    //现在已经分到两个组了，可以开始查了
    res[0] = find_one(a, a_index);
    res[1] = find_one(b, b_index);
}

int main()
{
    int a[] = {0, 0, 1, 1, 2, 2, 3, 4, 5, 5, 6, 6};
    find_once(a, 8);
    return 0;
}