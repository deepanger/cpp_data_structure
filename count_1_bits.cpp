#include<iostream>

using namespace std;

int count(int n)
{
    int count = 0;
    while(n!=0)
    {
        n = n & (n - 1);//可以用这办法数出来二进制数字中有多少个1，还是有点用处的
        count++;
    }
    return count;
}
int main()
{
    cout << count(7) << endl;
    getchar();
    return 0;
}