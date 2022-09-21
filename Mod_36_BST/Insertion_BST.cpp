#include<bits/stdc++.h>
using namespace std;

/*
Parent > Left Child
Parent < Right Child

LC < P < RC

LC < P
RC > P

Inorder result should be a sorted numbers.
Inorder Traversal = Left - Root - Right
*/

class treeNode{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int value){
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

treeNode *insertionBST(treeNode *root, int value);
void InOrder(treeNode *root); // Inorder Traversal sort the BST
void PreOrder(treeNode *root);
void PostOrder(treeNode *root);

// BST Binary Search Tree Insertion [lb-mid-ub formula]
treeNode *insertionBST(treeNode *root, int value){
    treeNode *newNode = new treeNode(value);
    // Case # 1: When root NULL
    if(root==NULL){
        root = newNode;
        return root;
    }
    // Case # 2: When value less than root->data [Left Child]
    if(value < root->data){
        root->leftChild = insertionBST(root->leftChild, value);
    }
    // Case # 3: When value greter than root->data [Rght Child]
    else if(value > root->data){
        root->rightChild = insertionBST(root->rightChild, value);
    }
    delete (newNode); // memory leak occured, if do not delete/free the memory 
    return root;
}

// Inorder = Left - Root - Right
void InOrder(treeNode *root){ 
    if(root != NULL){
        InOrder(root->leftChild);
        cout<<root->data<<" ";
        InOrder(root->rightChild);
    } 
}

// Preorder = Root - Left - Right
void PreOrder(treeNode *root){ 
    if(root != NULL){
        cout<<root->data<<" ";
        PreOrder(root->leftChild);
        PreOrder(root->rightChild);
    } 
}

// Postorder = Left - Right - Root
void PostOrder(treeNode *root){ 
    if(root != NULL){
        PostOrder(root->leftChild);
        PostOrder(root->rightChild);
        cout<<root->data<<" ";
    } 
}

int main(){
    int n;
    cin>>n;
    treeNode *root = NULL;
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        root = insertionBST(root, value);
    }
    cout<<endl<<"Sort BST with Inorder Traversal:"<<endl;
    InOrder(root);
    
}

/*

9
11 5 9 43 34 1 2 7 21

# # # Binary Tree:

Structure followed by Binary Search Format.
LowerBound - Middle - UpperBound

                      11
                      / \
                     /   \
                    /     \
                   /       \ 
                  /         \
                 /           \
                5            43
               / \           /
              /   \         /
             /     \       /
            1       9    43                    
             \     /     /
              \   /     /
               2 7    21
    

Inorder Trraversal = Left - Root - Right
Gives you a Sorted Number.

*/