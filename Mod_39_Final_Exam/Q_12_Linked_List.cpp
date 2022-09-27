/*

Answer the following questions for the doubly linked list as shown below, where 
        p = 12 
        q = p+4
        r = p+q 
        s = r-3
        t = r+s				

        a) head −> next −>next-> value = ?
        b) last −> prev −> next->value = ?
        c) temp −> prev −> prev −> prev= ?
        d) temp −> next−> prev −>prev->value = ?
        e) last −> prev −> prev −>next-> value = ?





*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *Next;
    Node *Prev;
    Node(int val){
        this->val = val;
        this->Next = NULL;
        this->Prev = NULL;
    }
};

    void createNode(Node *&head, int val){
        Node *newNode = new Node(val);
        if(head == NULL){
           head = newNode;
           return;
        }
        else{
            Node *tmp = head;
            while(tmp->Next != NULL){
                tmp = tmp->Next;
            }
            tmp->Next = newNode;
        }

    }

    // M I D
    Node *midNode(Node *head){
        Node *fast = head;
        Node *slow = head;
        while(fast != NULL && fast->Next != NULL){
            fast = fast->Next->Next;
            slow = slow->Next;
        }
        return slow;
    }
    Node *lastNode(Node *head){
        Node *tmp = head;
        while(tmp->Next != NULL){
            tmp = tmp->Next;
        }
        return tmp;
    }

    void Answer(Node *head){
        Node *first = head;
        Node *temp = midNode(head);
        Node *last = lastNode(head);

        // for(int  i=0; i<5; i++){
        // }
            int p = 12;
            createNode(first, p);
            // cout<<first->Next->Next->val<<endl; //a
            // cout<<last->Prev->Next->val<<endl; //b
            // cout<<temp->Prev->Prev->Prev<<endl; //c
            // cout<<temp->Next->Prev->Prev->val<<endl; //d
            // cout<<last->Prev->Prev->Next->val<<endl; //e

    }

    Node *Reverse(Node *head){
        Node *prev = NULL;
        Node *current = head;
        Node *next = head->Next;

        while(true){
            current->Next = prev;
            prev = current;
            current = next;
            if((current == NULL)) break;
                next = next->Next;
        }
        return prev;
    }

    void display(Node *head){
        Node *tmp = head;
        while(tmp != NULL){
            cout<<tmp->val;
            if(tmp->Next != NULL){
                cout<<" -> ";
            }
            tmp = tmp->Next;
        }
        cout<<endl;
}

int main(){
    Node *head = NULL;
    
    int p = 12;  // 12          (c) null
    int q = p+4; // 12+4 = 16   (d)
    int r = p+q; // 12+16 = 28  (a) 
    int s = r-3; // 28-3 = 25   (e)
    int t = r+s; // 28+25 = 53  (b)
   
    createNode(head, p);
    createNode(head, q);
    createNode(head, r);
    createNode(head, s);
    createNode(head, t);
    
    Answer(head);

    display(head);
    // cout<<"Mid: "<<midNode(head)<<endl;
    // cout<<"Last: "<<lastNode(head)<<endl;

    // head = Reverse(head);
    // display(head);
}