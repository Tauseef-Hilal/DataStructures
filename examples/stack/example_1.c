#include <stdio.h>
#include "../../include/stack/stack.h"
#include "../../include/utils/types.h"

int main()
{
  Stack *stack = STACK_new_stack(NULL);
  STACK_push(stack, INT(10));
  STACK_push(stack, INT(20));
  STACK_push(stack, INT(30));

  printf("Stack Top -> %d\n", *((int *)STACK_peek(stack)));
  STACK_pop(stack);
  printf("Stack Top -> %d\n", *((int *)STACK_peek(stack)));

  STACK_free(stack);
  return 0;
}
