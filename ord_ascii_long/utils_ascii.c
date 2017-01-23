#include "cast.h"
#include "utils_ascii.h"

bool is_higher_ascii(const void *ptr, const void *ptr2)
{
  const char *s = CAST_TO_CONST_STR(ptr);
  const char *s2 = CAST_TO_CONST_STR(ptr2);

  while (*s && *s2)
    {
      if (*s > *s2)
	return true;
      ++s;
      ++s2;
    }
  return false;
}
