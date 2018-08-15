#include<bits/stdc++.h>
using namespace std;
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;
    if(matrix!=nullptr&&rows>0&&columns>0)
    {
        int row = 0;
        int col = columns-1;
        while(row<rows&&col<<columns)
        {
            if (matrix[row*columns+col]==number)
            {
                found = true;
                break;
            }
            else if(matrix[row*columns+col]>number)
                --col;
            
            else
            {
                ++row;
            }
        }
    }
    return found;
}
int main()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    bool found = false;
    found = Find((int*)matrix, 4, 4, 7);
    if (found)
    cout << "found" << endl;
    return 0;
}