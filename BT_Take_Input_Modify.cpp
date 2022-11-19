#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int data){
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

Node* CreateNode(Node *&root, int data){
    /* Create Node for Binary Tree */
    Node *newNode = new Node(data);
    if(root == NULL){
        root = newNode;
    }
    if(root->leftChild == NULL){
        root->leftChild = newNode;
    }
    if(root->rightChild == NULL){
        root->rightChild = newNode;
    }
    return newNode;
}

void PrintInOrder(Node *root){
    /* In Order Traversal Recursive */
    if(root == NULL) return;
    PrintInOrder(root->leftChild);
    cout<<root->data<<" ";
    PrintInOrder(root->rightChild);
}

void LevelOrder(Node *root){
    /* Level Order Traversal [from root to leaf] */
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node *currentRoot = q.front();
        q.pop();
        cout<<currentRoot->data<<" ";
        
        if(currentRoot->leftChild != NULL)
            q.push(currentRoot->leftChild);
        if(currentRoot->rightChild != NULL)
            q.push(currentRoot->rightChild);
    }
}

int main(){
    int val;
    cin>>val;
    Node *root = new Node(val);
    
    queue <Node*> q;
    q.push(root);

    while(!q.empty()){
    /* Level Order input using queue Data Structure */
        Node *currentRoot = q.front();
        q.pop();
        
        int left, right;
        cin>>left>>right;
        
        if(left != -1){
            currentRoot->leftChild = CreateNode(root, left);
            q.push(currentRoot->leftChild);
        }
        
        if(right != -1){
            currentRoot->rightChild = CreateNode(root, right);
            q.push(currentRoot->rightChild);
        }
    }

    PrintInOrder(root);
    cout<<endl;
    LevelOrder(root);
}

/*

Input Format:
1
2 3
4 -1 5 6
-1 7 -1 -1 -1 8
-1 -1 -1 -1

                1
               / \
              /   \
             /     \
            2       3
           /        /\
          /        /  \
         4        5    6
          \             \
           \             \
            7             8

InOrder: 4 7 2 1 5 3 6 8
*/
