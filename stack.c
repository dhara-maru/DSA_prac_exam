#include <stdio.h>
#include <stdlib.h>
#define n 5
int s[n];
int top = -1;

void push(int x) {
    if (top == n - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        s[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Popped elem is %d\n", s[top--]);
    }
}

void peep() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Top elem is %d\n", s[top]);
    }
}

void count() {
    printf("There are %d elements in the stack\n", top + 1);
}

void change(int position, int x) {
    if (position < 1 || position > top + 1) {
        printf("Invalid index\n");
    } else {
        s[top - position + 1] = x;
    }
}

void display() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch = 0;

    while (ch != 6) {
        printf("\nMenu\n1. Push\n2. Pop\n3. Peep\n4. Change\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int x;
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4: {
                int y, position;
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter element to change: ");
                scanf("%d", &y);
                change(position, y);
                break;
            }
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Not valid\n");
                break;
        }
    }

    return 0;
}
