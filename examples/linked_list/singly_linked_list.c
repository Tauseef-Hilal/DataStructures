#include <stdio.h>
#include "../../include/linked_list/singly_linked_list.h"

int main()
{
  SinglyLinkedList *list = SLL_new_list();
  SLL_insert(list, 0, 1);
  SLL_insert(list, 1, 2);
  SLL_insert(list, 2, 3);
  SLL_print(list);
  SLL_free(list);
  return 0;
}