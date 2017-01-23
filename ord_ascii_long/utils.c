#include <stdlib.h>
#include <unistd.h>

#include "utils.h"

int my_putchar(int fd, char c)
{
  return write(fd, &c, 1);
}

int my_putstr(int fd, const char *s)
{
  return write(fd, s, my_strlen(s));
}

size_t my_strlen(const char *s)
{
  int i = 0;

  for (i = 0; *s++; ++i);
  return i;
}

void my_swap(void **ptr, void **ptr2)
{
  void *tmp = *ptr;

  *ptr = *ptr2;
  *ptr2 = tmp;
}

char *my_strdup(const char *s)
{
  if (!s)
    return NULL;

  char *copy = malloc(sizeof(*copy) * (my_strlen(s) + 1));
  int i;

  if (!copy)
    return NULL;
  i = 0;
  while (*s)
    copy[i++] = *s++;
  copy[i] = '\0';
  return copy;
}
