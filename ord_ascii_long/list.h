#ifndef LIST_H_
# define LIST_H_

# include <stdbool.h>
# include <stddef.h>

typedef struct s_node t_node;
typedef struct s_list t_list;

struct s_node
{
  void *elem;
  t_node *next;
  t_node *prev;
};

struct s_list
{
  size_t length;
  t_node *head;
  t_node *tail;
};

t_list init_list();
bool push_back_list(t_list *, void *);
void free_list(t_list *);
bool is_empty_list(const t_list *);
void display_list(const t_list *, void (*)(void *));

#endif /*! LIST_H_ */
