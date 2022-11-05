#include<stdio.h>
#include<stdlib.h>

struct Student{
    int roll;
    char name[10];
};

struct Node{
    struct Student data;
    struct Node *next;
    struct Node *prev;
};

void Insertion(struct Node **head, struct Student data){
    struct Node *newNode = malloc(sizeof(struct Node));
    
    /* assign value */
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
            tmp->next = newNode;
            newNode->prev = tmp;
        }
    }
}

// P R I N T  N O D E
void displayList(struct Node *head){
    struct Node *tmp = head;
    while(tmp != NULL){
        printf("%d|%s <--> ", tmp->data.roll, tmp->data.name);
        tmp = tmp->next;
    }
}

int main(){
    struct Node *head = NULL;
    
    int size;
    printf("How many Node wanna create: ");
    scanf("%d", &size);
   
    struct Student data[size];
    for(int i=0; i<size; i++){
        printf("Roll: ");   scanf("%d", &data[i].roll);
        printf("Name: ");   scanf("%s", data[i].name);
        
        Insertion(&head, data[i]);
    }
    displayList(head);
}