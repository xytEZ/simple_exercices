#include <stdlib.h>

#include "cast.h"
#include "list.h"
#include "utils.h"
#include "utils_ascii.h"
#include "bubble_sort.h"
#include "ord_ascii_long_getters.h"
#include "ord_ascii_long.h"

static void free_sized_strs(t_sized_str **sized_strs)
{
  int i;

  for (i = 0; sized_strs[i]; ++i)
    {
      free(sized_strs[i]->str);
      free(sized_strs[i]);
    }
  free(sized_strs);
}

static char *strs_to_str_with_newline(const t_list *strs)
{
  t_node *tmp;
  char *str;
  const char *str_tmp;
  int size = 0;
  int i;
  
  for (tmp = strs->head; tmp; tmp = tmp->next)
    {
      size += my_strlen(CAST_TO_CONST_STR(tmp->elem));
      if (tmp->next)
	++size;
    }
  if (!(str = malloc(sizeof(*str) * (size + 1))))
    return NULL;
  i = 0;
  tmp = strs->head;
  while (tmp)
    {
      str_tmp = CAST_TO_CONST_STR(tmp->elem);
      while (*str_tmp)
	str[i++] = *str_tmp++;
      if (tmp->next)
	str[i++] = ' ';
      tmp = tmp->next;
    }
  str[size] = '\0';
  return str;
}

bool ord_ascii_long(size_t length, char **av, t_list *list)
{
  t_sized_str **sized_strs;
  t_list strs;
  char *tmp;
  int max_size;
  int i;

  if (length == 1)
    return (tmp = my_strdup(*av)) && push_back_list(list, tmp);
  else if (!(sized_strs = get_sized_strs_from_size(length, av)))
    return false;
  max_size = get_max_size_of_all_strs(CAST_TO_CONST_SIZED_STRS(sized_strs));
  i = 1;
  while (i <= max_size)
    {
      if (!get_all_str_is_equal_to_size(CAST_TO_CONST_SIZED_STRS(sized_strs), i, &strs))
	return false;
      if (strs.length > 0)
	{
	  bubble_sort(&strs, &is_higher_ascii);
	  if (!(tmp = strs_to_str_with_newline(&strs))
	      || !push_back_list(list, tmp))
	    return false;
	  free_list(&strs);
	}
      ++i;
    }
  free_sized_strs(sized_strs);
  return true;
}
