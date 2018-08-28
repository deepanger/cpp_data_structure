#include<iostream>
#include<string>

using namespace std;

void reverse(string& s, int first, int last)//通过一个翻转函数可以做很多事，比如翻转部分和翻转句子
{
    char temp;
    while(first<last)
    {
        temp = s[first];
        s[first] = s[last];
        s[last] = temp;
        first++;
        last--;
    }
}
int main()
{
    string s = "12345";
    // reverse(s, 0, s.size() - 1);
    // cout << s << endl;


    //把字符串的前半部分和后半部分交换
    reverse(s, 0, 2);
    reverse(s, 3, s.size() - 1);
    reverse(s, 0, s.size() - 1);
    cout << s << endl;
    system("pause");

    //也可以以单词为单位翻转整个句子,这是个谷歌面试题
    //This is a paragraph for test
    //处理后： test for paragraph a is This


    string s1 = "This is a paragraph for test";
    reverse(s1, 0, s1.size() - 1);
    int first = 0;
    int last = 0;
    for (int i = 0; i <= s1.size();i++)
    {
        if(s1[i]==' '||s1[i]=='\0')
        {
            last = i - 1;
            reverse(s1, first, last);
            first = i + 1;
        }
        
    }

    cout << s1 << endl;
    system("pause");

    return 0;
}