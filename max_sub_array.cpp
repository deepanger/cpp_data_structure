#include<iostream>

using namespace std;
//最大子数组和，给定一个数组，输出最大连续子数组的和
#define NI -100;
int max(int x, int y)
{
    if(x>=y)
        return x;
        
        else
        {
            return y;
        }
        
}

int max_array_v1(int *array, int length)//这是最笨的n3的解法，我都想不到这么笨的解法
{
    int sum, maxsofar = NI;
    int i, j, k;
    for (i = 0; i < length; i++)
        for (j = i; j < length; j++)
        {
            sum = 0;
            for (k = i; k <= j; k++)
            {
                sum += array[k];
                maxsofar = max(maxsofar, sum);
            }
        }
    return maxsofar;
}

int max_array_v2_1(int *array, int length)//这个还好一点，首先想到的遍历方法
{
    int sum, maxsofar = NI;
    int i, j;
    for (i = 0; i < length; i++)
    {
        sum = 0;
        for (j = i; j < length; j++)
        {
            sum += array[j];
            maxsofar = max(maxsofar, sum);
        }
    }
    return maxsofar;
}
int max_array_v3(int *array, int l, int u)//分治法的较好解法
{
    int i, m;
    int lmax, rmax, sum;
    lmax = rmax = NI;
    if (l > u)
        return 0;
    else if (l == u)
        return array[l];
    m = (l + u) / 2;
    sum = 0;
    for (i = m; i >= 1; i--)
    {
        sum += array[i];
        lmax = max(sum, lmax);
    }
    sum = 0;
    for (i = m + 1; i <= u; i++)
    {
        sum += array[i];
        rmax = max(sum, rmax);
    }
    return max(lmax + rmax, max(max_array_v3(array, l, m), max_array_v3(array, m + 1, u)));
}

int max_array_v4(int *array, int length)//动态规划的思想
//扫描至array[i]时，可能的最长子向量有两种情况：要么在前i-1个元素中，要么以i结尾
{
    int i;
    int maxsofar = NI;
    int maxendinghere = 0;
    for (i = 0; i < length; i++)
    {
        maxendinghere = max(maxendinghere + array[i], array[i]);
        //分析：maxendinghere必须包含array[i]
        //当maxendinghere>0且array[i]>0，maxendinghere更新为两者和
        //当maxendinghere>0且array[i]<0，maxendinghere更新为两者和
        //当maxendinghere<0且array[i]<0，maxendinghere更新为array[i]
        //当maxendinghere<0且array[i]>0，maxendinghere更新为array[i]
        maxsofar = max(maxsofar, maxendinghere);
    }
    return maxsofar;
}
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, -1};
    cout << max_array_v2_1(a,7) << endl;
    cout << max_array_v3(a, 0, 6) << endl;
    cout << max_array_v4(a, 7) << endl;
    system("pause");
    return 0;
}