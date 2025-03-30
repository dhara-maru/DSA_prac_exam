#include <stdio.h>
#define n 50

char s[n];
int top = -1;

void push(char c){
    if(top == n-1){
        printf("Stack overflow");
    }
    else{
        top++;
        s[top] = c;
    }
}
char pop(){
    if(top == -1){
        printf("Stack is empty");
        return '\0';
    }else{
        return s[top--];
    }
}
void main(){
    char str;
    printf("ENTER A STRING : ");
    scanf("%s", str);

    for(int i=0; s[i] != '\0'; i++){
        push(s[i]);
    }

    printf("Reverse string : ");

    while(top != -1){
        printf("%c", pop(s[top--]));
    }
}