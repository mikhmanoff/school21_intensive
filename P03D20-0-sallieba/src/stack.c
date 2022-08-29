#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "stack.h"

struct Stack* create(int max) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->maxSize = max; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));
    return stack; 
} 


int isFull(struct Stack* stack) 
{ 
    if(stack->top == stack->maxSize - 1){
        printf("Will not be able to push maxSize reached\n");
    }
    
    return stack->top == stack->maxSize - 1; 
} 



int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
}


void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
}


int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 


    int peek(struct Stack* stack) 
    { 
        if (isEmpty(stack)) 
            return INT_MIN; 
        return stack->array[stack->top]; 
    }


int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'); 
} 

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

int covertInfixToPostfix(char* expr) 
{ 
    int i, j; 

    struct Stack* stack = create(strlen(expr)); 
    if(!stack)
        return -1 ; 

    for (i = 0, j = -1; expr[i]; ++i) 
    {
        if (checkIfOperand(expr[i])) 
            expr[++j] = expr[i]; 


        else if (expr[i] == '(') 
            push(stack, expr[i]); 

        else if (expr[i]==')') 
        {
            if(expr[i]==')')
            {
                while (!isEmpty(stack) && peek(stack) != '(') 
                    expr[++j] = pop(stack); 
                

                pop(stack);
            }
        }
        else
        { 
            while (!isEmpty(stack) && precedence(expr[i]) <= precedence(peek(stack))) 
                expr[++j] = pop(stack); 
            push(stack, expr[i]); 
        }
    }

    while (!isEmpty(stack)) 
        expr[++j] = pop(stack); 

    expr[++j] = '\0'; 
    printf( "%s", expr); 
} 

int main()
{
    char expression[] = "a(3*5))-d"; 
    covertInfixToPostfix(expression); 
    return 0; 
}