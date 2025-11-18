// Write program using functions for binary tree traversals: Pre-order, In-order and Post
// order using recursive approach.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int n)
    {
        data=n;
        left=NULL;
        right=NULL;
    }

    

};
void preorder(node* rootptr)
    {
        if(rootptr==NULL) return;
        else 
        {
            cout<<rootptr->data<<" ";
            preorder(rootptr->left);
            preorder(rootptr->right);
        }
    }

void inorder(node* rootptr)
{
    if(rootptr==NULL) return;
    else
    {
        inorder(rootptr->left);
        cout<<rootptr->data<<" ";
        inorder(rootptr->right);
    }
}    
void postorder(node* rootptr)
{
    if(rootptr==NULL) return;
    else
    {
        postorder(rootptr->left);
        postorder(rootptr->right);
        cout<<rootptr->data<<" ";
    }
}
void levelorder(node* rootptr)
{
    queue<node*> q;
    q.push(rootptr);
    vector<vector<int>> ans;
    
    while(!q.empty())
    {
        vector<int> level;
        int size=q.size();
        for (int i=0;i<size;i++)
        {
        if(q.front()->left!=NULL)        q.push(q.front()->left);
        if(q.front()->right!=NULL)        q.push(q.front()->right);
        level.push_back(q.front()->data);
        q.pop();
        }

        ans.push_back(level);


    }
    for(int i=0;i<ans.size();i++)
    {
        for( int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }
}  

// void levelorder1(node* root)
// {
//     queue<node*> q;
//     vector<vector<int>> ans;
//     q.push(root);
//     while(!q.empty())
//     {
//         vector<int> tempans;
//         int size=q.size();
//         for(int i=0;i<size;i++)
//         {
//             if(q.front()->left) q.push(q.front()->left);
//             if(q.front()->right) q.push(q.front()->right);
//             tempans.push_back(q.front()->data);
//             q.pop();
//         }  
//         ans.push_back(tempans);      
//     }
//     for(int i=0;i<ans.size();i++)
//     {
//         for(int j=0;j<ans[i].size();j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->right->left=new node(7);
    root ->right->right=new node(8);
    root ->right->right->left=new node(9);
    root ->right->right->right=new node(10);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    levelorder(root);

    return 0;
}
