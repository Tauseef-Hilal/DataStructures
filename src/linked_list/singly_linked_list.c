#include <stdio.h>
#include <stdlib.h>
#include "../../include/utils/common.h"
#include "../../include/utils/types.h"
#include "../../include/utils/errors.h"
#include "../../include/linked_list/singly_linked_list.h"

SinglyLinkedList *SLL_new_list(
    PrintFunction print_function,
    CompareFunction compare_function,
    FreeFunction free_function)
{
  SinglyLinkedList *list = alloc(sizeof(SinglyLinkedList));
  list->length = 0;
  list->head = NULL;

  list->print = print_function;
  list->free = free_function;
  list->compare = compare_function;

  return list;
}

SinglyLinkedListNode *SLL_new_node(void *data)
{
  SinglyLinkedListNode *node = alloc(sizeof(SinglyLinkedListNode));
  node->data = data;
  node->next = NULL;
  return node;
}

int SLL_insert(SinglyLinkedList *list, int pos, void *data)
{
  if (!list->head)
  {
    list->head = SLL_new_node(data);
    list->length++;
    return SUCCESS;
  }

  if (pos < 0 || pos > list->length)
  {
    return INVALID_POSITION_ERROR;
  }

  SinglyLinkedListNode *new = SLL_new_node(data);
  if (pos == 0)
  {
    new->next = list->head;
    list->head = new;
    list->length++;
    return SUCCESS;
  }

  SinglyLinkedListNode *prev = list->head;
  for (int i = 0; i < pos - 1; i++)
  {
    prev = prev->next;
    if (!prev)
      return INVALID_POSITION_ERROR;
  }

  new->next = prev->next;
  prev->next = new;
  list->length++;

  return SUCCESS;
}

int SLL_append(SinglyLinkedList *list, void *data)
{
  SinglyLinkedListNode *node = SLL_new_node(data);

  if (!list->head)
  {
    list->head = node;
    list->length++;
    return SUCCESS;
  }

  SinglyLinkedListNode *curr = list->head;
  while (curr->next)
    curr = curr->next;

  curr->next = node;
  list->length++;
  return SUCCESS;
}

void *SLL_pop(SinglyLinkedList *list, int pos)
{
  if (list->length == 0)
    return INT(EMPTY_STRUCTURE_ERROR);

  if (pos < 0 || pos > list->length - 1)
  {
    return INT(INVALID_POSITION_ERROR);
  }

  if (pos == 0)
  {
    SinglyLinkedListNode *temp = list->head;
    void *data = temp->data;

    list->head = temp->next;
    list->length--;
    free(temp);

    return data;
  }

  SinglyLinkedListNode *prev = list->head;
  for (int i = 0; i < pos - 1; i++)
  {
    prev = prev->next;
    if (!prev || !prev->next)
    {
      return INT(INVALID_POSITION_ERROR);
    }
  }

  SinglyLinkedListNode *temp = prev->next;
  void *data = temp->data;

  prev->next = temp->next;
  list->length--;
  free(temp);

  return data;
}

int SLL_search(SinglyLinkedList *list, void *target)
{
  SinglyLinkedListNode *curr = list->head;
  int pos = 0;

  while (curr)
  {
    if (list->compare(curr->data, target) == 0)
      return pos;

    curr = curr->next;
    pos++;
  }

  return ELEMENT_NOT_FOUND_ERROR;
}

void *SLL_get(SinglyLinkedList *list, int pos)
{
  if (list->length == 0)
    return INT(EMPTY_STRUCTURE_ERROR);

  if (pos < 0 || pos >= list->length)
    return INT(INVALID_POSITION_ERROR);

  SinglyLinkedListNode *curr = list->head;
  int curr_pos = 0;

  while (curr_pos < pos)
  {
    curr = curr->next;
    curr_pos++;
  }

  return curr->data;
}

void SLL_sort(SinglyLinkedList *list)
{
  SinglyLinkedListNode *slow = list->head;
  SinglyLinkedListNode *fast = NULL;
  SinglyLinkedListNode *min = NULL;

  while (slow)
  {
    min = slow;
    fast = slow->next;
    while (fast)
    {
      if (list->compare(fast->data, min->data) == -1)
      {
        min = fast;
      }
      fast = fast->next;
    }

    void *temp = min->data;
    min->data = slow->data;
    slow->data = temp;
    slow = slow->next;
  }
}

void SLL_reverse(SinglyLinkedList *list)
{
  SinglyLinkedListNode *curr = list->head;
  SinglyLinkedListNode *prev = NULL;
  SinglyLinkedListNode *next = NULL;

  while (curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  list->head = prev;
}

void SLL_print(SinglyLinkedList *list)
{
  SinglyLinkedListNode *curr = list->head;
  while (curr)
  {
    list->print(curr->data);
    curr = curr->next;

    if (curr)
      printf(" -> ");
  }
  printf("\n");
}

void SLL_free(SinglyLinkedList *list)
{
  SinglyLinkedListNode *curr = list->head;
  SinglyLinkedListNode *temp = list->head;

  while (curr)
  {
    temp = curr->next;

    if (list->free)
      list->free(curr->data);

    free(curr);
    curr = temp;
  }

  free(list);
}
