#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left;
    struct Node *right;
    int data;
    int height;
};


struct Node* newNode(int key){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    node->data = key;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}



int height(struct Node *node){
    if(node == NULL){
        return -1;
    }
    return node->height;
}

void preorder(struct Node *node){
    if(node == NULL){
        return ;
    }
    printf("%d [ %d ] \t" , node->data , height(node->left) - height(node->right));
    preorder(node->left);
    preorder(node->right);
}

int max(int a , int b){
    return a>b?a:b;
}

struct Node* rightRotate(struct Node *node){
    struct Node *child = node->left;
    struct Node *childRight = child->right;

    child->right = node;
    node->left = childRight;

    node->height = max(height(node->left) , height(node->right)) + 1;
    child->height = max(height(child->left) , height(child->right) ) + 1;
    
    return child; 
}

struct Node* leftRotate(struct Node *node){
    struct Node *child = node->right;
    struct Node *childLeft = child->left;

    child->left = node;
    node->right = childLeft;

    node->height = max(height(node->left) , height(node->right)) + 1;
    child->height = max(height(child->left) , height(child->right) ) + 1;
    
    return child; 
}

struct Node* balance(struct Node *actualRoot , struct Node *root){
    if(height(root->left) - height(root->right) > 1){ //Left-heavy meaning left-left or left-right
        if(height(root->left->left) - height(root->left->right) > 0){ //Left-left
            printf("\n Before balancing: \n");
            preorder(actualRoot);
            printf("\nLL case at node %d...\n" , root->data);
            return rightRotate(root);
        } else if(height(root->left->left) - height(root->left->right) < 0){
            printf("\n Before balancing: \n");
            preorder(actualRoot);
            printf("\nLR case at node %d...\n" , root->data);
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if(height(root->left) - height(root->right) < -1){ //Right-heavy meaning right-right or right-left
        if(height(root->right->left) - height(root->right->right) <= 0){ //Right-right
            printf("\n Before balancing: \n");
            preorder(actualRoot);
            printf("\nRR case at node %d...\n" , root->data);
            return leftRotate(root);
        } else if(height(root->right->left) - height(root->right->right) > 0){ //Right-left
            printf("\n Before balancing: \n");
            preorder(actualRoot);
            printf("\nRL case at node %d...\n" , root->data);
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    // printf("\n Before balancing: \n");
    // preorder(actualRoot);
    //printf("\nNo rotation used for %d node \n" , root->data);
    return root;   
}

struct Node* insert(struct Node *root ,struct Node *node , int key){
    if(node == NULL){ //Adding a new leaf node whose height is 0
        return newNode(key);
    }

    if(key < node->data){
        node->left = insert(root ,node->left , key);
    } else {
        node->right = insert(root , node->right , key);
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    // if(root == node){ //Preorder printing before balancing
    //     printf("\n Before balancing: \n");
    //     preorder(root);
    // }

    return balance(root , node);
}



void main(){
    struct Node *root = NULL;
    int ch , data;
    while(1){
        printf("\n1.Enter a new value \n 2.Display preorder \n 3.Exit \n");
        scanf("%d" , &ch);
        if(ch == 1){
            printf("Enter a new value to be inserted: ");
            scanf("%d" , &data);
            root = insert( root ,root , data);
            printf("\nAfter balancing all nodes(if any balancing is needed...)\n");
            preorder(root);
        } else if(ch == 2){
            preorder(root);
        } else {
            break;
        }
    }
}
