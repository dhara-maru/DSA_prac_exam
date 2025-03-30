#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define n 50

int s[n];
int top = -1;

void push(int x){
    top++;
    s[top] = x;
}

int pop(){
    if(top==-1){
        return '\0';
    }
    else{
        return s[top--];
    }
}

int eval(char *exp){
    for(int i=0; exp[i]; i++){
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }
        else{
            int b = pop();
            int a = pop();
            switch(exp[i]){
                case '+' : 
                    push(a+b);
                    break;
                case '-':
                    push(a-b);
                    break;
                case '*':
                    push(a*b);
                    break; 
                case '/':
                    push(a/b);
                    break; 
            }
        }
    }
    return pop();
}

void main(){
    char exp[n];

    scanf("%s", exp);
    printf("%d", eval(exp));
}