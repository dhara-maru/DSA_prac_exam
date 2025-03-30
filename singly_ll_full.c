#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert at first
void insert_first(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

// Insert at last
void insert_last(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}


// Delete first
void delete_first() {
    if (head == NULL) return;
    struct node* temp = head;
    head = head->next;
    free(temp);
}

// Delete last
void delete_last() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete at position
void delete_at_pos(int pos) {
    if (head == NULL || pos < 1) return;
    struct node* temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }
    struct node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Count nodes
int count_nodes() {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
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
    int choice, value, pos;
    while (1) {
        printf("\n1. Insert First\n2. Insert Last\n");
        printf("3. Delete First\n4. Delete Last\n5. Delete at Position\n");
        printf("6. Count Nodes\n7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_first(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_last(value);
                break;
            case 3:
                delete_first();
                break;
            case 4:
                delete_last();
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_at_pos(pos);
                break;
            case 6:
                printf("Total nodes: %d\n", count_nodes());
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
