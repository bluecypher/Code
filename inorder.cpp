// Inorder traversal BST
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    node  *left, *right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
unordered_map<node*,int> cnt;
void inorder(node* t)
{
    stack<node* > s;
    s.push(t);
    while(!s.empty())
    {
        node* temp=s.top();
        if(temp==NULL)
        {
            s.pop();
            continue;
        }
        if(cnt[temp]==0){ s.push(temp->left);}
        else if(cnt[temp]==1){ cout<<temp->data<<" ";}
        else if(cnt[temp]==2){ s.push(temp->right);}
        else s.pop();
        cnt[temp]++;
    }

}


int main()
{
    node* t=new node(1);
    t->left=new node(2);
    t->right=new node(3);
    t->left->left=new node(4);
    inorder(t);
}
