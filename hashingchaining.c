#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

void initHashTable() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        hashTable[i] = NULL;  // Initialize all slots as empty linked lists.
    }
}

int hash(int key) 
{
    return key % SIZE;  // Simple modulo-based hash function.
}

void insertChaining(int key) 
{
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) 
    {
        hashTable[index] = newNode;
    } else 
    {
        // Collision occurred, add the new node to the linked list.
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void displayHashTable() 
{
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) 
    {
        struct Node* current = hashTable[i];
        printf("%d: ", i);
        while (current != NULL) 
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() 
{
    initHashTable();

    insertChaining(5);
    insertChaining(25);
    insertChaining(15);
    insertChaining(35);
    insertChaining(3);

    displayHashTable();

    return 0;
}
