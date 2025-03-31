#include <stdio.h>
#include <stdlib.h>

#define n 5

int deque[n], front = -1, rear = -1;

// Enqueue at front
void enqueue_front(int x) {
    if ((rear + 1) % n == front) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front = (front - 1 + n) % n;
    }
    deque[front] = x;
}

// Enqueue at rear (normal)
void enqueue_rear(int x) {
    if ((rear + 1) % n == front) {
        printf("Deque is full\n");
        return;
    }
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    deque[rear] = x;
}

// Dequeue from front (normal)
void dequeue_front() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
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
        rear = (rear - 1 + n) % n;
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
        i = (i + 1) % n;
    }
    printf("\n");
}

// Menu
int main() {
    int choice, x;
    while (1) {
        printf("\n1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue_front(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue_rear(x);
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
