#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


//简单选择排序
void simple_selection_sort(int *a, int start, int end)//这里是左开右闭区间，和STL中的迭代器相似
{
    int temp;
    int i, j, max_num_so_far;
    for (i = start; i < end;i++)
    {
        max_num_so_far = i;
        for (j = i + 1; j < end;j++)
            if (a[j] < a[max_num_so_far]) //这里的小技巧是不直接放到第i个位置去，而是记录最小位置的编号
                max_num_so_far = j;
        if (max_num_so_far != i)
        {
            temp = a[i];
            a[i] = a[max_num_so_far];
            a[max_num_so_far] = temp;
        }
    }
}
//直接插入排序
void straight_insertion_sort(int *a, int start, int end)
{
    int temp;
    int i, j;

    for (i = start + 1; i < end;i++)
    {
        temp = a[i];
        for (j = i - 1; temp < a[j] && j >= start;j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp; //这里要么是j已经=start-1了，要么是a[j]<temp了，所以要来个j+1;
    }
}

//为了折半查找排序准备的折半插入函数，左闭右闭区间,这个函数会溢出
void binary_insert(int *a, int value, int left, int right)
{
    int mid;
    int end = right;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (value < a[mid])
            right = mid - 1;
        else
        {
            left = mid + 1;
        }
    }
    for (int i = end + 1; i > left; i--)
        a[i] = a[i - 1];
    a[left] = value;
}
//折半查找排序，把直接插入排序中的插入部分改成二分查找插入，就是折半查找排序了
void binary_insertion_sort(int *a, int start, int end)
{
    int temp;
    int i;
    for (i = start + 1; i < end;i++)
    {
        temp = a[i];
        binary_insert(a, temp, start, i - 1);
    }
}
//冒泡排序，这个创新之处在于多了一个exchange
void bubble_sort(int *a, int start, int end)
{
    bool exchange;
    int temp;
    for (int i = start; i < end - 1;i++)
    {
        exchange = false;
        for (int j = end - 1; j > i;j--)
        {
            if(a[j-1]>a[j])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                exchange = true;
            }
        }
        if(exchange==false)
            return;
    }
}

//用于快速排序的分区函数
int partition(int *a, int start, int end)
{
    int i = start;
    int j = end - 1;
    const int pivot = a[i];//始终选择第一个数作为轴，然后后面正好让大数放在a[i]的位置，真是巧妙啊，这个代码
    while(i<j)
    {
        while(i<j&&a[j]>=pivot)
            j--;
        a[i] = a[j];
        while(i<j&&a[i]<=pivot)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}

void quick_sort(int *a, int start, int end)
{
    if(start<end-1)
    {
        const int pivot = partition(a, start, end);
        quick_sort(a, start, pivot);
        quick_sort(a, pivot + 1, end);
        //必须这么写，不能写成quick(a, start, pivot-1) quick(a, pivot,end)
        //因为这是左闭右开区间，而pivot本身是不需要排序的，所以应该放在开区间
    }
}


//这是一个非递归版本的快拍，用stack实现
// void quick_sort_iteration(int *a, int start, int end);
// {

// }

//归并排序的二路归并
void merge(int *a, int *t, int start, int mid, int end)//t为辅助数组，这个很特殊了,mid为分界点
{
    int i, j, k;
    for (i = 0; i < end;i++)
        t[i] = a[i];
    // ij是检测指针，k是存放指针
    for (i = start, j = mid, k = start; i < mid && j < end;k++)//两个区间排序的时候也是左闭右开区间
    {
        if(t[i]<t[j])
        {
            a[k] = t[i++];
        }
        
        else
        {
            a[k] = t[j++];
        }
    }
    while(i<mid) //如果有剩下的没进去，全都放进去
        a[k++] = t[i++];
    while(j<end)
        a[k++] = t[j++];
}
// 归并排序本体
void merge_sort(int *a, int *t, int start, int end)
{
    if(start<end-1)
    {
        int mid = (start + end) / 2;//这个得到的mid是中间值或者中间俩的后一个（总数偶数）时
        merge_sort(a, t, start, mid);
        merge_sort(a, t, mid, end);
        merge(a, t, start, mid, end);
    }
}

//STL 中的堆排序，看起来还挺简单的
void STL_heap_sort(vector<int> &a)
{
    make_heap(a.begin(), a.end());
    sort_heap(a.begin(), a.end());
}
//堆排序，有点复杂，用书上的版本比较好
void heap_sort();

int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1,0};
    int *t;
    t = (int*)malloc(sizeof(int) * 10);
    merge_sort(a, t, 0, 9);
    quick_sort(a, 0, 9);
    bubble_sort(a, 0, 9);
    binary_insertion_sort(a, 0, 9);
    straight_insertion_sort(a, 0, 9);
    simple_selection_sort(a, 0, 9);
    return 0;
}