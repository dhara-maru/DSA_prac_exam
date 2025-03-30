#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

// Insert in the middle (after a given value)
void insert_middle(int value, int after) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    if (head == NULL) {
        new_node->prev = new_node->next = NULL;
        head = new_node;
        return;
    }
    struct node* temp = head;
    while (temp != NULL && temp->data != after)
        temp = temp->next;
    if (temp == NULL) return;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
}

// Delete a specific node
void delete_node(int value) {
    if (head == NULL) return;
    struct node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

// Display list
void display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu
int main() {
    int choice, value, after;
    while (1) {
        printf("\n1. Insert in Middle\n2. Delete Node\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value and after which node: ");
                scanf("%d %d", &value, &after);
                insert_middle(value, after);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_node(value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
