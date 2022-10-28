#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node *Next;
};

void createNode(struct Node **head, int val);
struct Node *reverseNonRecursive(struct Node *head);
int CountNode(struct Node *head);
void InsertAtHead(struct Node **head, int val);
void InsertAtTail(struct Node *head, int val);
int FindMiddleValue(struct Node *head);
void InsertAtMiddle(struct Node *head, int val);
void InsertByPosition(struct Node *head, int val, int pos);
void DeletionHead(struct Node **head);
void DeletionMiddle(struct Node *head);
void DeletionTail(struct Node *head);
void DeletionByPosition(struct Node **head, int pos);
void SearchByValueAndPosition(struct Node *head, int opt, int key);
void SearchValueDuplicate(struct Node *head, int key);
void displayList(struct Node **head);

// C R E A T E  N O D E
void createNode(struct Node **head, int val){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = val;
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

// R E V E R S E  N O N  R E C U R S I V E
struct Node *reverseNonRecursive(struct Node *head){
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = head->Next;
    
    while(curr != NULL){
        // set value
        curr->Next = prev;
        // go ahead 
        prev = curr;
        curr = next;
        if(curr == NULL) break;
        next = next->Next;
    }
    return prev;
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

// I N S E R T I O N  A T  H E A D
void InsertAtHead(struct Node **head, int val){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->Next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->Next = *head;
        *head = newNode;
    }
}

// I N S E R T I O N  A T  T A I L
void InsertAtTail(struct Node *head, int val){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->Next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node *tmp = head;
        while(tmp->Next != NULL){
            tmp = tmp->Next;
        }
        tmp->Next = newNode;
    }   
}

// M I D D L E  V A L U E
int FindMiddleValue(struct Node *head){
    struct Node *fast = head;
    struct Node *slow = head;
    while(fast != NULL && fast->Next != NULL){
        fast = fast->Next->Next;
        slow = slow->Next;
    }
    return slow->val;
}

// I N S E R T  M I D D L E
void InsertAtMiddle(struct Node *head, int val){
    struct Node *fast = head;
    struct Node *slow = head; 

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->Next = NULL;

    /*
    int count = CountNode(head);
    if(count%2 == 0){
        while(fast->Next->Next != NULL){
            fast = fast->Next->Next;
            slow = slow->Next;
        }
        newNode->Next = slow->Next;
        slow->Next = newNode;
    }
    else{
        while(fast->Next != NULL){
            fast = fast->Next->Next;
            slow = slow->Next;
        }
        newNode->Next = slow->Next;
        slow->Next = newNode;
    }*/
    
    while(fast->Next != NULL && fast->Next->Next != NULL){
            fast = fast->Next->Next;
            slow = slow->Next;
        }
        newNode->Next = slow->Next;
        slow->Next = newNode;
    
}

// I N S E R T  D E S I R E D  P O S I T I O N
void InsertByPosition(struct Node *head, int val, int pos){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->Next = NULL;
    
    // Head insertion not work

    struct Node *tmp = head;
    for(int i=1; i<pos-1; i++){
        tmp = tmp->Next;
    }
    
    int count = CountNode(head);
    if(pos > count+1){
        printf("Position out of Bound\n");
    }
    else{
        newNode->Next = tmp->Next;
        tmp->Next = newNode;
    }
}

// D E L E T I O N  H E A D
void DeletionHead(struct Node **head){
    struct Node *delNode = *head;
    if(*head != NULL){
        *head = (*head)->Next;
        free(delNode);
    }
    else
        printf("Empty List");
}

// D E L E T I O N  M I D D L E
void DeletionMiddle(struct Node *head){
    // Find the Middle Position
    struct Node *fast = head;
    struct Node *slow = head;
    while(fast!= NULL && fast->Next != NULL){
            fast = fast->Next->Next;
            slow = slow->Next;  // slow = mid
    }
    struct Node *delNode = slow;
    
    // Traverse Mid-1 Posotion
    if(head->Next == NULL) 
        printf("Permission Deny !!!\n");
    else{
        struct Node *tmp = head;
        int count = CountNode(head);
        for(int i=0; i<count/2-1; i++){
            tmp = tmp->Next;
        }
        tmp->Next = tmp->Next->Next;
        delNode->Next = NULL;
        free(delNode);
        }
}

