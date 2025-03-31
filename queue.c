#include <stdio.h>
#include <stdlib.h>

#define n 5

int queue[n], front = -1, rear = -1;

// Enqueue (Insert)
void enqueue(int value) {
    if (rear == n - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Dequeue (Remove)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        front = rear = -1;
        return;
    }
    front++;
}

// Display
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Menu
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
