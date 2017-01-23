#include <stdlib.h>

#include "cast.h"
#include "utils.h"
#include "ord_ascii_long_getters.h"

bool get_all_str_is_equal_to_size(const t_sized_str **sized_strs,
				  size_t str_size,
				  t_list *strs)
{
  char *s;

  *strs = init_list();
  while (*sized_strs)
    {
      if ((*sized_strs)->length == str_size
	  && ((!(s = my_strdup((*sized_strs)->str)))
	      || !push_back_list(strs, s)))
	return false;
      ++sized_strs;
    }
  return true;
}

int get_max_size_of_all_strs(const t_sized_str **sized_strs)
{
  int max = 0;

  while (*sized_strs)
    {
      if (max < CAST_TO_INT((*sized_strs)->length))
	max = (*sized_strs)->length;
      ++sized_strs;
    }
  return max;
}

static t_sized_str *get_sized_str(const char *s, size_t length)
{
  t_sized_str *sized_str = malloc(sizeof(*sized_str));

  if (!sized_str || !(sized_str->str = my_strdup(s)))
    return NULL;
  sized_str->length = length;
  return sized_str;
}

t_sized_str **get_sized_strs_from_size(size_t length, char **av)
{
  t_sized_str **sized_strs;
  int i;

  if (!(sized_strs = malloc((length + 1) * sizeof(*sized_strs))))
    return NULL;
  for (i = 0; *av; ++i)
    {
      if (!(sized_strs[i] = get_sized_str(*av, my_strlen(*av))))
	return NULL;
      ++av;
    }
  sized_strs[length] = NULL;
  return sized_strs;
}
