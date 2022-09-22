#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    Node *leftChild;
    Node *rightChild;
    Node(int value){
        data = value;
        leftChild = NULL; 
        rightChild = NULL;
    }
};

// Inorder = Left - Root - Right
void InOrder(Node *root){ 
    if(root != NULL){
        InOrder(root->leftChild);
        cout<<root->data<<" ";
        InOrder(root->rightChild);
    } 
}

// Preorder: Root - Left - Right
void PreOrder(Node *root){
    if(root != NULL){
        cout<<root->data<<" ";
        PreOrder(root->leftChild);
        PreOrder(root->rightChild);
    }
}

// Postorder = Left - Right - Root
void PostOrder(Node *root){ 
    if(root != NULL){
        PostOrder(root->leftChild);
        PostOrder(root->rightChild);
        cout<<root->data<<" ";
    } 
}

// Height of Tree
int Height(Node* root){
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
void CurrentLevel(Node* root, int level){
    // cout<<level<<endl;
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
       CurrentLevel(root->leftChild, level-1);
       CurrentLevel(root->rightChild, level-1);
    //    cout<<root->data<<level<<" ";
    }
}

// Print Level from Root Nodes
void LevelOrderFromRoot(Node* root){
    int h = Height(root);
    for(int i=1; i<=h; i++){
        cout<<"\tLevel # "<<i<<":"<<" ";
        CurrentLevel(root, i);
        cout<<endl;
    }
}
int main(){
    Node *root = new Node('A');

    root->leftChild = new Node('B');
    root->leftChild->leftChild = new Node('D');
    root->leftChild->rightChild = new Node('E');
    root->leftChild->rightChild->rightChild = new Node('F');

    root->rightChild = new Node('C');
    root->rightChild->rightChild = new Node('G');
    
    cout<<endl<<"Nodes are each Level: "<<endl;
    LevelOrderFromRoot(root);
    
    cout<<endl<<"IN-Order Traversal:"<<endl<<"\t";
    InOrder(root);

    cout<<endl<<"PRE-Order Traversal:"<<endl<<"\t";
    PreOrder(root);

    cout<<endl<<"POST-Order Traversal:"<<endl<<"\t";
    PostOrder(root);
}

/*

# # # Binary Tree:
Inorder:    D B F E A C G
Preorder:   A B D E F C G
Postorder:  D F E B G C A 

Draw Tree from Preorder & Inorder

                    A
                   / \
                  /   \ 
                 /     \
                B       C
               / \       \
              /   \       \
             D     E       G
                    \
                     \
                      F      

*/