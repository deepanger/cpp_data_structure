//求数组最大值
#define NI -10000000
int max_num(int *a, int n)
{
    int max = NI;
    for (int i = 0; i < n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    return max;
}

//求数组最小值
#define MI 0x3f3f3f3f
int min_num(int *a, int n)
{
    int min = MI;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}