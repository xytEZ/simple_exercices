#include <stdlib.h>

#include "utils.h"
#include "add.h"

char add(char c, char c2) { return c + c2; }

int insert_last_remain(t_char_list **result, t_remain *remain)
{
  if (remain->ret != 0 && remain->ret < 0)
    remain->ret *= -1;
  return ((remain->ret != 0 && !(*result = push_front_in_char_list(*result, remain->ret + 48)))
	  || (remain->sign == 1 && !(*result = push_front_in_char_list(*result, '-')))) ?
    -1 : 1;
}

int insert_new_digit_to_result(t_char_list **result, t_remain *remain, char c)
{
  remain->sign = (c < 0) ? 1 : 0;
  if (c / 10 > 0 || c / 10 < 0)
    {
      remain->ret = c / 10;
      c %= 10;
    }
  else if (c < 0)
    {
      if (c / 10 < 0)
	remain->ret = c / 10;
      c %= 10;
    }
  return !(*result = push_front_in_char_list(*result, (c > 0) ? c + 48 : (c - 48) * -1)) ?
    -1 : 1;
}

int try_to_add_digit_to_result(t_char_list **result,
			       t_remain *remain,
			       const char *nb,
			       int *nb_pos)
{
  if (*nb_pos < 0 || nb[*nb_pos] == '-');
  else
    {
      char digit_result;

      digit_result = nb[*nb_pos];
      if (remain->sign == 1)
	digit_result -= remain->ret;
      else
	digit_result += remain->ret;
      digit_result -= 48;
      if (insert_new_digit_to_result(result, remain, digit_result) == -1)
	return -1;
    };
  --(*nb_pos);
  return 1;
}

int add_two_digits_to_result(t_char_list **result,
			     t_remain *remain,
			     const char *nb,
			     const char *nb2,
			     int *nb_pos,
			     int *nb2_pos)
{
  char digit_result;

  if (*nb == '-' && *nb2 == '-')
    digit_result = add((nb[*nb_pos] - 48) * -1, (nb2[*nb2_pos] - 48) * -1);
  else if (*nb == '-')
    digit_result = add((nb[*nb_pos] - 48) * -1, (nb2[*nb2_pos] - 48));
  else if (*nb2 == '-')
    digit_result = add((nb[*nb_pos] - 48), (nb2[*nb2_pos] - 48) * -1);
  else
    digit_result = add((nb[*nb_pos] - 48), (nb2[*nb2_pos] - 48));
  if (remain->sign == 1)
    digit_result -= remain->ret;
  else
    digit_result += remain->ret;
  --(*nb_pos);
  --(*nb2_pos);
  return insert_new_digit_to_result(result, remain, digit_result) == -1 ?
    -1 : 1;
}

t_char_list *inf_add(const char *nb, const char *nb2)
{
  t_remain remain = { 0, -1 };
  t_char_list *result = NULL;
  int nb_pos = my_strlen(nb) - 1;
  int nb2_pos = my_strlen(nb2) - 1;

  while (nb_pos >= 0 || nb2_pos >= 0)
    {
      if (nb_pos < 0 || nb[nb_pos] == '-')
	{
	  if (try_to_add_digit_to_result(&result, &remain, nb2, &nb2_pos) == -1)
	    return NULL;
	  --nb_pos;
	}
      else if (nb2_pos < 0 || nb2[nb2_pos] == '-')
	{
	  if (try_to_add_digit_to_result(&result, &remain, nb, &nb_pos) == -1)
	    return NULL;
	  --nb2_pos;
	}
      else
	if (add_two_digits_to_result(&result, &remain, nb, nb2, &nb_pos, &nb2_pos)
	    == -1)
	  return NULL;
    }
  if (insert_last_remain(&result, &remain) == -1)
    return NULL;
  return result;
}
