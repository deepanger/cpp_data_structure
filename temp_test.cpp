#include<bits/stdc++.h>
using namespace std;
int add(int a, int b)
    {
        return a + b;
    }
int main()
{
/*1 函数指针 */
    // int (*pf)(int, int);
    // pf = add;
    // // auto pf = add;
    // cout << pf(1, 2) << endl;
    // cout << (*pf)(1, 2) << endl;
    //函数指针可以作为参数传到函数中，写法有两种形式
    //int add_a(int a,int b, int(*pf)(int,int)) or
    //int add_b(int , ,int b, int pf(int,int))

/*2 new和delete的用法 */
    // int *pi = new int;
    // *pi = 1;
    // cout << *pi << endl;
    // int *pin = new int[10];//申请了10个int的空间
    // memset(pin, 0, sizeof(int) * 10);
    // for (auto i = 0; i < 10;i++)
    // {
    //     cout << *pin << endl;
    //     pin++;
    // }
    // //要释放空间，要成对使用
    // delete pi;
    // delete[] pin;
/*3 relloc后面跟的是总大小，而不是要扩充的大小 */
    // int *p = (int *)malloc(sizeof(int) * 10);
    // memset(p, 0, 10);
    // p = (int *)realloc(p,sizeof(int)*12);
    int a[10];
    scanf("%d", &a[0]);
    cout << a[0] << endl;
    system("pause");
    return 0;
}