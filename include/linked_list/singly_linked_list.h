#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "../utils/common.h"

typedef struct SLL_node
{
  void *data;
  struct SLL_node *next;
} SinglyLinkedListNode;

typedef struct SLL
{
  SinglyLinkedListNode *head;
  unsigned int length;

  PrintFunction print;
  CompareFunction compare;
  FreeFunction free;
} SinglyLinkedList;

SinglyLinkedList *SLL_new_list(
    PrintFunction print_function,
    CompareFunction compare_function,
    FreeFunction free_function);

SinglyLinkedListNode *SLL_new_node(void *data);
int SLL_insert(SinglyLinkedList *list, int pos, void *data);
int SLL_append(SinglyLinkedList *list, void *data);
int SLL_search(SinglyLinkedList *list, void *target);
void *SLL_pop(SinglyLinkedList *list, int pos);
void *SLL_get(SinglyLinkedList *list, int pos);
void SLL_sort(SinglyLinkedList *list);
void SLL_reverse(SinglyLinkedList *list);
void SLL_print(SinglyLinkedList *list);
void SLL_free(SinglyLinkedList *list);

#endif
