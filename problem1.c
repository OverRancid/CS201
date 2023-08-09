//OverRancid#0590
#include <stdio.h>      //Parental Advisory
#include <stdlib.h>    //Explicit Content

#define size 100

int top = -1;
int stack[size];
int minElement;

void push(int value){
    if(top==-1){
        minElement = value;
    }
    top++;
    if(value<minElement){
        stack[top] = 2*value - minElement;
        minElement = value;
        return;
    }
    stack[top] = value;
}

void pop(){
    if(stack[top] < minElement){
        minElement = 2*minElement - stack[top];
    }
    top--;
}

void min(){
    if(top<0){
        printf("empty stack detected\n\topinion rejected.\n");
        return;        
    }
    printf("Min Element: %d\n", minElement);
}

void Top(){
    if(top<0){
        printf("empty stack detected\n\topinion rejected.\n");
        return;
    }
    int answer = stack[top];
    if(answer<minElement){
        answer =  2*minElement - answer;
    }
    printf("Top Element: %d\n", answer);
}

int main(){
    char instruction;
    int x;
    printf("initalize stack with 10 elements\n");
    for(int i=0; i<10; i++){
        scanf("%d", &x);
        push(x);
    }
    printf("(i): push\n(d): pop\n(m): min\n(t): top\n(q):quit\n");
    while(1){
        scanf(" %c", &instruction);
        if(instruction=='i'){
            scanf("%d", &x);
            push(x);
        }
        else if(instruction=='d'){
            pop();
        }
        else if(instruction=='m'){
            min();
        }
        else if(instruction=='t'){
            Top();
        }
        else{
            exit(0);
        }
    }
    return 0;
}

