#include<cstring>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool hasPathCore(const char* matrix, int rows, int cols, int row ,int col,
                 const char* str, int& pathLength, bool *visit)
{
    if(str[pathLength]=='\0')
        return true;
    bool hasPath=false;
    if(row>=0&&col>=0&&
       row<rows&&col<cols&&
       matrix[row*cols+col]==str[pathLength]&&
       !visit[row*cols+col]
       )
    {
            pathLength++;
            visit[row * cols + col] = true;
        
    hasPath = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visit) ||
                  hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visit) ||
                  hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visit) ||
                  hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visit);
    if (!hasPath)//如果再r,c点不成功，或者在r,c点的邻居也不成功，那我们就抹除这一步的痕迹
                //而且这个是找到一个就可以了，所以找到一个之后不用清除visit的痕迹，如果要找到多个的话，就要清除了
    {
            pathLength--;
            visit[row * cols + col] = false;
    }
    }
    return hasPath;
}
bool hasPath(char *matrix, int rows, int cols, char* str)
{
    if(matrix==nullptr||rows<1||cols<1||str==nullptr)
        return false;
    bool *visit = (bool*)malloc(rows * cols * sizeof(bool));
    memset(visit, 0, sizeof(bool) * rows * cols);

    int pathLength = 0;
    for (int row = 0; row < rows;row++)
    {
        for (int col = 0; col < cols;col++)
            if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visit))
            {
                return true;
            }
    }
    return false;
}


int main()
{
    char matrix[] = {'a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h'};
    char str[] = "bfce";
    char str0[] = "abfb";
    cout << hasPath(matrix, 3,4,str0) << endl;
    return 0;
}