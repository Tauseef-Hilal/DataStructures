#ifndef STACK_H
#define STACK_H

#include "../linked_list/singly_linked_list.h"
#include "../utils/common.h"

typedef struct stack
{
  SinglyLinkedList *list;
} Stack;

Stack *STACK_new_stack(FreeFunction free_function);
int STACK_is_empty(Stack *stack);
int STACK_push(Stack *stack, void *data);
void *STACK_pop(Stack *stack);
void *STACK_peek(Stack *stack);
void STACK_free(Stack *stack);

#endif