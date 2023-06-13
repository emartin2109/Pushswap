##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	src/action_on_list/check_list.c		\
		src/action_on_list/command_list.c	\
		src/get.c							\
		src/main.c							\
		src/sort.c							\
		src/utils/utils_list.c				\
		src/utils/utils.c


OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

CFLAGS += #-W -Wall -Wextra -Wshadow -Wimplicit -Werror

CPPFLAGS += -I./include

all:	$(NAME)
PHONY	+= all

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
PHONY	+= clean

fclean:	clean
	rm -f $(NAME)

PHONY	+= fclean

re:	fclean all
PHONY	+= re

unit_tests:
PHONY	+= unit_tests

tests_run:
PHONY	+= tests_run

.PHONY:	$(PHONY)
