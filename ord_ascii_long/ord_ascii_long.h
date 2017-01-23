#ifndef ORD_ASCII_LONG_H_
# define ORD_ASCII_LONG_H_

# define CAST_TO_CONST_SIZED_STRS(x) (const t_sized_str **)x

# include <stddef.h>
# include <stdbool.h>

# include "list.h"

typedef struct s_sized_str t_sized_str;

struct s_sized_str
{
  char *str;
  size_t length;
};

bool ord_ascii_long(size_t, char **, t_list *);

#endif /* !ORD_ASCII_LONG_H_ */
