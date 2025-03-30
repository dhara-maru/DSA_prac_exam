#include <stdio.h>
#include <ctype.h>
#define n 5

char s [n];
int top = -1;

void push(char ch){
    top++;
    s[top] = ch;
}
char pop(){
    if(top == -1){
        return '\0';

    }else{
        return s[top--];
    }
}
int precedence(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else return 0;
}
void topostfix(char infix[]){
    for(int i=0; infix[i] != '\0'; i++){
        char ch = infix[i]; 

        if(isalnum(ch)){
            printf("%c", ch);
        }

        else if(ch == '('){
            push(ch);
        }

        else if(ch == ')'){
            while(top != -1 && s[top] != '('){
                printf("%c",pop());

            }
            pop();
        }


        else{
            while(top != -1 && precedence(s[top]) >= precedence(ch)){
                printf("%c",pop());

            }
            push(ch);
        }

    }

    while(top != -1){
        printf("%c", pop());
    }
}
void main(){
    char infix[n];

    printf("Enter infix : ");
    scanf("%s", infix);

    topostfix(infix);
    printf(infix);
}