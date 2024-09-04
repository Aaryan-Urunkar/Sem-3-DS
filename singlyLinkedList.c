#include <stdio.h>
#include <stdlib.h>

struct Node { 
    int data;
    struct Node *next;
};
struct Node *first;

void viewList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d \t" , temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void insertStart( int data){
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode ->data = data;
    newNode ->next = first;
    first = newNode;
    
}

void insertEnd( int data){
    struct Node * temp = first;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode ->data = data;
    newNode ->next = NULL;
    temp->next = newNode;
}

void insertPosition(int data , int pos){
    if(pos == 0) {
        insertStart(data);
        return;
    }
    struct Node * temp = first;
    int i = 1;
    while(i<pos){
        temp = temp -> next;
        i++;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode ->data = data;
    newNode ->next = temp->next;
    temp->next = newNode;
}

void deleteFirstNode(){
    struct Node *temp = first;
    first = temp->next;
    temp->next = NULL;
    free(temp);
}

void deleteNode(int pos){
    int i =1;
    struct Node *temp = first;
    struct Node *follow = NULL;
    while(i<pos){
        i++;
        follow = temp;
        temp = temp->next;
    }
    follow-> next = temp-> next;
    temp->next = NULL;
    free(temp);
}

void main(){
    first = NULL;
    int ch , data , pos;
    while(1){
        printf("1.Insert at beginning \n 2.Insert at end \n 3.Insert at position \n 4.Delete first node \n 5.Delete n'th node \n 6.Exit \n");
        scanf("%d" , &ch);
        if(ch == 1){
            printf("Enter data to be inserted: ");
            scanf("%d" , &data);
            insertStart( data);
            viewList(first);
        } else if(ch == 2){
            printf("Enter data to be inserted: ");
            scanf("%d" , &data);
            insertEnd( data);
            viewList(first);
        } else if(ch == 3){
            printf("Enter data to be inserted: ");
            scanf("%d" , &data);
            printf("\nEnter position: ");
            scanf("%d" , &pos);
            insertPosition( data , pos);
            viewList(first);
        }else if(ch == 4){
            deleteFirstNode();
            viewList(first);
        }else if( ch == 5){
             printf("Enter position of node to be deleted: ");
            printf("\nEnter position: ");
            scanf("%d" , &pos);
            deleteNode( pos);
            viewList(first);
        } else if(ch == 6){
            break;
        }
    }
}
