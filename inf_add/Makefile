CC	= cc

CFLAGS	+= -W -Wall -Wextra

RM	= rm -f

SRC	= main.c	\
	  add.c		\
	  char_list.c	\
	  utils.c

OBJ	= $(SRC:.c=.o)

NAME	= infin_add

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean	all
