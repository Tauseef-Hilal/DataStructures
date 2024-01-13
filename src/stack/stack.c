#include <stdio.h>
#include <stdlib.h>
#include "../../include/stack/stack.h"
#include "../../include/utils/common.h"
#include "../../include/linked_list/singly_linked_list.h"

Stack *STACK_new_stack(FreeFunction free_function)
{
  Stack *stack = alloc(sizeof(Stack));
  stack->list = SLL_new_list(NULL, NULL, free_function);
  return stack;
}

int STACK_is_empty(Stack *stack)
{
  return stack->list->length == 0;
}

int STACK_push(Stack *stack, void *data)
{
  return SLL_insert(stack->list, 0, data);
}

void *STACK_peek(Stack *stack)
{
  return SLL_get(stack->list, 0);
}

void *STACK_pop(Stack *stack)
{
  return SLL_pop(stack->list, 0);
}

void STACK_free(Stack *stack)
{
  SLL_free(stack->list);
  free(stack);
}