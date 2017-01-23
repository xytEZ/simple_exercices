#include "utils.h"
#include "add.h"

bool check_args(const char *nb, const char *nb2)
{
  return str_is_valid_number(nb) && str_is_valid_number(nb2);
}

int main(int ac, char **av)
{
  int ret_value;

  if (ac != 3)
    {
      my_putstr(2, "Usage : ");
      my_putstr(2, *av);
      my_putstr(2, " [arg1] [arg2]");
      ret_value = 0;
    }
  else if (!check_args(av[1], av[2]))
    {
      my_putstr(2, "One of the numbers is invalid.");
      ret_value = 0;
    }
  else
    {
      t_char_list *result = inf_add(av[1], av[2]);

      if (!result)
	{
	  my_putstr(2, "Error.");
	  ret_value = 0;
	}
      else
	{
	  print_char_list(result, 1);
	  free_char_list(result);
	  ret_value = 1;
	}
    }
  my_putstr(1, "\n");
  return ret_value;
}
