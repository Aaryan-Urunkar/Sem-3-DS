#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Hash table structure
struct HashTable {
    int table[TABLE_SIZE];
};


struct HashTable* createHashTable() {
    struct HashTable *ht = (struct HashTable*)malloc(sizeof(struct HashTable));

    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = -1; 
    }

    return ht;
}


int hash(int key) {
    return key % TABLE_SIZE;
}


void insert(struct HashTable *ht, int key) {
    int index = hash(key);
    int i = 0; 
    int count = 0;

    while (ht->table[(index + i * i) % TABLE_SIZE] != -1 && count < TABLE_SIZE) {
        i++; 
        count++;
    }

    if (count >= TABLE_SIZE) {
        printf("Hash table is full\n");
    } else {
        ht->table[(index + i * i) % TABLE_SIZE] = key; 
    }
}


int search(struct HashTable *ht, int key) {
    int index = hash(key);
    int i = 0; 
    int count = 0;

    while (ht->table[(index + i * i) % TABLE_SIZE] != -1 && count < TABLE_SIZE) {
        if (ht->table[(index + i * i) % TABLE_SIZE] == key) {
            return (index + i * i) % TABLE_SIZE; // Key found
        }
        i++;
        count++;
    }

    return -1; // Key not found
}


void display(struct HashTable *ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != -1) {
            printf("Index %d: %d\n", i, ht->table[i]);
        } else {
            printf("Index %d: [empty]\n", i);
        }
    }
}

// Main function
int main() {
    struct HashTable *ht = createHashTable();

    int choice, data;
    while (1) {
        printf("\n1. Insert an element\n2. Search for an element\n3. Display the hash table\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &data);
                insert(ht, data);
                break;
            case 2:
                printf("Enter element to be searched: ");
                scanf("%d", &data);
                int result = search(ht, data);
                if (result != -1) {
                    printf("Key %d found at index %d\n", data, result);
                } else {
                    printf("Key %d not found\n", data);
                }
                break;
            case 3:
                display(ht);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
