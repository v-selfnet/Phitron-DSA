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

// Level Order Traversal [from root to leaf]
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
    Node *root = new Node(3);
    Node *a = new Node(9);
    Node *b = new Node(20);
    Node *c = new Node(15);
    Node *d = new Node(7);

    root->leftChild = a;
    root->rightChild = b;

    b->leftChild = c;
    b->rightChild = d;

    cout<<endl<<"Levelorder [root to leaf]: ";
    LevelOrder(root);
   
}

/*
# # # Full Binary Tree:

                     3
                    / \ 
                   /   \
                  9     20
                        /\
                       /  \
                      15   7
                        
3 9 20 15 7
*/
