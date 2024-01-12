#ifndef TYPES_H
#define TYPES_H

#define INT(v) \
  &(int) { v }
#define CHAR(v) \
  &(char) { v }
#define FLOAT(v) \
  &(float) { v }
#define DOUBLE(v) \
  &(double) { v }

#define SHORT(v) \
  &(short) { v }
#define LONG(v) \
  &(long) { v }
#define UINT(v) \
  &(unsigned int) { v }
#define ULONG(v) \
  &(unsigned long) { v }
#define ULONG_LONG(v) \
  &(unsigned long long) { v }

#endif