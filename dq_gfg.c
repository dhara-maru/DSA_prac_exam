#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

int deque[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

//insert an element at the front of the deque
void insertFront(int key) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) { 
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front = front - 1;
    }

    deque[front] = key;

}

//insert an element at the rear of the deque
void insertRear(int key) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (rear == -1) {  // If deque is initially empty
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0; 
    } else {
        rear = rear + 1;
    }

    deque[rear] = key;
}

//delete an element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    int removed = deque[front];

    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;  
    } else {
        front = front + 1;
    }

}

//delete an element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    int removed = deque[rear];

    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;  // wrap around
    } else {
        rear = rear - 1;
    }

}

void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
