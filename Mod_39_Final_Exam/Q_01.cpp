/*
Question # 01
    Traverse the following binary tree using the inorder, preorder,  
    postorder, and level order techniques. Level each of the nodes of 
    the tree. Also, find the height of the tree. 
*/

#include<bits/stdc++.h>
using namespace std;

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
int Height(treeNode* root);
void CurrentLevel(treeNode* root, int level);
void LevelOrderFromLeaf(treeNode* root);
void LevelOrderFromLeaf(treeNode* root);
void InOrder(treeNode *root); // Inorder Traversal sort the BST
void PreOrder(treeNode *root);
void PostOrder(treeNode *root);

// Insertion Node in tree.
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

// Height of Tree
int Height(treeNode* root){
    if (root == NULL) return 0;
    else {
        int LHeight = Height(root->leftChild);
        int RHeight = Height(root->rightChild);

        if (LHeight > RHeight) 
            return(LHeight + 1);
        else 
            return(RHeight + 1);
    }
}

// Level each Node of Tree
void CurrentLevel(treeNode* root, int level){
    if (root == NULL)
        return;
    if (level == 1)
        cout<<root->data << " ";
    else if (level > 1){
       CurrentLevel(root->leftChild, level-1);
       CurrentLevel(root->rightChild, level-1);
    }
}

// Print Level from Root Nodes
void LevelOrderFromRoot(treeNode* root){
    int h = Height(root);
    for(int i=1; i<=h; i++){
        CurrentLevel(root, i);
    }
    cout<<endl;
    for(int i=1; i<=h; i++){
        cout<<"\tLevel # "<<i<<":"<<" ";
        CurrentLevel(root, i);
        cout<<endl;
    }
}

// Print Level from Leaf Nodes
void LevelOrderFromLeaf(treeNode* root){
    int h = Height(root);
    for (int i=h; i>=1; i--)
        CurrentLevel(root, i);
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
    int arr[11] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 35};
    
    treeNode *root = NULL;
    
    for(int i=0; i<11; i++){ 
        root = insertionBST(root, arr[i]);
    }

    cout<<endl<<"Height of the tree:"<<" "<<Height(root)<<endl;
    
    cout<<endl<<"Level-Order Traverssal: "<<endl<<"\t";
    LevelOrderFromRoot(root);

    cout<<endl<<"IN-Order Traversal:"<<endl<<"\t";
    InOrder(root);
    
    cout<<endl<<"PRE-Order Traversal:"<<endl<<"\t";
    PreOrder(root);
   
    cout<<endl<<"POST-Otrder Traversal:"<<endl<<"\t";
    PostOrder(root);
}

/*

11
15 11 26 8 12 20 30 6 9 14 35

# # # Binary Tree: BST Formation

Structure followed by [B]inary [S]earch [T]ree - BST.
LowerBound - Middle - UpperBound

                       15
                        |
                -----------------
               /                 \
              /                   \
             /                     \
            11                     26
           /\                      / \
          /  \                    /   \
         /    \                  /     \
        8      12              20      30
       /\       \                        \                   
      /  \       \                        \
     /    \       \                        \
    6      9       14                      35
    

Inorder Trraversal = Left - Root - Right
Inorder Trraversal Gives you a Sorted Number Only From BST.

*/