#include <stdlib.h>

#include "utils.h"
#include "char_list.h"

t_char_list *push_front_in_char_list(t_char_list *list, char c)
{
  t_char_list *new;

  if (!(new = malloc(sizeof(*new))))
    return NULL;
  new->c = c;
  new->next = list;
  return new;
}

void print_char_list(t_char_list *list, int fd)
{
  t_char_list *tmp = list;

  while (tmp != NULL)
    {
      my_putchar(fd, tmp->c);
      tmp = tmp->next;
    }
}

void free_char_list(t_char_list *list)
{
  t_char_list *tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}
