#include<iostream>
#include<queue>
#include<string>
#include<iomanip>
using namespace std;

void ChiaHsienTriangle(int n)
{
    int width = 3;
    queue<int> Q;
    Q.push(1);
    for (int i = 0; i < n+1;i++)
    {
        for (int j = 0; j < n - i;j++)
            cout << string(width, ' ');
        int prev = 0;
        for (int j = 0; j < i + 1;j++)
        {
            cout << setw(width) << Q.front() << string(width, ' ');
            Q.push(prev + Q.front());
            prev = Q.front();
            Q.pop();
        }
        Q.push(1);
        cout << endl;
    }
    
}
int main()
{
    ChiaHsienTriangle(10);
    system("pause");
    return 0;
}