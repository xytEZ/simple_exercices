#ifndef CHAR_LIST_H_
# define CHAR_LIST_H_

typedef struct s_char_list t_char_list;

struct s_char_list
{
  char c;
  t_char_list *next;
};

t_char_list *push_front_in_char_list(t_char_list *, char);
void print_char_list(t_char_list *, int);
void free_char_list(t_char_list *);

#endif /* !CHAR_LIST_H_ */
