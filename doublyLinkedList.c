#include <stdio.h>
#include <stdlib.h>

struct Node { 
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *first;

void displayList( struct Node *first){
    struct Node *temp = first;
    printf("\n The elements of the list are : \n");
    while (temp != NULL){
        printf("%d \t" , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert( int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(first == NULL ){
        
        first = newNode;
    } else {
        struct Node *temp = first;
        while (temp->next != NULL){
            temp = temp->next;
        }
        newNode->prev = temp;
        //newNode->next = NULL;
        temp->next = newNode;
    }
    
}

int removeStart(){
    if(first == NULL){
             printf("List is empty!");
             return -404;
    }
    if(first->next == NULL && first->prev == NULL){
        
        int a = first->data;
        first = NULL;
        return a;
    }
    int a = first->data;
    first = first->next;
    struct Node *temp = first->prev;
    first-> prev = NULL;
    //free(temp);
    return a;
}

void reverseList(){
    printf("Head of the list before reversing isbefore reversing is %d \n " , first->data);
    struct Node *temp = first;
    int len = 1;
    while (temp->next != NULL){
        temp = temp->next;
        len++;
    }
    struct Node *reverse  = temp;
    struct Node *reverseHead =NULL;
    struct Node *reverseFollow ;
    while(temp->prev != NULL){
        reverse->next = temp->prev;
        //reverse->prev = reverseFollow;

        if(reverseHead == NULL){
            reverseHead = reverse;
        }
        //reverseFollow = reverse;
        reverse = reverse->next;
        

        temp = temp->prev;
        
    }
    reverse->next = NULL;
    // first = reverseHead;
    
    first = NULL;
    while(reverseHead != NULL){
        insert(reverseHead->data);
        reverseHead=reverseHead->next;
    }
    
    displayList(first);
}


void main()
{
    
    first = NULL;

    int ch, no, pos;

    while (1){
        printf("1.Insert a number \n 2.Remove first node \n 3.Reverse the linked list \n 4.Exit \n");
        scanf("%d" , &ch);
        if(ch == 1){
            printf("Enter a number to be inserted: ");
            scanf("%d" , &no);
            insert( no);
            displayList(first);
        } else if(ch ==2 ){
            no = removeStart();
            if(no != -404){
            printf("The removed element is %d \n" , no);
            }
            displayList(first);
        } else if(ch == 3){
            reverseList();
        } else if(ch == 4){
            break;
        }
    }

    
}
