#include<iostream>
#include<queue>
#include<cmath>
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
            Q.push(Q.front()->rchild);
        Q.pop();
    }
}

BTnode* simple_tree()
{
    int h;
    cin >> h;
    if (h<0)
        return nullptr;
    int N = static_cast<int>(pow(2.0, h + 1) - 1);

    BTnode *nodes = new BTnode[N];
    int start = 0;
    int gap = 2;
    for (int i = start; i < N;i+=gap)
    {
        nodes[i].data = i;
        nodes[i].lchild = nullptr;
        nodes[i].rchild = nullptr;
    }
    for (int L = 0; L < h;L++)
    {
        start = 2 * start + 1;
        gap *= 2;
        for (int i = start; i < N;i+=gap)
        {
            nodes[i].data = i;
            nodes[i].lchild = nodes + i - gap / 4;
            nodes[i].rchild = nodes + i + gap / 4;
        }
    }

    BTnode *root = nodes + N / 2;
    pre_order(root);
    cout << endl;
    in_order(root);
    cout << endl;
    level_order(root);

    return root;
}

size_t leaf_count(BTnode *root)
{
    if(root==nullptr)
        return 0;
    else if((root->lchild==nullptr)&&(root->rchild==nullptr)) //如果无儿无女就是叶子节点
        return 1;
    else
    {
        return leaf_count(root->lchild) + leaf_count(root->rchild);
    }
}
int main()
{
    BTnode* root = simple_tree();
    cout << leaf_count(root) << endl;
    system("pause");
    return 0;
}