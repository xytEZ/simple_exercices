#include <stdlib.h>

#include "converter.h"
#include "utils.h"
#include "str_maxlenoc.h"

int main(int ac, char **av)
{
  if (ac < 3)
    {
      my_putstr(2, "\n");
      return 0;
    }

  char *s = str_maxlenoc(ac - 1, CAST_TO_CHAR_DOUBLE_CONST_ARRAY(av + 1));

  if (s)
    my_putstr(1, s);
  my_putstr(1, "\n");
  free(s);
  return 1;
}
