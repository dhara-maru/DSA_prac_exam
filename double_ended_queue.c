#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int deque[SIZE], front = -1, rear = -1;

// Enqueue at front
void enqueue_front(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    deque[front] = value;
}

// Enqueue at rear
void enqueue_rear(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Deque is full\n");
        return;
    }
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    deque[rear] = value;
}

// Dequeue from front
void dequeue_front() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Dequeue from rear
void dequeue_rear() {
    if (rear == -1) {
        printf("Deque is empty\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Menu
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue_front(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue_rear(value);
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
