#ifndef CONVERTER_H_
# define CONVERTER_H_

# define CAST_TO_INT(x) (int)x
# define CAST_TO_CHAR_DOUBLE_CONST_ARRAY(x) (const char **)x

# include "list.h"

char char_ptr_to_char(const char *);
char *char_to_char_ptr(char);
char *list_to_str(t_list *);

#endif /* !CONVERTER_H_ */
