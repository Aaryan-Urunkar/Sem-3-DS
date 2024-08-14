#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

struct Stack {
    int top;
    int stackInternal[CAPACITY];
};

void push(struct Stack *stackpointer, int element)
{   
   // printf("%d", stackpointer->top);
    if(stackpointer->top >= CAPACITY-1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stackpointer->top++; //incrementing top by 1 b4 pushing new element
    stackpointer->stackInternal[stackpointer->top]=element; 
    
}

void pop(struct Stack *stackpointer)
{   
    if(stackpointer->top == -1)//if stack is empty, we don't decrement top
    {
        printf("Stack is empty\n");
        return;
    }
    stackpointer->top--;
}

void viewStack(struct Stack *stackpointer)
{ //Just to view the content of the stack

    printf("Contents of stack updated: \n");
    for (int i = 0; i <= stackpointer->top; i++)
    {
        printf("%d \t" , stackpointer->stackInternal[i]);
    }
    printf("\n");

}

void main()
{
    struct Stack stack;
    stack.top=-1;
     while (1)
    {
        printf("1.Push \n 2.Pop \n 3.Exit \n");
        int ch , pushElement;
        scanf("%d" , &ch);
        if(ch == 1)
        { 

            printf("Enter new element: ");
            scanf("%d" , &pushElement);
            printf("\n");
            push(&stack,pushElement);
            viewStack(&stack);

        } else if(ch == 2){

            pop(&stack);
           // printf("The popped element is: %d \n" , elemPopped);
            viewStack(&stack);

        }else if(ch == 3){
            break;
        }
    }
    
}