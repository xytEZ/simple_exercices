#include <stdlib.h>

#include "list.h"

t_list init_list()
{
  t_list list;

  list.length = 0;
  list.head = NULL;
  list.tail = NULL;
  return list;
}

bool push_back_list(t_list *list, void *elem)
{
  t_node *new = malloc(sizeof(*new));

  if (!new)
    return false;
  new->elem = elem;
  new->next = NULL;
  if (!list->head)
    list->head = new;
  else
    list->tail->next = new;
  list->tail = new;
  ++list->length;
  return true;
}

void free_list(t_list *list)
{
  t_node *tmp = list->head;
  t_node *tmp2;

  while (tmp)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      free(tmp2->elem);
      free(tmp2);
    }
  list->length = 0;
  list->head = NULL;
  list->tail = NULL;
}

bool is_empty_list(const t_list *list) { return !(list->length ^ 0); }
