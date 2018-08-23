#include<iostream>
#include <stack>
#include <string>

using namespace std;

void intBaseConventor(int num, int b, string& numstr)
{
    string digitChar = "0123456789ABCDEF";
    numstr = "";
    stack<char> S;
    if(num<0)
    {
        numstr += '-';
        num = -num;
    }
    do
    {
        S.push(digitChar[num % b]);
        num = num / b;
    } while (num != 0);
    while(!S.empty())
    {
        numstr += S.top();
        S.pop();
    }
}
int main()
{
    int num;
    cin >> num;
    string out = "";
    intBaseConventor(num, 2, out);
    cout << out <<endl;
    system("pause");
}