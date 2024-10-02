#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 100

struct Stack {
    int top;
    struct Node* stackInternal[CAPACITY];
} stack;

struct Node {
    struct Node *left;
    struct Node *right;
    char data;
};

// struct Node *root;

struct Node* newNode(char data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
     
    return node; 
}

void push(struct Node* number){
    //Incrementing the topmost index by 1
    stack.top++;


    //PRINTING ELEMENT TO BE PUSHED
    //printf("Pushing %d into stack \n" , number);


    if(stack.top >= CAPACITY){ //Edge case
        printf("Stack full!! Cannot push more!! \n");
        return;
    }


    //Pushing new element at topmost index
    stack.stackInternal[stack.top] = number; 
    //viewStack();
}

struct Node* pop() {
    if(stack.top == -1){
        return NULL; //Means that stack is empty
    }
    struct Node* ch= stack.stackInternal[stack.top--];

    //printf("Popped %d from stack \n" , ch);
    return ch;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t", root->data);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d \t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void createTree(char expression[CAPACITY]){
    int length = strlen(expression);

    struct Node* right;
    struct Node* left;
    
    for(int i = 0 ; i < length - 1; i++){

        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'|| expression[i] == '/'){

            right = pop();
            left = pop();
            struct Node* newRoot = newNode(expression[i]);
            newRoot->left = left;
            newRoot->right = right;
            push(newRoot);
        
        } else {
            push(newNode(expression[i]));
        }
    }

    printf("Displaying tree in inorder: \n");
    struct Node *eTree = pop();
    inorder(eTree);
}


void main(){
    stack.top = -1;
    char expression[CAPACITY];

    printf("Enter an expression IN POSTFIX: \n");
    fgets(expression, CAPACITY, stdin);
    int ch;
    while(1){
        printf("1.Create a expression tree \n 2.Evaluate \n");
        scanf("%d" , &ch);
        if(ch == 1){
            createTree(expression);
        }
    }
}
