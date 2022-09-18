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

 
int height(Node* root) {
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
 
void CurrentLevel(Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
       CurrentLevel(root->left, level-1);
       CurrentLevel(root->right, level-1);
    }
}
 
void LevelOrder(Node* root) {
    int h = height(root);
    // int i;
    for (int i=h; i>=1; i--)
        CurrentLevel(root, i);
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
    
    LevelOrder(root);
    cout<<height(root);
}