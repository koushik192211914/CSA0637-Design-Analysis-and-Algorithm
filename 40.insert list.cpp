#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a number into the list
void insert(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data to new node
    new_node->data = new_data;
    
    // Link the new node to the list
    new_node->next = (*head_ref);
    
    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty list
    struct Node* head = NULL;
    
    // Insert some numbers into the list
    insert(&head, 3);
    insert(&head, 6);
    insert(&head, 9);
    
    // Print the list
    printf("List after initial insertions: ");
    printList(head);
    
    // Insert a new number into the list
    int number_to_insert = 5;
    insert(&head, number_to_insert);
    
    // Print the list after insertion
    printf("List after inserting %d: ", number_to_insert);
    printList(head);
    
    return 0;
}
