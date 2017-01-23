#include <unistd.h>

#include "utils.h"

int my_putchar(int fd, char c) { return write(fd, &c, 1); }
int my_putstr(int fd, const char *s) { return write(fd, s, my_strlen(s)); }

int my_strlen(const char *s)
{
  if (!s)
    return 0;

  int i = 0;

  while (*s++ != '\0')
    ++i;
  return i;
}

bool str_is_only_composed_of_digit(const char *s)
{
  while (*s != '\0')
    {
      if (*s > '9' || *s < '0')
	return false;
      ++s;
    }
  return true;
}

bool str_is_valid_number(const char *s)
{
  int length = my_strlen(s);

  return !(length == 0
	   || (*s == '-' && length == 1)
	   || (*s != '-' && !str_is_only_composed_of_digit(s))
	   || (*s == '-' && !str_is_only_composed_of_digit(++s)));
}
