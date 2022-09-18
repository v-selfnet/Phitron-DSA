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


// Current Level of Tree
void currentLevel(Node* root, int level){
    if(root==NULL)
        return;
    if(level==1)
        cout<<root->data <<" ";
    else if(level>1){
       currentLevel(root->leftChild, level-1);
       currentLevel(root->rightChild, level-1);
    }
}

// Level Order Traversal [from leaf to root]
void LevelOrder(Node *root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    int leftHeight = 1;
    int rightHeight = 1;

    while(!q.empty()){
        Node *chkNode = q.front();
        q.pop();
        if(chkNode != NULL){
            if(chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
                leftHeight++;
            }
            if(chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
                rightHeight++;
            }
        }
        else{
            if(q.empty()){
                q.push(NULL);
            }
        }
    }
    int height = leftHeight>rightHeight?leftHeight:rightHeight;
    for(int i=height; i>0; i--){
        currentLevel(root, i);
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

    cout<<"Levelorder [leaf to root]"<<endl;
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
                        
15 7 9 20 3
*/
