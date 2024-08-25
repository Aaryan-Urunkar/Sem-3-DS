#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

struct Queue {
    int front;
    int rear;
    int elements[CAPACITY];
};

struct Queue queue;

void viewQueue(){
    printf("Contents of the queue are: \n");
    for(int i = queue.front+1 ; i <= queue.rear ; i++){
        printf("%d \t" , queue.elements[i]);
    }
    printf("\n");
}

void enqueue(int elem){
    if(queue.rear + 1 == CAPACITY){
        printf("Queue is full!! Cannot insert! \n");
        return;
    }else {
        queue.rear++;
    }
    queue.elements[queue.rear] = elem;
    viewQueue();
}

int dequeue(){
    if( queue.front >= queue.rear){
        printf("Queue is emoty! Cannot dequeue \n");
        return -404;
    }
    int elemToBeRemoved = queue.elements[++queue.front];
    return elemToBeRemoved;
}


void main(){
    queue.front = -1;
    queue.rear = -1;
    int ch , pushElement;
    while (1)
    {
        printf("1.Enqueue \n 2.Dequeue \n 3.Exit \n");
        
        scanf("%d" , &ch);
        if(ch == 1){ 

            printf("Enter new element: ");
            scanf("%d" , &pushElement);
            printf("\n");
            enqueue(pushElement);

        } else if(ch == 2){

            int elemPopped = dequeue();
            if(elemPopped != -404){
                printf("The dequeued element is: %d \n" , elemPopped);
            }
            viewQueue();

        }else if(ch == 3){
            break;
        }
    }
}