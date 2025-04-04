#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert in ascending order
void insert_ordered(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL || head->data >= value) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL && temp->next->data < value)
        temp = temp->next;

    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete a specific node while maintaining order
void delete_node(int value) {
    if (head == NULL) return;

    struct node* temp = head;
    struct node* prev = NULL;

    if (head->data == value) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert in Order\n2. Delete Node\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_ordered(value);
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
