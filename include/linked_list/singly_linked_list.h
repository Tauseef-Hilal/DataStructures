#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct SLL_node
{
  int data;
  struct SLL_node *next;
} SinglyLinkedListNode;

typedef struct SLL
{
  unsigned int length;
  SinglyLinkedListNode *head;
} SinglyLinkedList;

SinglyLinkedList *SLL_new_list();
SinglyLinkedListNode *SLL_new_node(int data);
int SLL_insert(SinglyLinkedList *list, int pos, int data);
int SLL_pop(SinglyLinkedList *list, int pos);
int SLL_search(SinglyLinkedList *list, int target);
int SLL_get(SinglyLinkedList *list, int pos);
void SLL_print(SinglyLinkedList *list);
void SLL_free(SinglyLinkedList *list);

#endif
