#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int value){
        data = value;
        leftChild = NULL; 
        rightChild = NULL;
    }
};

bool isMirror(Node *root1, Node *root2){
    if(root1==NULL && root2==NULL) return true;
    else if(root1==NULL || root2==NULL) return false;
    else if(root1!=NULL && root2!=NULL){
        return(
            root1->data==root2->data &&
            isMirror(root1->leftChild, root2->rightChild) &&
            isMirror(root1->rightChild, root2->leftChild)
        );
    }
    else return false;
}

bool isSymmetric(Node *root){
    return isMirror(root, root);
}

int main(){
    Node *root = new Node(1);
    
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);

    Node *d = new Node(2);
    Node *e = new Node(3);
    Node *f = new Node(4);
    
    root->leftChild = a;
    root->leftChild->leftChild = b;
    root->leftChild->rightChild = c;
    
    root->rightChild = d;
    root->rightChild->leftChild = e;
    root->rightChild->rightChild = f;

    if(isSymmetric(root))
        cout<<"The Tree is Symmetric";
    else
        cout<<"The Tree is NOT Symmetric";
}

/*
# # # Perfect Binary Tree: Symmetric
                    1
                   / \
                  /   \ 
                 /     \
                /       \
               2         2
              / \       / \
             /   \     /   \
            3     4   4     3

# # # Binary Tree: NOT Symmetric
                    1
                   / \ 
                  /   \
                 /     \
                2       2
                 \       \
                  \       \
                   3       3
                    \       \
                     \       \
                      4       4

Algorithm: Check Symmetric Tree with Recursion.
Data: A binary tree T whose root node is root.
Result: Return true if T is symmetric, otherwise return false.

Function # 1
    isMirror(root1, root2):
        if root1 is empty && root2 is empty then
            return true;
        end
        else if root1 is empty || root2 is empty then
            return false;
        end
        else
            return 
            root1.value == root2.value &&
            isMirror(root1.left, root2.right) &&
            isMirror(root1.right, root2.left);
        end

Function # 2 
    isSymmetric(root):
        if root is empty then
            return true
        end
        return isMirror(root.left, root.right);
*/
