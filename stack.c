#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

struct Stack {
    int top;
    int stackInternal[CAPACITY];
};

struct Stack stack; //global variable of struct Stack 

void viewStack() { //Just to view the content of the stac
    printf("Contents of stack updated: \n");
    for (int i = 0; i <= stack.top; i++)
    {
        printf("%d \t" , stack.stackInternal[i]);
    }
    printf("\n");
}

void push(int number){
    //Incrementing the topmost index by 1
    stack.top++;

    if(stack.top >= CAPACITY){ //Edge case
        printf("Stack full!! Cannot push more!! \n");
        return;
    }


    //Pushing new element at topmost index
    stack.stackInternal[stack.top] = number; 
    viewStack();
}

int pop() {
    if(stack.top == -1){
        return 404; //Means that stack is empty
    }
    return stack.stackInternal[stack.top--];
}


void main(){
    stack.top = -1;
    while (1)
    {
        printf("1.Push \n 2.Pop \n 3.Exit \n");
        int ch , pushElement;
        scanf("%d" , &ch);
        if(ch == 1){ 

            printf("Enter new element: ");
            scanf("%d" , &pushElement);
            printf("\n");
            push(pushElement);

        } else if(ch == 2){

            int elemPopped = pop();
            printf("The popped element is: %d \n" , elemPopped);
            viewStack();

        }else if(ch == 3){
            break;
        }
    }
}

