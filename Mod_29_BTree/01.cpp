#include<bits/stdc++.h>
using namespace std;

// Linked List
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

void printTree(Node* root, int level);
void spacePrint(int level);

void printTree(Node* root, int level){
    // When tree empty
    if(root == NULL){
        return;
    }
    // Case 1
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data<<endl;
        return;
    }
    // Case 2
    else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root: "<<root->data<<endl;
    }
    if(root->leftChild != NULL){
        spacePrint(level);
        cout<<"Left: ";
        printTree(root->leftChild, level+1); // recursive

    }
    if(root->rightChild != NULL){
        spacePrint(level);
        cout<<"Right: ";
        printTree(root->rightChild, level+1); // recursive
    }
}

void spacePrint(int level){
    for(int i=0; i<level; i++){
        cout<<"   ";
    }
}

int main(){
    int n;
    cin>>n;
    Node *nodes[n];
    for(int i=0; i<n; i++){
        nodes[i] = new Node(-1);
    }

    for(int i=0; i<n; i++){
        int value, left, right;
        cin>>value>>left>>right;
        nodes[i]->data = value;
        if(left != -1){
            nodes[i]->leftChild = nodes[left];
        }
        if(right != -1){
            nodes[i]->rightChild = nodes[right];
        }
    }

    printTree(nodes[0], 0);
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