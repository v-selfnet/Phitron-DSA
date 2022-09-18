#include<bits/stdc++.h>
using namespace std;

// Linked List
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL; 
        right = NULL;
    }
};
// Inorder = Left - Root - Right
void inOrder(Node *root){ 
    if(root == NULL) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
}

// Preorder = Root - Left - Right
void preOrder(Node *root){ 
    if(root == NULL) return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);   
}
// Postorder = Left - Right - Root
void postOrder(Node *root){ 
    if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);   
        cout<<root->data<<" ";
}


int main(){
    Node *root = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    Node *d = new Node(5);
    Node *e = new Node(6);
    Node *f = new Node(7);
    Node *g = new Node(8);

    root->left = a;
    root->right = b;

    a->left = c;

    b->left = d;
    b->right = e;

    c->right = f;

    e->right = g;

    cout<<"Inorder:\t";
    inOrder(root);
    cout<<"\nPreorder:\t";
    preOrder(root);
    cout<<"\nPostorder:\t";
    postOrder(root);
    
}

/*
Inorder = Left - Root - Right       4 7 2 1 <-|-> 5 3 6 8
Preorder = Root - Left - Right      1 4 7 2 <-|-> 5 3 6 8
Postorder = Left - Right - Root     7 4 2 <-|-> 5 8 6 3 1         
# # # Binary Tree # # #
                    1
                   / \
                  /   \ 
                 /     \
                2       3
               /       / \
              /       /   \
             4       5     6
              \             \
               \             \                      
                7             8

*/