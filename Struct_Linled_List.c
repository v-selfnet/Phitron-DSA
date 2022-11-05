#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

// S T R U C T U R E
struct Employee{
    int id;
	char name[20];
	int age;
    char desi[20];
    int salary;
};

// N O D E
struct Node{
    struct Employee data;
    struct Node *Next;
};

// I N I T I A L I Z A T I O N
void CreateNode(struct Node **head, struct Employee data);
void InsertNode(struct Node **head, struct Employee data, int opt, int pos);
int CountNode(struct Node *head);
void SearchByID(struct Node *head, struct Employee data[], int key);
void SearchByPosition(struct Node *head, int pos);
void DeleteNode(struct Node **head, int pos, int opt);
void Lebel();
void EmpInfoPrint(struct Employee data);
void displayList(struct Node *head);
void TakeInputData(struct Node *head, struct Employee data[], int size);

// C R E A T E  N O D E
void CreateNode(struct Node **head, struct Employee data){
    /*** each Node contain each employee record ***/
    struct Node *newNode = malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->Next = NULL;
   
    /* insertion at tail */
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

// I N S E R T I O N  N O D E
void InsertNode(struct Node **head, struct Employee data, int opt, int pos){
    /*** each Node contain each employee record ***/
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Next = NULL;
    
    if(opt == 1){
        /* inserttion at head */
        if(head != NULL){
            newNode->Next = *head;
            *head = newNode;
        }
        else{
            *head = newNode;
        }
    }
    else if(opt == 2){
        /* insertion at tail */
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
    else if(opt == 3){
        /* insertion at any position */
        struct Node *tmp = *head;
        for(int i=1; i<pos-1; i++){
            tmp = tmp->Next;
        }
        int count = CountNode(*head);
        if(pos > count+1){
            printf("Position out of Bound\n");
        }
        else{
            newNode->Next = tmp->Next;
            tmp->Next = newNode;
        }
    }
}

// C O U N T
int CountNode(struct Node *head){
    struct Node *tmp = head;
    int count = 0;
    while(tmp != NULL){
        tmp = tmp->Next;
        count++;
    }
    return count;
}

// S E A R C H  B Y  I D
void SearchByID(struct Node *head, struct Employee data[], int key){
    printf("\nSearch Result is:\n");
    Lebel();
    struct Node *tmp = head;
    while(tmp != NULL){
        if(tmp->data.id == key){
            EmpInfoPrint(tmp->data);
            return;
        }
        tmp = tmp->Next;
    }    
    printf("Not Found");
}

// S E A R C H  B Y  P O S I T I O N
void SearchByPosition(struct Node *head, int pos){
    printf("\nSearch Result is:\n");
    Lebel();
    struct Node *tmp = head;
    int count = CountNode(tmp);
    if(pos > count){
        printf("Position is out of bound. try again...\n");
        return;
    }
    for(int i=1; i<pos; i++){
        tmp = tmp->Next;
    }
    EmpInfoPrint(tmp->data);
}

// D E L E T I O N
void DeleteNode(struct Node **head, int pos, int opt){
    struct Node *delNode = *head;
    struct Node *tmp = *head;
   
    if(opt == 1){
    /* delete head */
        Lebel();
        if(*head != NULL){
            *head = (*head)->Next;
            EmpInfoPrint(delNode->data);
            free(delNode);
        } else printf("List is Empty. try again...");
    }
    else if(opt == 2){
    /* delete tail */
        Lebel();
        if(*head != NULL && (*head)->Next != NULL){
            while(tmp->Next->Next != NULL){
                tmp = tmp->Next;
            }
            delNode = tmp->Next;
            tmp->Next = NULL;
            EmpInfoPrint(delNode->data);
            free(delNode);
        } else printf("Head Node Do Not Delete. try again...");
    }
    else if(opt == 3){
    /* delete any position */
        Lebel();
        if(*head != NULL && (*head)->Next != NULL){
            if(pos > CountNode(*head)){
                printf("Position is out of bound. try again...\n");
                return;
            }
            for(int i=1; i<pos-1; i++){
                tmp = tmp->Next;
            }
            delNode = tmp->Next;
            tmp->Next = delNode->Next;
            delNode->Next = NULL;
            EmpInfoPrint(delNode->data);
            free(delNode);
        } else printf("Head Node Do Not Delete. try again...");
    }
    else printf("Invalid Number. try again...");
}

// L E B E L
void Lebel(){
    printf("ID\tName\tAge\tDesignation\tSalary\n");
    printf("--\t----\t---\t-----------\t------\n");
}

// P R I N T  D A T A
void EmpInfoPrint(struct Employee data){
    /*** print each employee data ***/
    printf("%d\t%s\t%d\t%s\t\t%d\n",
    data.id, data.name, data.age, data.desi, data.salary);
}

// P R I N T  N O D E
void displayList(struct Node *head){
    /*** print all employee data ***/
    struct Node *tmp = head;
    Lebel();
    int count = CountNode(tmp);
    while(tmp != NULL){
        EmpInfoPrint(tmp->data);
        tmp = tmp->Next;
    }
    printf("\nTotal Employees: %d\n", count);
}

// T A K E  I N P U T
void TakeInputData(struct Node *head, struct Employee data[], int size){
    int count = CountNode(head);
    for(int i=0; i<size; i++){
        data[i].id = count+i+1;
        printf("%d", i+1);
        printf("\tName : ");            scanf("%s", data[i].name);
        printf("\tAge : ");             scanf("%d", &data[i].age);
        printf("\tDesignation : ");     scanf("%s", data[i].desi);
        printf("\tSalary : ");          scanf("%d", &data[i].salary);
    }
    printf("\nSuccessfully added [ %d ] employees data\n", size);
    Lebel();
    for(int i=0; i<size; i++){
        EmpInfoPrint(data[i]);
    }
}

// M A I N
int main(){
    struct Node *head = NULL;
    
    // FILE *inputFile = fopen("in.txt", "r"); // for file
    
    int size;
    // fscanf(inputFile, "%d", &size); // for file
    // struct Employee data[size]; // for file
   
    printf("OOPs!!! File Not Found.\n");
    printf("How Many Emplpyees data want to Insert?: ");
    scanf("%d", &size);
    struct Employee data[size];
    TakeInputData(head, data, size);
    for(int i=0; i<size; i++){
        CreateNode(&head, data[i]);
    }
    
    // work with file
    // for(int i=0; i<size; i++){
    //     /* input from file */
    //     data[i].id = i+1;   
    //     fscanf(inputFile, "%s", data[i].name);
    //     fscanf(inputFile, "%d", &data[i].age);
    //     fscanf(inputFile, "%s", data[i].desi);   
    //     fscanf(inputFile, "%d", &data[i].salary);
    //     CreateNode(&head, data[i]);
    // }

    printf("\nAll Employee Linked List: \n");
    displayList(head);

    printf("\n-------------------------------");
    printf("\nChoice 0: Exit");
    printf("\nChoice 1: Search by ID");
    printf("\nChoice 2: Search by Position");
    printf("\nChoice 3: Deletion");
    printf("\nChoice 4: Create Node at Tail");
    printf("\nChoice 5: Insertion Node at any Position");
    printf("\n-------------------------------");
    
    int choice, key, option, count;
    printf("\nNext Choice: ");
    scanf("%d", &choice);
    while(choice != 0){
        switch(choice){
            case 1:
                printf("\nInput iD Number: ");
                scanf("%d", &key);
                SearchByID(head, data, key);
                break;
            case 2:
                printf("\nInput desired Position: ");
                scanf("%d", &key);
                SearchByPosition(head, key);
                break;
            case 3:
                /* deletion*/
                printf("\nOptions for Deletion:");
                printf("\n\t\t[ -^-Home-^-\t: 0 ]");
                printf("\n\t\t[ Head\t\t: 1 ]");
                printf("\n\t\t[ Tail\t\t: 2 ]");
                printf("\n\t\t[ Position\t: 3 ]");
                printf("\nSelect [0/1/2/3]: ");
                scanf("%d", &option);
                while(option != 0){
                    switch(option){
                        case 1:
                             DeleteNode(&head, -1, option); 
                             break;
                        case 2:
                             DeleteNode(&head, -1, option); 
                             break;
                        case 3:
                            printf("\nInput Desired Position: ");
                            scanf("%d", &key);
                            DeleteNode(&head, key, option); 
                            break;
                        default:
                            break;
                    }
                    printf("\nSelect [0/1/2/3]: ");
                    scanf("%d", &option);
                }
            case 4:
                /* insertion tail */
                printf("How Many Emplpyees data want to Insert?: ");
                scanf("%d", &size);
                TakeInputData(head, data, size);
                for(int i=0; i<size; i++){
                    CreateNode(&head, data[i]);
                }
                break;
            case 5:
                /* insertion at any position */
                printf("\nOptions for Insertion:");
                printf("\n\t\t[ -^-Home-^-\t\t: 0 ]");
                printf("\n\t\t[ At Head\t\t: 1 ]");
                printf("\n\t\t[ At Tail\t\t: 2 ]");
                printf("\n\t\t[ At Any Position\t: 3 ]");
                
                printf("\nSelect [0/1/2/3]: ");
                scanf("%d", &option);
                
                while(option != 0){
                    switch(option){
                        case 1:
                            /* insert head */
                            printf("Number of Emplpyees data Insert to head: ");
                            scanf("%d", &size);
                            TakeInputData(head, data, size);
                            for(int i=0; i<size; i++){
                                InsertNode(&head, data[i], option, -1);
                            }
                            break;
                        case 2:
                            /* insert tail */
                            printf("Number of Emplpyees data Insert to tail: ");
                            scanf("%d", &size);
                            TakeInputData(head, data, size);
                            for(int i=0; i<size; i++){
                                InsertNode(&head, data[i], option, -1);
                            }
                            break;
                        case 3:
                            /* insert at any position */
                            printf("Input Emplpyees size: ");
                            scanf("%d", &size);
                            printf("Input Emplpyees insert position: ");
                            scanf("%d", &key);
                            TakeInputData(head, data, size);
                            for(int i=0; i<size; i++){
                                InsertNode(&head, data[i], option, key);
                            }
                            break;
                        default:
                            break;
                    }
                    printf("\nSelect [0/1/2/3]: ");
                    scanf("%d", &option);
                }
                break;
            default:
                break;
        }
        printf("\nNext Choice: ");
        scanf("%d", &choice);
    }
    displayList(head);
}