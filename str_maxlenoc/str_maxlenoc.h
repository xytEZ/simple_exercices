#ifndef STR_MAXLENOC_H_
# define STR_MAXLENOC_H_

# include <stdbool.h>

char *str_maxlenoc(int, const char **);
bool occurrence_is_found_in_any_str(int *, int, const char **, char);
bool occurrence_is_found_in_str(int *, const char *, char);
void reset_argv_pos(int, int *);
bool is_match(char, char);

#endif /* !STR_MAXLENOC_H_ */
