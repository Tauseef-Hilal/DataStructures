#include <stdio.h>
#include <stdlib.h>
#include "../../include/stack/stack.h"
#include "../../include/utils/types.h"

struct spam
{
  int foo;
  int bar;
};

void free_f(void *data);

int main()
{
  Stack *stack = STACK_new_stack(free_f);
  for (int i = 1; i <= 5; i++)
  {
    struct spam *x = alloc(sizeof(struct spam));
    x->foo = i;
    x->bar = i * i;
    STACK_push(stack, x);
  }

  printf("Stack Top -> %d\n", ((struct spam *)STACK_peek(stack))->bar);
  STACK_pop(stack);
  printf("Stack Top -> %d\n", ((struct spam *)STACK_peek(stack))->bar);

  STACK_free(stack);
  return 0;
}

void free_f(void *data)
{
  free(data);
}