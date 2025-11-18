// Write a program for binary search tree (BST) having functions for the following
// operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of 

#include<iostream>
#include<queue>
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

void insert(node* &root, int key)
{
    if(!root) 
    {
        root=new node(key);
        return;
    }
    node* curr=root;
    while (true)
    {
        if(curr->data>key) 
        {
            if(!curr->left) 
            {
                curr->left=new node(key);
                break;
            }
            else curr=curr->left;
        }
        else if(curr->data<key)
        {
            if(!curr->right) 
            {
                curr->right=new node(key);
                break;
            }
            else curr=curr->right;
        }
        else
        {
            cout<<"duplicate  element"<<endl;
        }
    }
}
node* helper(node* root)
{
    if(!root->left) return root->right;
    if(!root->right) return root->left;

    node* rightChild=root->right;
    node* leftChildRightEnd=root->left;
    while(leftChildRightEnd->right) leftChildRightEnd=leftChildRightEnd->right;
    leftChildRightEnd->right=rightChild;
    return root->left;
}

node* deleteNode(node* root, int key)
{
    node* rootcopy=root;
    if(!root) return NULL;
    if(root->data==key) rootcopy= helper(root);

    while(root)
    {
        if(root->data>key)
        {
            if(root->left&&root->left->data==key) 
            {
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
        }
        else if(root->data<key)
        {
            if(root->right&&root->right->data==key) 
            {
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
                
    }
    return rootcopy;
}

void inorder(node* root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int maxDepth(node* root)
{
    if(!root) return 0;
    int count =1;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        count++;
    }
    return count;

}
int minDepth(node* root)
{
    if(!root) return 0;
    int count =1;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            if(!q.front()->left&&!q.front()->right) return count;
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        count++;
    }
    return count;

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
