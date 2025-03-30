#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { 
    stack[++top] = c; 
}
char pop() { 
    return stack[top--]; 
}
char peek() { 
    return stack[top]; 
}
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void reverse(char *exp) {
    int l = 0, r = strlen(exp) - 1;
    while (l < r) {
        char temp = exp[l];
        exp[l++] = exp[r];
        exp[r--] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isalnum(c)){
            prefix[j++] = c;
        }
        else if (c == ')'){
            push(c);
        } 
        else if (c == '(') 
        {
            while (top != -1 && peek() != ')') prefix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c)) prefix[j++] = pop();
            push(c);
        }
    }
    while (top != -1){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverse(prefix);
}

void main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);

}
