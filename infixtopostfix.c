#include <stdio.h>
#define n 5
#include <ctype.h>

char s[n];
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
    if(ch == '+' || ch == '-'){
        return 1;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}

void infixtopostfix(char infix[]){
    for(int i=0; infix[i] != '\0'; i++){
        char ch = infix[i];

        //for operands
        if(isalnum(ch)){
            printf("%c", ch);
        }

        //for left paranthesis
        else if(ch == '('){
            push(ch);
        }    

        //for right bracket
        else if(ch == ')'){
            while(top != -1 && s[top] != '('){
                printf("%c", pop());
            }
            pop();
        } 

        //for operator, check precedence
        else{
            while(top != -1 && precedence(s[top]) >= precedence(ch)){
                printf("%c", pop());
            }
            push(ch);
        }
    }

    //pop remaining ops
    while(top != -1){
        printf("%c", pop());
    }
}

void main(){
    char infix[n];
    printf("Enter infix here : ");
    scanf("%s", infix);

    printf("postfix is : ");
    infixtopostfix(infix);
}