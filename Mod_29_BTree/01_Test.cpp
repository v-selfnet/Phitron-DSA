#include<bits/stdc++.h>
using namespace std;

// Linked List
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value){
        data = value;
        left = NULL; 
        right = NULL;
    }
};
void printTree(Node *root){
    if(root != NULL){
        cout<<long(root->left)<<" "
        <<root->data<<" "
        <<long(root->right)<<endl;
        printTree(root->left);
        printTree(root->right);
    }
}

int main(){
    Node *root = new Node(0);
        root->left = new Node(1);
        root->right = new Node(2);
        root->left->left = new Node(3);
        root->left->right = new Node(4);

        printTree(root);
    
}

/*
# # # Input:
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

# # # Output:
Root: 0
Left:
    Root: 1
    Left: 3
    Right: 4
Right:
    Root: 2
    Left:
        Root: 5
        Left: 7
        Right: 8
    Right: 6

# # # Full Binary Tree:
                    0
                   / \
                  /   \ 
                 /     \
                1       2
               / \     / \
              /   \   /   \
             3     4 5     6
                    / \
                   /   \                      
                  7     8



# # # Binary Tree Level:
- - - - - - - - - - 0 - - - - - - - - - -   Level # 0 
                   / \
                  /   \ 
                 /     \
- - - - - - - - 1       2 - - - - - - - -   Level # 1
               / \     / \
              /   \   /   \
- - - - - - -3     4 5     6- - - - - - -   Level # 2
                    / \
                   /   \                      
- - - - - - - - - 7     8- - - - - - - - -  Level # 3

*/