#include<iostream>
#include<cmath>

using namespace std;


double root(double x)//二分查找求平方根
{
    double l = 0;
    double u = x;
    double m = (l + u) / 2;
    while(true)
    {
        double err = m * m-x;
        if(abs(err)<1e-6)
            return m;
            else if(err>0)
                u = m;
                else
                {
                    l = m;
                }
                m = (l + u) / 2;
    }
}
int binary_search(int* a, int n, int x)//二分查找一个不重复的数字，在递增数列中
{
    int l = 0;
    int u = n - 1;
    int m = (l + u) >> 1;
    while(l<=u)
    {
        if(a[m]==x)
            return m;
            else if(a[m]<x)
                l = m+1;//这里的加一减一都是必须的，这是闭区间的二分查找
                
                else
                {
                    u = m-1;
                }
                m = (l + u) >> 1;
                cout << m << endl;
    }
    
}
int main()
{
    cout << root(2) << endl;
    system("pause");
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binary_search(a, 11, 9) << endl;
    system("pause");
    return 0;
}