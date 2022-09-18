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

// ZigZag Order traversal with stack.
void ZigZagOrder(Node* root){
    // if null then return
    if(!root) return;
 
    // declare two stacks
    stack<Node*> currentlevel;
    stack<Node*> nextlevel;
 
    // push the root
    currentlevel.push(root);
 
    // check if stack is empty  
    bool lefttoright = true;
    while (!currentlevel.empty()){
        // pop out of stack
        Node* temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if(temp){
            // print the data in it
            cout << temp->data << " ";
 
            // store data according to current order
            if(lefttoright){
                if (temp->leftChild)
                    nextlevel.push(temp->leftChild);
                if (temp->rightChild)
                    nextlevel.push(temp->rightChild);
            }
            else{
                if (temp->rightChild)
                    nextlevel.push(temp->rightChild);
                if (temp->leftChild)
                    nextlevel.push(temp->leftChild);
            }
        }
        if(currentlevel.empty()){
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
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

    cout<<endl<<"Zigzag order traversal: ";
    ZigZagOrder(root);
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
                        
3 20 9 15 7
*/
