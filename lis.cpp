#include<stdio.h>
#include<iostream>
#define MAXN 1001//最大数组长度
//最长递增子序列的问题，只需要一个数组就可以表示，每个位置表示以a[i]为结尾的序列的最大长度
//那么只要从之前的序列中找到比a[i]小的集合，然后从中找到最大的，加一就可以了
int N;
int a[MAXN];
int d[MAXN];
void dp()
{
    int i, j;
    d[0] = 0;//这里有个细节是，两个数组都是从1开始的，而不是从0，这是为了更符合人的节奏
    for (j = 1; j <= N;j++)
    {
        int max = 0;
        for (i = 1; i < j;i++)
            if(a[i]<a[j]&&max<d[i])
                max = d[i];
        d[j] = max + 1;
    }
}

int main()
{
    int i, max=0;
    scanf("%d", &N);
    for (i = 1; i <= N;i++)
        scanf("%d", &a[i]);
    dp();
    for (i = 1; i <= N;i++)
    if(d[i]>max)
        max = d[i];
    printf("%d\n", max);
    getchar();
    system("pause");
    return 0;
}