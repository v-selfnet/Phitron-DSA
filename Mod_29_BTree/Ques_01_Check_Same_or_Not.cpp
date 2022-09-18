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

bool isSameTree(Node *root1, Node *root2){
    if(root1==NULL && root2==NULL) return 1;
    if(root1!=NULL && root2!=NULL){
        return(
            root1->data==root2->data &&
            isSameTree(root1->leftChild, root2->leftChild) &&
            isSameTree(root1->rightChild, root2->rightChild)
        );
    }
    else return 0;
}
int main(){
    /*
    int n;
    cout<<"Enter First Tree: ";
    cin>>n;
    Node *root1[n];
    for(int i=0; i<n; i++){
        root1[i] = new Node(0);
    }

    for(int i=0; i<n; i++){
        int value, left, right;
        cin>>value>>left>>right;
        root1[i]->data = value;
        if(left != 0){
            root1[i]->leftChild = root1[left];
        }
        if(right != 0){
            root1[i]->rightChild = root1[right];
        }
    }

    int n2;
    cout<<"Enter Second Tree: ";
    cin>>n2;
    Node *root2[n2];
    for(int i=0; i<n2; i++){
        root2[i] = new Node(0);
    }

    for(int i=0; i<n2; i++){
        int value, left, right;
        cin>>value>>left>>right;
        root2[i]->data = value;
        if(left != 0){
            root2[i]->leftChild = root2[left];
        }
        if(right != 0){
            root2[i]->rightChild = root2[right];
        }
    }

    if(isSameTree(root1[1], root2[1]))
        cout<<"Same";
    else
        cout<<"Not Same";

        */

    Node *root1 = new Node(1);
    Node *a = new Node(3);
    // Node *b = new Node(2);
    root1->leftChild = a;
    // root1->rightChild = b;

    Node *root2 = new Node(1);
    // Node *x = new Node(2);
    Node *y = new Node(3);
    // root2->leftChild = x;
    root2->rightChild = y;

    if(isSameTree(root1, root2))
        cout<<"Same";
    else
        cout<<"Not Same";

    
}

/*
Test Case # 1 : Same Tree
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



Test Case # 2 : Same Tree
3
1 2 3
2 0 0
3 0 0


Test Case # 3 : Not a Same Tree
2
1 2 0
2 0 0

2
1 0 2
2 0 0



*/