#include <stdio.h>
#define n 5

int q[5]; 
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == n-1){
        printf("Queue overflow");
    }
    else{
        if(front == -1){
            front = 0;
        }
        q[++rear] = x;
    }
}
void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue empty");
        front = rear = -1;
        return;
    }
    front++;
}
void display(){
    if(front == 0 || front > rear){
        printf("Queue is empty");
        return;
    }
    for(int i=front; i<= rear; i++){
        printf("%d", q[i]);
    }
}
void main(){
    int ch;
    while
}