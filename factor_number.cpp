#include<iostream>
#include<cmath>
using namespace std;
//求因子个数，而不是质因子个数
int count_factor(int n)
{
    int count=0;
    int sq=sqrt(n);
    int r;
    for(int i=1;i<=sq;i++)
    {
        if(n%i==0)
        {
            r=n/i;
            if(r==i)
            {
                count+=1;
            }
            else{
                count+=2;
            }
        }
    }
}

int main()
{
    int a[100];
    for(int i=1;i<100;i++)
        a[i]=count_factor(i);
    return 0;
}