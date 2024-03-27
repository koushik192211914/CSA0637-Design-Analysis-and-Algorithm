#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    insert(&head, 3);
    insert(&head, 6);
    insert(&head, 9);
    printf("List after initial insertions: ");
    printList(head);
    int number_to_insert = 5;
    insert(&head, number_to_insert);
    
    // Print the list after insertion
    printf("List after inserting %d: ", number_to_insert);
    printList(head);
    
    return 0;
}
