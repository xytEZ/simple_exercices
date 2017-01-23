#ifndef ADD_H_
# define ADD_H_

# include "char_list.h"

typedef struct s_remain
{
  char ret;
  int sign;
}	       t_remain;

char add(char, char);
int insert_last_remain(t_char_list **, t_remain *);
int insert_new_digit_to_result(t_char_list **, t_remain *, char);
int try_to_add_digit_to_result(t_char_list **, t_remain *, const char *, int *);

int add_two_digits_to_result(t_char_list **,
			       t_remain *,
			       const char *,
			       const char *,
			       int *,
			       int *);

t_char_list *inf_add(const char *, const char *);

#endif /* !ADD_H_ */
