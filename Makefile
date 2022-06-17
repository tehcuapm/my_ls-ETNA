##
## ETNA PROJECT, 03/01/2022 by pauche_m & garo_n
## Makefile
## File description:
##      makefile of the project
##

SRC = ./src/main.c \
	./src/base_options_functions.c \
	./src/option_l.c \
	./src/option_r.c \
	./src/option_majL.c \
	./src/option_d.c \
	./src/option_a.c \
	./src/option_t.c \
	./src/option_f.c \
	./src/option_majA.c \
	./src/options_functions.c \
	./src/sort_files.c \
	./src/pools_functions.c \
	./src/base_ls.c \
	./src/dir_functions.c \
	./src/my_ls.c \
	./src/option_majR.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall  -Wextra -Werror -ggdb3
NAME = my_ls

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:     $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re