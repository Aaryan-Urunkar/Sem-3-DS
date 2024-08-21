#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 100
#define EXPRESSION_SIZE 100

/**
 * OPERATOR PRECEDENCE ASSUMED :
 * 
 * HIGHEST            ^
 *                *   /   %
 * LOWEST        +         -
 */

struct Stack
{
    int top;
    char operators[CAPACITY];
};

struct Stack stack;

void viewStack()
{ // Just to view the content of the stac
    // printf("Contents of stack updated: \n");
    for (int i = 0; i <= stack.top; i++)
    {
        printf("%c \t", stack.operators[i]);
    }
    printf("\n");
}

void push(char operator)
{
    // Incrementing the topmost index by 1
    stack.top++;

    if (stack.top >= CAPACITY)
    { // Edge case
        printf("Stack full!! Cannot push more!! \n");
        return;
    }

    // Pushing new element at topmost index
    stack.operators[stack.top] = operator;
    //viewStack();
}

char pop()
{
    if (stack.top == -1)
    {
        return 32; // Means that stack is empty
    }
    return stack.operators[stack.top--];
}

void precedenceWisePush(char operator){
    // printf("%c \n" , operator);
    if(operator == ')'){
        while (stack.operators[stack.top] != '(')
        {
            printf("%c" , pop());
        }
        pop();
    } else if(operator == '(' || operator == '^') {
        if(operator == '^' && stack.operators[stack.top] == '^'){
            // ^ and ^ are equal precedence hence this is an edge case
            printf("%c" , pop());

        }
        push(operator);
    } else if(operator == '/' || operator == '*' || operator == '%'){
        if ( stack.operators[stack.top] == '^' || stack.operators[stack.top] == '/' || stack.operators[stack.top] == '*' || stack.operators[stack.top] == '%')
        { //Element at top of stack has lower or equal precedence
            printf("%c" , pop());
            push(operator);
        }else {
             push(operator);
        }
        
    } else if( operator == '+' || operator == '-'){
        if (stack.operators[stack.top] == '^' ||  stack.operators[stack.top] == '/' || stack.operators[stack.top] == '*' || stack.operators[stack.top] == '%' || stack.operators[stack.top] == '+' || stack.operators[stack.top] == '-'){
            printf("%c" , pop());
            push(operator);
        } else {
        push(operator);
        }
    }
}

void eval(char expression[EXPRESSION_SIZE])
{
    int length = strlen(expression);

    for (int i = 0; i < length; i++)
    {
        if (expression[i] == '^' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%' || expression[i] == '(' || expression[i] == ')')
        {
            // printf("%c" , expression[i]);
            precedenceWisePush(expression[i]);
        } else {
            printf("%c" , expression[i]);
        }
    }

    while (stack.top != -1)
    {
        printf("%c" , pop());
        //stack.top = -1;
    }

}

void main()
{
    char expression[EXPRESSION_SIZE];

    // Assuming that expression will only have operands and valid operators: (,),+,-,*,/,% and ^ (raised to)
    fgets(expression, EXPRESSION_SIZE, stdin);
    // printf("%s" , expression);
    eval(expression);
    
    
}
