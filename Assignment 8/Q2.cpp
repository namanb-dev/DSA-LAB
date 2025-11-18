// mplement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST 

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

node* searchRecc(node*root, int key)
{
    if(root==NULL) return NULL;
    if(root->data==key) return root;
    if(key>root->data) return searchRecc(root->right,key);
    if(key<root->data) return searchRecc(root->left,key);
}

node* searchIter(node* root, int key)
{
    while(root!=NULL&&root->data!=key)
    {
        if(key<root->data) root=root->left;
        else root=root->right;
    }
    return root;
}

int max(node*root)
{
    while(root!=NULL&&root->right!=NULL)
    {
        root=root->right;
    }
    cout<< root->data<<endl;
    
}
void min(node*root)
{
    while(root!=NULL&&root->left!=NULL)
    {
        root=root->left;
    }
    cout<< root->data<<endl;;
    
}

int inorderSuc(node*root, int key)
{
    int suc=-1;
    while(root)
    {
        if(root->data>key)
        {
            suc=root->data;
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return suc;
}

int inorderPre(node* root,int key)
{
    int pre=-1;
    while(root)
    {
        if(root->data<key)
        {
            pre=root->data;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return pre;
}


int main()
{
     node* root = new node(10);

    
    root->left = new node(5);
    root->right = new node(15);

    
    root->left->left = new node(3);
    root->left->right = new node(7);
    root->right->left = new node(12);
    root->right->right = new node(18);

    
    root->left->left->left = new node(1);
    root->left->left->right = new node(4);
    root->left->right->left = new node(6);
    root->left->right->right = new node(8);
    root->right->left->left = new node(11);
    root->right->left->right = new node(13);
    root->right->right->left = new node(17);
    root->right->right->right = new node(20);

    
    node* a1=searchRecc(root,2);
    cout<<(a1?a1->data:-1)<<endl;
    node* a2=searchIter(root,2);
    cout<<(a2?a2->data:-1)<<endl;
    
    max(root);
    min(root);

    cout<<"pred is: "<<inorderPre(root,12)<<endl;
    cout<<"succ is: "<<inorderSuc(root,12)<<endl;

}


/*
my bst

              10
           /      \
         5          15
       /   \       /   \
     3      7     12    18
    / \    / \   / \   / \
   1  4   6  8  11 13 17 20

*/
