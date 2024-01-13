#include <stdio.h>
#include <stdlib.h>

#include "../../include/utils/types.h"
#include "../../include/utils/common.h"
#include "../../include/linked_list/singly_linked_list.h"

struct student
{
  char *name;
  int roll_no;
};

void print_f(void *data);
int compare(void *a, void *b);
void free_f(void *data);

int main()
{
  SinglyLinkedList *list = SLL_new_list(print_f, compare, free_f);

  struct student *s1 = alloc(sizeof(struct student));
  s1->name = "Tauseef";
  s1->roll_no = 401;

  struct student *s2 = alloc(sizeof(struct student));
  s2->name = "Suhaib";
  s2->roll_no = 402;

  struct student *s3 = alloc(sizeof(struct student));
  s3->name = "Aqib";
  s3->roll_no = 403;

  SLL_insert(list, 0, s3);
  SLL_insert(list, 1, s2);
  SLL_insert(list, 2, s1);
  SLL_print(list);
  SLL_sort(list);
  SLL_print(list);
  SLL_free(list);

  return 0;
}

void print_f(void *data)
{
  printf("%s", ((struct student *)data)->name);
}

int compare(void *a, void *b)
{
  int x = ((struct student *)a)->roll_no;
  int y = ((struct student *)b)->roll_no;

  if (x < y)
    return -1;
  else if (x > y)
    return 1;
  else
    return 0;
}

void free_f(void *data)
{
  free(data);
}