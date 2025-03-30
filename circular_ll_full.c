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
    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
        head = new_node;
    }
}

// Insert at last
void insert_last(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
    }
}

// Delete first
void delete_first() {
    if (head == NULL) return;
    struct node* temp = head, *last = head;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while (last->next != head)
        last = last->next;
    head = head->next;
    last->next = head;
    free(temp);
}

// Delete last
void delete_last() {
    if (head == NULL) return;
    struct node* temp = head, *prev = NULL;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

// Delete at position
void delete_at_pos(int pos) {
    if (head == NULL || pos < 1) return;
    struct node* temp = head, *prev = NULL;
    if (pos == 1) {
        delete_first();
        return;
    }
    for (int i = 1; temp->next != head && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == head && pos > 1) return;
    prev->next = temp->next;
    free(temp);
}

// Count nodes
int count_nodes() {
    if (head == NULL) return 0;
    int count = 0;
    struct node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Menu
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n1. Insert First\n2. Insert Last\n3. Delete First\n4. Delete Last\n");
        printf("5. Delete at Position\n6. Count Nodes\n7. Display\n8. Exit\n");
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
