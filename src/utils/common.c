#include <stdio.h>
#include <stdlib.h>
#include "../include/utils/errors.h";

void *alloc(size_t size)
{
  void *ptr = malloc(size);
  if (!ptr)
  {
    fprintf(stderr, "Error allocating memory!");
    exit(MEMORY_ALLOCATION_ERROR);
  }

  return ptr;
}