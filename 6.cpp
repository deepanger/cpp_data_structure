#include<bits/stdc++.h>
using namespace std;
//链表的各种操作
struct ListNode
{
    int value;
    ListNode *next_point;
};

ListNode *CreateListNode(int value)
{
    ListNode *pNode = new ListNode();
    pNode->value = value;
    pNode->next_point = nullptr;

    return pNode;
}
//往一个链表末端添加一个点
void addPoint_for_list(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode;
    pNew->value = value;
    pNew->next_point=nullptr;

    if(*pHead==nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* node = *pHead;
        while(node->next_point!=nullptr)
            node = node->next_point;
        node->next_point = pNew;
    }
}

//删除值为某个数的结点，传入的参数仍为2重指针，因为可能要修改头指针（第一个结点就删）

void removenode(ListNode** pHead, int value)
{
    if (pHead == nullptr || *pHead == nullptr)
        return;
    ListNode *pToBeDel = nullptr;
    if ((*pHead)->value == value)
    {
        pToBeDel = *pHead;
        *pHead = (*pHead)->next_point;
    }
    else
    {
        ListNode *p = *pHead;
        while (p->next_point != nullptr && p->next_point->value != value)
            p = p->next_point;
        if (p->next_point != nullptr && p->next_point->value == value)
        {
            cout << "deleting" << endl;
            pToBeDel = p->next_point;
            p->next_point = p->next_point->next_point;
        }
    }
    if (pToBeDel != nullptr)
    {
        delete pToBeDel;
    }
}

ListNode *reverse_list(ListNode *head)
{
    if (head->next_point == nullptr)
        return head;
    else
    {
        ListNode *p = head->next_point;
        ListNode *before = nullptr;
        ListNode *next = nullptr;
        while (p != nullptr)
        {
            next = p->next_point;
            p->next_point = before;
            before = p;
            p = next;
        }
        head->next_point = before;
    }
}

int main()
{
    ListNode start;
    ListNode *p = nullptr;
    // (*p).value = 0;
    // (*p).next_point = nullptr;
    ListNode **p0 = &p;
    
    for (int i = 0; i < 10; i++)
        addPoint_for_list(p0, i);
    ListNode *p1 = *p0;
    while(p1!=nullptr)
    {
        cout << p1->value << endl;
        p1 = p1->next_point;
    }
    removenode(p0, 3);
    cout << "remove" << endl;
    p = (*p0);
    while (p != nullptr)
    {
        cout << p->value << endl;
        p = p->next_point;
    }
    system("pause");
    return 0;
}

