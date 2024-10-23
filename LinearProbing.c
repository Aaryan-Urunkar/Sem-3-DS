#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int size;

struct HashTable{
    int table[0];
} ;

// Function to create a hash table
struct HashTable* createHashTable() {
    // struct HashTable *ht = malloc(sizeof(struct HashTable));
    // ht->table = malloc(TABLE_SIZE * sizeof(int));
    struct HashTable *ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->table[size];
    for (int i = 0; i < size; i++) {
        ht->table[i] = -1; 
    }
    return ht;
}


int hash(int key) {
    return key % size;
}


void insert(struct HashTable *ht, int key) {
    int index = hash(key);
    int count = 0;
    while (ht->table[index] != -1 && count < size) {
        index = (index + 1) % size; 
        count++;
    }
    if(count < size){
        ht->table[index] = key;
    } else {
        printf("Hash table is full");
    }
}


int search(struct HashTable *ht, int key) {
    int index = hash(key);
    int count = 0;
    while (ht->table[index] != -1) {
        if (ht->table[index] == key) {
            return index; // Key found
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
        count++;
        if(count >= TABLE_SIZE){
            break;
        }
    }
    return -1; // Key not found
}

void display(struct HashTable *ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < size; i++) {
        if (ht->table[i] != -1) {
            printf("Index %d: %d\n", i, ht->table[i]);
        } else {
            printf("Index %d: [empty]\n", i);
        }
    }
}

// Main function
int main() {
    
    printf("Enter size of table:");
    scanf("%d" , &size);
    struct HashTable *ht ;
    ht = createHashTable();


    int ch, data;
    while(1){
        printf("\n 1.Insert an element \n 2.Search an element \n 3.Display hash table \n 4.Exit \n");
        scanf("%d" , &ch);
        if(ch == 1){
            printf("Enter element to be inserted: ");
            scanf("%d" , &data);
            insert(ht , data);
        } else if(ch == 2){
            printf("Enter element to be searched: ");
            scanf("%d" , &data);
            printf("\n Element found at index %d \n" , search(ht , data));
        } else if(ch == 3){
            display(ht);
        } else if(ch == 4){
            break;
        }
    }
    return 0;
}
