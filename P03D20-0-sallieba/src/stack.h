#ifndef SRC_STACK_H_
#define SRC_STACK_H_

//#define NMAX 1000;

struct Stack {
  int top;
  int maxSize;
  int *array;
};

struct Stack *create(int max);

int is_empty(struct Stack *stack);

void push(struct Stack *stack, int item);

int pop(struct Stack *stack);

int peek(struct Stack *stack);

int convert_rpn(char *input_expression);

#endif // SRC_STACK_H_
