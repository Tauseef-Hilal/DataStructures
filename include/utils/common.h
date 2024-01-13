#ifndef COMMON_H
#define COMMON_H

typedef void (*PrintFunction)(void *data);
typedef int (*CompareFunction)(void *a, void *b);
typedef void (*FreeFunction)(void *);

void *alloc(size_t size);

#endif