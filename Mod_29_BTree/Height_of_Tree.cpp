#include <iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root){
    if (root == NULL) return 0;
    else {
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight) 
            return(lheight + 1);
        else 
            return(rheight + 1);
        
    }
}

int main() {
	Node *root = new Node(3);
    Node *a = new Node(9);
    Node *b = new Node(20);
    Node *c = new Node(15);
    Node *d = new Node(7);

    root->left = a;
    root->right = b;

    b->left = c;
    b->right = d;
    
    cout<<height(root);
}