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

// Inorder = Left - Root - Right
void InOrder(Node *root){ 
    if(root != NULL){
        InOrder(root->leftChild);
        cout<<root->data<<" ";
        InOrder(root->rightChild);
    } 
}
// Preorder = Root - Left - Right
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
// Level Order Traversal
void LevelOrder(Node *root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *chkNode = q.front();
        q.pop();
        if(chkNode != NULL){
            cout<<chkNode->data<<" ";
            if(chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(q.empty()){
                q.push(NULL);
            }
        }
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
    cout<<endl<<"Inorder: ";
        InOrder(nodes[0]);
    cout<<endl<<"Preorder: ";
        PreOrder(nodes[0]);
    cout<<endl<<"Postorder: ";
        PostOrder(nodes[0]);
    cout<<endl<<"Levelorder: ";
        LevelOrder(nodes[0]);
}

/*
Input:
5
3 4 20
4 -1 -1
20 15 7
15 -1 -1
7 -1 -1



Input:
10
0 1 2
1 3 4
2 -1 5
3 6 -1
4 7 -1
5 8 -1
6 -1 -1
7 -1 -1
8 -1 9
9 -1 -1

Inorder: [Left Root Right]      6 3 1 7 4 0 2 8 9 5
Preorder: [Root Left Right]     0 1 3 6 4 7 2 5 8 9
Postorder: [Left Right Root]    6 3 7 4 
# # # Full Binary Tree:
                    0
                   / \
                  /   \ 
                 /     \
                1       2
               / \       \
              /   \       \
             3     4       5
            /     /       /
           /     /       /                    
          6     7       8
                         \
                          \
                           9

*/
