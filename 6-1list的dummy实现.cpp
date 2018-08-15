#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    ListNode *next_point;
};

ListNode *inser_after(ListNode *curr, int value)
{
    ListNode *p = new ListNode;
    p->value = value;

    p->next_point = curr->next_point;
    curr->next_point = p;

    return p;
}

void insert_at_tail(ListNode *head, int value)
{
    ListNode *p0;
    p0 = head;
    while (p0->next_point != nullptr)
        p0 = p0->next_point;
    ListNode *temp = inser_after(p0, value);
}

void print_list(ListNode *head)
{
    for (auto p = head->next_point; p != nullptr; p = p->next_point)
        cout << p->value << endl;
}

void remove_node(ListNode *head, int value)
{
    ListNode *p = head;
    while (p->next_point != nullptr)
    {
        if (p->next_point->value == value)
        {
            ListNode *tobeDel = p->next_point;
            p->next_point = p->next_point->next_point;
            delete tobeDel;
        }

        else
        {
            p = p->next_point;
        }
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
    ListNode *head = new ListNode; //只要有一个head，value始终为0，就可以维护一个链表了
    head->value = NULL;
    head->next_point = nullptr; //这就是一个dummy head了，始终不修改head的value

    ListNode *p = head;
    for (int i = 0; i < 10; i++)
        p = inser_after(p, i);
    print_list(head);
    remove_node(head, 3);
    print_list(head);
    system("pause");
    return 0;
}