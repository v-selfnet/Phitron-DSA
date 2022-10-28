#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Emp{
    int id;
	char name[20];
	int age;
    char dese[20];
    int salary;
};

void EmpInfoPrint(struct Emp data){
    data.id = 1; // auto generate id number not working
    printf("%d\t%s\t%d\t%s\t%d\n",
    data.id, data.name, data.age, data.dese, data.salary);
}

struct Node{
    struct Emp data;
    struct Node *Next;
};

void createNode(struct Node **head, struct Emp data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *tmp = *head;
        while(tmp->Next != NULL){
            tmp = tmp->Next;
        }
        tmp->Next = newNode; 
    }
    
}

void displayList(struct Node **head){
    struct Node *tmp = *head;
    printf("ID\tName\tAge\tDesegnation\tSalary\n");
    printf("--\t----\t---\t-----------\t------\n");
    int CountNode = 0;
    while(tmp != NULL){
        EmpInfoPrint(tmp->data);
        tmp = tmp->Next;
        CountNode++;
    }
    printf("\nTotal Employees: %d", CountNode);
}

int main(){
    struct Node *head = NULL;

    int num;
    printf("How Many Emplpyee Records [Node] Want to Create: ");
    scanf("%d", &num);
    
    struct Emp data[num];
    
    for(int i=1; i<=num; i++){ 
        printf("%d", i);
        
        printf("\tName: ");
        scanf("%s", data[i].name);
        
        printf("\tAge: ");
        scanf("%d", &data[i].age);
        
        printf("\tDesegnation: ");
        scanf("%s", data[i].dese);
        
        printf("\tSalary: ");
        scanf("%d", &data[i].salary);
        
        createNode(&head, data[i]);
    }
    printf("\nAll Employee Linked List: \n");
    displayList(&head);
}