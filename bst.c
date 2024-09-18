#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* root;

struct Node* newNode(int item) {
    struct Node* temp = 
       (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}



struct Node* insert(struct Node* node, int data) {

    if (node == NULL)
        return newNode(data);
    
   
    if (node->data == data)
        return node;
    
    
    if (node->data < data)
        node->right = insert(node->right, data);
    
    else
        node->left = insert(node->left, data);


    return node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \t", root->data);
        inorder(root->right);
    }
}

int main()
{
    root = NULL;
    int ch, data;
    while(1){
        printf("1.Add new element to linked list \n 2.Display list \n 3.Exit \n");
        scanf("%d" , &ch);
        if(ch == 1){
            printf("Enter element to be inserted: ");
            scanf("%d" , &data);
            root = insert(root, data);
            //inorder(root);
        } else if(ch == 2){
            inorder(root);
            printf("\n");
        }else if(ch == 3){
            break;
        }
    }
    return 0;
}
