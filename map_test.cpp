#include<iostream>
#include<map>
#include<string>

using namespace std;

void print_map(const map<int,string> &m)
{
    for (auto it = m.cbegin(); it != m.cend();it++)
        cout << it->first << "    " << it->second << endl;
}
int main()
{
    map<int, string> m;
    m[0] = "0";
    m[1] = "1";
    print_map(m);

    return 0;
}