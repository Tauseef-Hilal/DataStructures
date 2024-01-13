#include <stdio.h>
#include "../../include/utils/types.h"
#include "../../include/linked_list/singly_linked_list.h"

void print_f(void *data)
{
  printf("%d", *((short *)data));
}

int compare(void *a, void *b)
{
  short x = *((short *)a);
  short y = *((short *)b);

  if (x < y)
    return -1;
  else if (x > y)
    return 1;
  else
    return 0;
}

int main()
{
  SinglyLinkedList *list = SLL_new_list(print_f, compare, NULL);
  SLL_append(list, SHORT(3));
  SLL_append(list, SHORT(2));
  SLL_append(list, SHORT(1));
  SLL_print(list);
  SLL_sort(list);
  SLL_print(list);
  SLL_reverse(list);
  SLL_print(list);
  SLL_free(list);

  return 0;
}