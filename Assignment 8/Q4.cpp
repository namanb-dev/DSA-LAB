// Write a program to determine whether a given binary tree is a BST or not.

#include<iostream>
#include <climits>
using namespace std;
class node
{
    public:
    node* left;
    node* right;
    int data;
    node(int n)
    {
        data=n;
        right=NULL;
        left=NULL;
    }
};

bool isValid(node *root, long max, long min)
{
    if(!root) return true;
    if(root->data<=min||root->data>=max) return false;
    return isValid(root->left,root->data,min)&&isValid(root->right,max,root->data);
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
    cout<<isValid(root,LONG_MAX,LONG_MIN)?"Is BST":"Not bst"<<endl;

    
    
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
