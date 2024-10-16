#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CAPACITY 100

/////////////////
///QUEUE CODE///
///////////////

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
    //viewQueue();
}

int dequeue(){
    if( queue.front >= queue.rear){
        printf("Queue is emoty! Cannot dequeue \n");
        return -404;
    }
    int elemToBeRemoved = queue.elements[++queue.front];
    return elemToBeRemoved;
}


///////////////
//GRAPH///////
/////////////
int vertices;
int visited[0];



void displayMatrix(int matrix[vertices][vertices]){
    for(int i = 0; i < vertices ; i++){
        for(int j = 0; j < vertices; j++){
            printf("%d " , matrix[i][j]);
        }
    }
}

void BFS(int matrix[vertices][vertices]){
    int visited[vertices];
    for(int i =0 ; i < vertices ; i++){ //Initializing to default values
        visited[i] = 0;
    }

    int startFrom ,node;
    printf("Start search from (enter node value between 0 and %d): " , vertices - 1);
    scanf("%d", &startFrom);
    printf("\n");
    if(startFrom < 0 || startFrom >= vertices){
        return;
    }
    visited[startFrom] = 1; //Coz this node is initially visited
    printf("%d " , startFrom);
    enqueue(startFrom); //Enqueued i for exploration

    while(queue.front != queue.rear){ //While queue is not empty
        node = dequeue();
        for(int i = 0;i<vertices ; i++){
            if(matrix[node][i] == 1 && visited[i] == 0){
                printf("%d " , i);
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void DFS(int matrix[vertices][vertices] ,int A){
    int i;
    printf("%d " , A);
    visited[A] = 1;
    for(i = 0 ; i < vertices; i++){
        if(matrix[A][i] == 1 && visited[i] != 1){
            DFS(matrix , i);
        }
    }
}

void main(){
    printf("Enter number of vertices/nodes : ");
    scanf("%d" , &vertices);
    int arr[vertices][vertices];
    
    
    visited[vertices];
    


    for(int i = 0; i < vertices ; i++){
        for(int j = 0; j < vertices; j++){
            if(i == j){
                arr[i][j] = 0;
                continue;
            }
            printf("\n Is node %d connected to %d (Enter 1 if yes otherwise 0) : " ,i ,j);
            scanf("%d" , &arr[i][j]);
        }
    }
    int ch , data;
    while(1){
        printf("\n 1.BFS \n 2.DFS \n 3.Exit \n");
        scanf("%d" , &ch);
        if(ch == 1){
            BFS(arr);
        } else if(ch == 2){
            printf("Enter node to start from : ");

            for(int i =0 ; i < vertices ; i++){ //Initializing to default values
                visited[i] = 0;
            }

            scanf("%d" , &data);
            printf("\n");
            DFS( arr , data);
        } else if(ch == 3){
            break;
        }
    }
    BFS(arr);
}
