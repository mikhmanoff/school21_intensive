#include "stack.h"
struct stack *init() {
  struct stack *t = (struct stack *)malloc(sizeof(struct stack));
  t->top = NULL;
  t->size = 0;
  return t;
}
void push(struct stack *list, int x) {
  // int flag = 1;
  if (!list) {
    // flag = 0;
    return;
  }
  // if (flag != 0) {
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  if (list->top == NULL) {
    t->next = NULL;
    list->top = t;
  } else {
    t->next = list->top;
    list->top = t;
  }
  // flag = list->top->data;
  list->size++;
  //}
  // return flag;
}
int pop(struct stack *list) {
  int flag = 1;
  if (!list || !list->top)
    flag = 0;
  if (flag != 0) {
    int value = list->top->data;
    struct Node *del = list->top;
    list->top = list->top->next;
    free(del);
    list->size--;
    flag = value;
  }
  return flag;
}
int not_null(struct stack *list) { return !list->top; }
void destroy(struct stack *list) {
  if (!list) {
    return;
  }
  if (list->top) {
    delet(list->top);
  }
  free(list);
}
void delet(struct Node *list) {
  if (list) {
    delet(list->next);
  }
  free(list);
}
void print(struct stack *list) {
  for (struct Node *p = list->top; p != NULL; p = p->next) {
    printf("%d ", p->data);
  }
  printf("\n");
}
