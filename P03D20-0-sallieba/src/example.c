#include <ctype.h>
#include <stdio.h>

#define T_NUMBER 0
#define T_OPERATOR 1
#define T_BRACKET 2

struct token {
  int type;
  int value;
  int priority;
};

/* Reads the next token from stdin. Returns 1 on success, 0 on EOL. */
int next_token(struct token *t) {
  char c;

  /* discard spaces silently */
  do {
    c = getchar();
  } while (c == ' ');

  if (isdigit(c)) {
    t->type = T_NUMBER;
    t->value = 0;
    do {
      t->value = t->value * 10 + (c - '0');
      c = getchar();
    } while (isdigit(c));
    ungetc(c, stdin); /* save the non-digit for next time */

  } else if (c == '+' || c == '-' || c == '*' || c == '/') {
    t->type = T_OPERATOR;
    t->value = c;

  } else if (c == '(' || c == ')') {
    t->type = T_BRACKET;
    t->value = c;

  } else if (c == '\n') {
    ungetc(c, stdin); /* make sure we always return 0 from now on */
    return 0;

  } else {
    /* handle illegal character */
    
  }

  return 1;
}

int main() {

  struct token t;

  while (next_token(&t)) {
    switch (t.type) {
      case T_NUMBER:   printf("number   %d\n", t.value); break;
      case T_OPERATOR: printf("operator %c\n", t.value); break;
      case T_BRACKET:  printf("bracket  %c\n", t.value); break;
    }
  }

  return 0;
}