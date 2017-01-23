#ifndef BUBBLE_SORT_H_
# define BUBBLE_SORT_H_

# include <stdbool.h>

# include "list.h"

void bubble_sort(t_list *, bool (*)(const void *, const void *));

#endif /* !BUBBLE_SORT_H_ */