// D E L E T I O N  T A I L
void DeletionTail(struct Node *head){
    struct Node *tmp = head;
    if(head->Next == NULL){
        printf("Permission Deny! Head Can Not Delete\n");
    }
    else{
        while(tmp->Next->Next != NULL){
            tmp = tmp->Next;
        }
        struct Node *delNode = tmp->Next;
        tmp->Next = NULL;
        free(delNode);
    }
}

// D E L E T I O N  B Y  P O S I T I O N
void DeletionByPosition(struct Node **head, int pos){
    int count = CountNode(*&*head);
    if(pos == 1){
        DeletionHead(&*head);
    }
    else if(pos>count){
        printf("Position out of Bound. List Size [%d]\n", count);
    }
    else{
        struct Node *tmp = *head;
        for(int i=1; i<pos-1; i++){
            tmp = tmp->Next;
        }
        struct Node *delNode = tmp->Next;
        tmp->Next = delNode->Next;
        delNode = NULL;
        free(delNode);
    }
}

// D E L E T I O N  B Y  V A L U E
void DeletionByValue(struct Node **head, int key){
    if(*head == NULL){
        /* Handel Empty List */
        printf("Empty List");
    }
    else if((*head)->val == key){
        /* Handel Head */
        struct Node *delHead = *head;
        *head = (*head)->Next;
        free(delHead);
    }
    else{
        /* Handel all Values include Tail*/
        struct Node *tmp = *head;
        struct Node *delNode;
        while(tmp->Next != NULL){
            if(tmp->Next->val == key){
                /* if key found enter this block */
                delNode = tmp->Next;
                tmp->Next = delNode->Next;
                delNode->Next = NULL;
                free(delNode);
                break;
            }
            else{
                tmp = tmp->Next;
                if(tmp->Next == NULL){
                     /* if key not found enter this block */
                    printf("Value [%d] Not Found !!! Try again...\n", key);
                }
            }
        }     
    }
}

// S E A R C H  B Y  V A L U E  &  P O S I T I O N
void SearchByValueAndPosition(struct Node *head, int opt, int key){
    struct Node *tmp = head;
    int countPos = 1;
    if(opt == 1){
        /* Search by Value */
        while(tmp != NULL){
            if(tmp->val == key){
                printf("\nRequested Value [%d]\nand the Position is [%d]", key, countPos);
                return;
            }
            tmp = tmp->Next;
            countPos++;
        }
        printf("\nRequested Value not yet in List.\nTry again...");
    }
    else if(opt == 2){
        /* Search by Position */
        int count = CountNode(head);
        if(key > count){
            printf("Position out of bound.\ntry again...");
        }
        else{
            for(int i=1; i<key; i++){
                tmp = tmp->Next;
            }
            printf("\nRequested Position [%d]\nand the Value is [%d]", key, tmp->val);
        }    
    }
}

// S E A R C H  B Y  V A L U E  D U P L I C A T E
void SearchValueDuplicate(struct Node *head, int key){
    struct Node *tmp = head;
    int count = 0;
    int frequency = 1;
    printf("Values Positions are: ");
    while(tmp != NULL){
        if(tmp->val == key){
            // print the positions of values
            printf("%d ", count);
            frequency++;
        }
        tmp = tmp->Next;
        count++;
    }
    printf("\nFrequency: %d", frequency);
}
// P R I N T
void displayList(struct Node **head){
    struct Node *tmp = *head;
    while(tmp != NULL){
        printf("%d", tmp->val);
        if(tmp->Next != NULL){
            printf(" -> ");
        }
        tmp = tmp->Next;
    }
} 

