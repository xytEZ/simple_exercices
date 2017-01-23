#include <stdio.h>
#include <stdlib.h>

#include "cast.h"
#include "utils.h"
#include "list.h"
#include "ord_ascii_long.h"

void display_string(void *elem)
{
  my_putstr(1, CAST_TO_CONST_STR(elem));
  my_putchar(1, '\n');
}

int main(int ac, char **av)
{ 
  if (ac == 1)
    {
      my_putchar(2, '\n');
      return 0;
    }

  t_list list = init_list();
  
  if (!ord_ascii_long(ac - 1, ++av, &list))
    my_putchar(2, '\n');
  else
    {
      display_list(&list, &display_string);
      free_list(&list);
    }
  return 1;
}
