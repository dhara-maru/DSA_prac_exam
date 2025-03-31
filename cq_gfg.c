#include <stdio.h>
#define n 5
int queue[n];
int front = -1, rear = -1;

int isFull()
{
    return (rear + 1) % n == front;
}

int isEmpty()
{
    return front == -1;
}

void enqueue(int x)
{
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % n;
    queue[rear] = x;
}

int dequeue()
{
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % n;
    }
    return data;
}

void display()
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
    }
    printf("%d\n", queue[rear]);
}