// M A I N  F U N C T I O N
int main(){
    struct Node *head = NULL;

    int n;
    printf("How many Node wanna create: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int val;
        printf("Input value for Node %d: ", i);
        scanf("%d", &val);
        createNode(&head, val);
    }
    printf("\nLinked List: \n");
    displayList(&head);

    printf("\n-------------------------------");
    printf("\nChoice 0: Exit");
    printf("\nChoice 1: Reverse Non Recursive");
    printf("\nChoice 2: Count Nodes");
    printf("\nChoice 3: Insertion at Head");
    printf("\nChoice 4: Insertion at Tail");
    printf("\nChoice 5: Find the Moddle Value");
    printf("\nChoice 6: Insert Value for Moddle");
    printf("\nChoice 7: Insert Value by Position");
    printf("\nChoice 8: Deletion at Head");
    printf("\nChoice 9: Deletion at Middle");
    printf("\nChoice 10: Deletion at Tail");
    printf("\nChoice 11: Deletion by Position");
    printf("\nChoice 12: Deletion by Value");
    printf("\nChoice 13: Search by Value & Position");
    printf("\nChoice 14: Search by Value Duplicate");
    printf("\n-------------------------------");

    int choice, count, opt ,value, pos;
    printf("\nNext Choice: ");
    scanf("%d", &choice);
    while(choice != 0){
        switch(choice){
            case 1:
                printf("\nReversed Linked List: \n");
                head = reverseNonRecursive(head);
                displayList(&head);
                break;
            case 2:
                count = CountNode(head);
                printf("\nTotal Nodes: %d", count);
                break;
            case 3:
                printf("\nValue of Head Node: ");
                scanf("%d", &value);
                InsertAtHead(&head, value);
                displayList(&head);
                break;
            case 4:
                printf("\nValue of Tail Node: ");
                scanf("%d", &value);
                InsertAtTail(head, value);
                displayList(&head);
                break;
            case 5:
                printf("\nMiddle Position Value is: ");
                int midVal = FindMiddleValue(head);
                printf("%d", midVal);
                break;
            case 6:
                printf("\nInsert Value for Middle Position: ");
                scanf("%d", &value);
                InsertAtMiddle(head, value);
                displayList(&head);
                break;
            case 7:
                printf("\nInsert Value & Position: ");
                scanf("%d %d", &value, &pos);
                InsertByPosition(head, value, pos);
                displayList(&head);
                break;
            case 8:
                DeletionHead(&head);
                displayList(&head);
                break;
            case 9:
                DeletionMiddle(head);
                displayList(&head);
                break;
            case 10:
                DeletionTail(head);
                displayList(&head);
                break;
            case 11:
                printf("\nDelete Position: ");
                scanf("%d", &pos);
                DeletionByPosition(&head, pos);
                displayList(&head);
                break;
            case 12:
                printf("\nDelete Value: ");
                scanf("%d", &value);
                DeletionByValue(&head, value);
                displayList(&head);
                break;
            case 13:
                printf("\n[ Go To Main Menu\t: 0 ]\n[ Search by Value\t: 1 ]\n[ Search by Position\t: 2 ]\n");
                printf("\nSelect [0/1/2]: ");
                scanf("%d", &opt);
                while(opt != 0){
                    if(opt==1){
                        printf("\nInput Desired Value: ");
                        scanf("%d", &value);
                        SearchByValueAndPosition(head, opt, value);
                    }
                    else if(opt == 2){
                        printf("\nInput Desired Position: ");
                        scanf("%d", &value);
                        SearchByValueAndPosition(head, opt, value);
                    }
                    else{
                        printf("\nWrong Selection. try again...\n");
                    }
                    printf("\nSelect [0/1/2]: ");
                    scanf("%d", &opt);
                }
                break;
            case 14:
                printf("\nInput Desired Value: ");
                scanf("%d", &value);
                SearchValueDuplicate(head, value);
                break;
            default:
                break;
        }
        printf("\nNext Choice: ");
        scanf("%d", &choice);
    }
    printf("\nFinal List Structure is: \n");
    displayList(&head);
}