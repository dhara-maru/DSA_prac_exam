#include <stdio.h>
#include <stdlib.h>

#define n 5

int queue[n], front = -1, rear = -1;

// Enqueue (Insert)
void enqueue(int x) {
    if ((rear + 1) % n == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % n;
    queue[rear] = x;
}

// Dequeue (Remove)
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; ; i = (i + 1) % n) {
        printf("%d ", queue[i]);
        if (i == rear) break;
    }
    printf("\n");
}

// Menu
int main() {
    int choice, x;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
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
