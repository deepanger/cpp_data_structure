//返回不重复集合的子集，用二进制枚举
#include<stdio.h>
#include<math.h>
void sub_print(int *a, int start, int end)
{
    int n = end - start;
    for (int i = 0; i<pow(2,n);i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(i&(1<<j))
            printf("%d",a[j]);
        }
        printf("\n");
    }
    
}

int main()
{
    
    int a[] = {1, 2, 3};
    sub_print(a, 0, 3);
    return 0;
}