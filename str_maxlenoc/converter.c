#include <stdlib.h>

#include "converter.h"

char char_ptr_to_char(const char *s) { return *s; }

char *char_to_char_ptr(char c)
{
  char *s = malloc(sizeof(*s));

  if (!s)
    return NULL;
  *s = c;
  return s;
}

char *list_to_str(t_list *list)
{
  if (!list->length)
    return NULL;

  char *s;
  t_node *tmp;
  int i;

  if (!(s = malloc((list->length + 1) * sizeof(*s))))
    return NULL;
  i = 0;
  tmp = list->head;
  while (i < CAST_TO_INT(list->length))
    {
      s[i++] = char_ptr_to_char(tmp->elem);
      tmp = tmp->next;
    }
  s[i] = '\0';
  return s;
}
