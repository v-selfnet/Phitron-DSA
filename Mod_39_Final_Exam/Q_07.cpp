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
void InOrder(treeNode *root); // Inorder Traversal sort the BST


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
        cout<<root->data <<" ";
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
}

// Inorder = Left - Root - Right
void InOrder(treeNode *root){ 
    if(root != NULL){
        InOrder(root->leftChild);
        cout<<root->data<<" ";
        InOrder(root->rightChild);
    } 
}

int main(){
    treeNode *root = NULL;
    
    /* 
        Who is the Inorder Successer of 30? 
        33 || 34 ?
        After delete Parent Node 30 it replace with the Node 33. 
        Where it should replace with 34.
        int arr[16] = {30, 28, 60, 40, 65, 38, 50, 62, 66, 35, 39, 61, 63, 33, 36, 34};
    */
    
    int arr[13] = {7, 5, 12, 3, 6, 9, 15, 1, 4, 8, 10, 13, 17};
    for(int i=0; i<13; i++){
        root = insertionBST(root, arr[i]);
    }
    
    cout<<"# # # # # Before Operation # # # # #";
    cout<<endl<<"Height of the tree:"<<" "<<Height(root);
    cout<<endl<<"Level-Order Traverssal:"<<endl<<"\t";
    LevelOrderFromRoot(root);
    cout<<endl<<"IN-Order Traversal:"<<endl<<"\t";
    InOrder(root);

    cout<<endl<<endl<<"# # # # # # # # # #"<<endl;
    cout<<"Press 1: Insertion"<<endl
        <<"Press 2: Deletion"<<endl
        <<"Press 0: Exit"<<endl;
    cout<<"# # # # # # # # # #"<<endl<<endl;

    int ins, del, choice;
    cout<<"Next Choice: ";
    cin>>choice;
    while(choice != 0){
        switch(choice){
            case 1:
                cout<<"Enter Value for Insertion: ";
                cin>>ins;
                root = insertionBST(root, ins);
                break;
            case 2:
                cout<<"Enter Value for Deletion: ";
                cin>>del;
                root = deletionBST(root, del);
                break;
            default:
                break;
        }
        cout<<"Next Choice: ";
        cin>>choice;
    }

    cout<<endl<<"# # # # # After Operation # # # # #";
    cout<<endl<<"Height of the tree:"<<" "<<Height(root);
    cout<<endl<<"Level-Order Traverssal:"<<endl<<"\t";
    LevelOrderFromRoot(root);
    cout<<endl<<"IN-Order Traversal:"<<endl<<"\t";
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


int arr[16] = {30, 28, 60, 40, 65, 38, 50, 62, 66, 35, 39, 61, 63, 33, 36, 34};
        Who is the Inorder Successer of 30? 
        33 || 34 ?
        After delete Parent Node 30 it replace with the Node 33. 
        Where it should replace with 34.

                               30
                               /\
                              /  \
                             /    \
                            /      \
                           /        \
                          /          \
                         28          60
                                     /\
                                    /  \
                                   /    \
                                  /      \
                                 /        \
                                40        65
                               /\          /\
                              /  \        /  \
                             /    \      /    \
                            38    50    62    66   
                           /\                  /\
                          /  \                /  \
                         /    \              /    \
                        35    39            61    63
                       /\
                      /  \
                     /    \
                    33     36
                     \
                      \
                       \
                       34  
*/