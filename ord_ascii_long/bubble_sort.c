#include "utils.h"
#include "bubble_sort.h"

void bubble_sort(t_list *list, bool (*comparator)(const void *, const void *))
{
  t_node *tmp;
  t_node *tmp2;

  for (tmp = list->tail; tmp->prev; tmp = tmp->prev)
    {
      for (tmp2 = list->head; tmp2 != tmp; tmp2 = tmp2->next)
	{
	  if ((*comparator)(tmp2->elem, tmp2->next->elem))
	    my_swap(&tmp2->elem, &tmp2->next->elem);
	}
    }
}
