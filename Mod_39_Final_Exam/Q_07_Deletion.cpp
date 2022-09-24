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
treeNode *InOrderSucc(treeNode *root);
treeNode *deletionBST(treeNode *root, int value);
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

// Find Inorder Successer
treeNode *InOrderSucc(treeNode *root){
    treeNode *curr = root;
    while(curr->leftChild != NULL){
        curr = curr->leftChild;
    }
    return curr;
}

// Deletion BST
treeNode *deletionBST(treeNode *root, int value){
    if(value < root->data){
        root->leftChild = deletionBST(root->leftChild, value);
    }
    else if(value > root->data){
        root->rightChild = deletionBST(root->rightChild, value);
    }
    else{
        // Implementation of case 3
        if(root->leftChild == NULL){
            // Case 1 | Case 2
            treeNode *tmp = root->rightChild;
            delete (root);
            return tmp;
        }
        else if(root->rightChild == NULL){
            // Case 2
            treeNode *tmp = root->leftChild;
            delete (root);
            return tmp;
        }
        else{
            treeNode *tmp = InOrderSucc(root->rightChild);
            root->data = tmp->data;
            root->rightChild = deletionBST(root->rightChild, tmp->data);
        }
    }
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
    // int arr[11] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 35};
    // int arr[11] = {10, 40, 20, 8, 99, 16, 15, 17, 11, 14, 1};
    int arr[16] = {30, 28, 60, 40, 65, 38, 50, 62, 66, 35, 39, 61, 63, 33, 36, 34};
    
    treeNode *root = NULL;
    
    for(int i=0; i<16; i++){ 
        root = insertionBST(root, arr[i]);
    }

    cout<<endl<<"Height of the tree:"<<" "<<Height(root)<<endl;
    
    cout<<endl<<"Level-Order Traverssal: "<<endl<<"\t";
    LevelOrderFromRoot(root);

    cout<<endl<<"IN-Order Traversal:"<<endl<<"\t";
    InOrder(root);
    
    // cout<<endl<<"PRE-Order Traversal:"<<endl<<"\t";
    // PreOrder(root);
   
    // cout<<endl<<"POST-Otrder Traversal:"<<endl<<"\t";
    // PostOrder(root);

    root = deletionBST(root, arr[0]);
    cout<<endl<<"Level-Order After Delete: "<<endl<<"\t";
    LevelOrderFromRoot(root);
    cout<<endl<<"IN-Order After Delete:"<<endl<<"\t";
    InOrder(root);
}

/*

11
15 11 26 8 12 20 30 6 9 14 35

11
10 40 20 8 99 16 15 17 11 14 1

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