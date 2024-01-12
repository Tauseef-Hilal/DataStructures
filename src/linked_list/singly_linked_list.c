#include <stdio.h>
#include <stdlib.h>
#include "../../include/utils/common.h"
#include "../../include/utils/errors.h"
#include "../../include/linked_list/singly_linked_list.h"

SinglyLinkedList *SLL_new_list()
{
  SinglyLinkedList *list = alloc(sizeof(SinglyLinkedList));
  list->length = 0;
  list->head = NULL;
  return list;
}

SinglyLinkedListNode *SLL_new_node(int data)
{
  SinglyLinkedListNode *node = alloc(sizeof(SinglyLinkedListNode));
  node->data = data;
  node->next = NULL;
  return node;
}

int SLL_insert(SinglyLinkedList *list, int pos, int data)
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

int SLL_pop(SinglyLinkedList *list, int pos)
{
  if (list->length == 0)
    return EMPTY_STRUCTURE_ERROR;

  if (pos < 0 || pos > list->length - 1)
  {
    return INVALID_POSITION_ERROR;
  }

  if (pos == 0)
  {
    SinglyLinkedListNode *temp = list->head;
    int data = temp->data;

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
      return INVALID_POSITION_ERROR;
    }
  }

  SinglyLinkedListNode *temp = prev->next;
  int data = temp->data;

  prev->next = temp->next;
  list->length--;
  free(temp);

  return data;
}

int SLL_search(SinglyLinkedList *list, int target)
{
  SinglyLinkedListNode *curr = list->head;
  int pos = 0;

  while (curr)
  {
    if (curr->data == target)
      return pos;

    curr = curr->next;
    pos++;
  }

  return ELEMENT_NOT_FOUND_ERROR;
}

int SLL_get(SinglyLinkedList *list, int pos)
{
  if (pos < 0 || pos >= list->length)
    return INVALID_POSITION_ERROR;

  SinglyLinkedListNode *curr = list->head;
  int curr_pos = 0;

  while (curr_pos < pos)
  {
    curr = curr->next;
    curr_pos++;
  }

  return curr->data;
}

void SLL_print(SinglyLinkedList *list)
{
  SinglyLinkedListNode *curr = list->head;
  while (curr)
  {
    printf("%d", curr->data);
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
    free(curr);
    curr = temp;
  }

  free(list);
}
