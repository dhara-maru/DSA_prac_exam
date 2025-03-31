#include <stdio.h>
#define n 5

int s[5];
int top = -1;

void push(int x){
    if(top == n-1){
        printf("Stack overflow");
    }else{
        top++;
        s[top] = x;
    }
}
int pop(){
    if(top == -1){
        printf("Stack empty");
        return '\0';
    }
    else{
        return s[top--];
    }

}
int peep(){
    if(top == -1){
        printf("Stack empty");
        return '\0';
    }
    else{
        return s[top];
    }
}
void count(){
    if(top == -1){
        printf("Stack empty");
    }
    else{
        return top+1;
    }
}
void change(int i, int x){
    if(i < 1 || i > top + 1){
        printf("invalid position");
    }
    else{
        s[top - i + 1] = x;
    }
}
void display(){
    if(top == -1){
        printf("Stack empty");
     }
    else{
        for(int i=top-1; i>=0; i--){
            printf("%d", s[i]); 
        }
    }
}
void main(){
    int ch;
    while(1){
        printf("\n1.push \n2.pop \n 3.peep \n 4. change \n 5. count \n 6. display \n 7. exit");
        printf("Enter ur choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1 :
                int x;
                printf("ENter elem : ");
                scanf("%d", &x);
                push(x);
                break;
            case 2 :
                printf("%d is popped", pop());
                break;
            case 3 :
                printf("%d is at top", peep());
                break;
            case 4:
                int i, x;
                printf("ENter position : ");
                scanf("%d", &i);
                printf("ENter elem : ");
                scanf("%d", &x);
                change(i,x);
                break;
            case 5 :
                count();
                break;
            case 6 :
                display();
                break;
            case 7 :    
                exit(0);
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }
}