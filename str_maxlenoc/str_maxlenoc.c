#include "list.h"
#include "converter.h"
#include "str_maxlenoc.h"

bool is_match(char c, char c2) { return !(c ^ c2); }

void reset_argv_pos(int count, int *argv_pos)
{
  int i = 0;

  while (i < count)
    argv_pos[i++] = 0;
}

bool occurrence_is_found_in_str(int *argv_pos, const char *s, char c)
{
  while (s[*argv_pos])
    {
      if (is_match(s[*argv_pos], c))
	{
	  ++(*argv_pos);
	  return true;
	}
      ++(*argv_pos);
    }
  return false;
}

bool occurrence_is_found_in_any_str(int *argv_pos, int ac, const char **av, char c)
{
  int i = 0;

  while (i < ac)
    {
      if (!occurrence_is_found_in_str(argv_pos++, *av++, c))
	return false;
      ++i;
    }
  return true;
}

char *str_maxlenoc(int ac, const char **av)
{
  t_list list = init_list();
  int argv_pos[ac - 1];
  char *s = NULL;
  char *c = NULL;

  reset_argv_pos(ac - 1, argv_pos);
  while (**av)
    {
      if (occurrence_is_found_in_any_str(argv_pos, ac - 1, av + 1, **av))
	{
	  c = char_to_char_ptr(**av);
	  if (!c || !push_back_list(&list, c))
	    return NULL;
	}
      else
	{
	  if (!is_empty_list(&list))
	    break;
	  else
	    reset_argv_pos(ac - 1, argv_pos);
	}
      ++*av;
    }
  s = list_to_str(&list);
  free_list(&list);
  return s;
}
