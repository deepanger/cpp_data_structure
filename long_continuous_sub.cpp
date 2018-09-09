#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 100
int table[256];
// memset(table, -1, sizeof(int) * 256);
void dp(int *d, int n, char *a)
{
    for (int i = 0; i < 256;i++)
        table[i] = -1;
    d[0] = 1;
    table[a[0]] = 0;
    for (int i = 1; i < n;i++)
    {
        if(table[a[i]]==-1)
        {
            table[a[i]] = i;
            d[i] = d[i - 1] + 1;
        }
        else
        {
            int last_pos = table[a[i]];
            if(last_pos<(i-d[i-1]))
            {
                d[i] = d[i - 1] + 1;
            }
            else
            {
                d[i] = i - table[a[i]];
            }
        }
            
    }
}
int d[MAX];
int main()
{
    int n;
    cin >> n;
    char a[MAX];
    scanf("%s", a);
    dp(d, n, a);
    int *max = max_element(d, d + MAX);
    cout << *max;
    return 0;
}