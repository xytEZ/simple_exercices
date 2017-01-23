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

  while (*s++)
    ++i;
  return i;
}
