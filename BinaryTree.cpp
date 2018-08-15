#include<iostream>
#include<queue>
using namespace std;

struct BTnode
{
    int data;
    BTnode *lchild;
    BTnode *rchild;
};

void pre_order(BTnode *root)
{
    if(root!=nullptr){
        cout << root->data << ' ';
    pre_order(root->lchild);
    pre_order(root->rchild);
    }
    
}

void in_order(BTnode *root)
{
    if(root!=nullptr)
    {
        in_order(root->lchild);
        cout << root->data << ' ';
        in_order(root->rchild);
    }
}

void post_order(BTnode *root)
{
    if(root!=nullptr)
    {
        post_order(root->lchild);
        post_order(root->rchild);
        cout << root->data << ' ';
    }
}

void level_order(BTnode *root)
{
    queue<BTnode *> Q;
    if(root!=nullptr)
        Q.push(root);
    while(!Q.empty())
    {
        cout << Q.front()->data << ' ';
        if(Q.front()->lchild!=nullptr)
            Q.push(Q.front()->lchild);
        if(Q.front()->lchild!=nullptr)
            Q.push(Q.front()->lchild);
        Q.pop();
    }
}
int main()
{
    return 0;
}