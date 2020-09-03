##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## script for compile .c
##

SRC	=	main.c	\
		my_exec.c	\
		mysh.c	\
		minishell1.c	\
		set_unsetenv.c	\
		function_checking.c	\
		path_handling.c	\
		fork.c	\
		my_cd.c	\
		my_cd_manager.c	\
		my_pwd.c	\
		my_cd_file.c	\
		lib/my/my_printf.c	\
		lib/my/my_putchar.c	\
		lib/my/init_function.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_octa.c	\
		lib/my/my_put_hexa_maj.c	\
		lib/my/my_put_hexa_x.c	\
		lib/my/my_put_bin.c	\
		lib/my/my_put_unsigned_int.c	\
		lib/my/print_modulo.c	\
		lib/my/prefixe_adress.c	\
		lib/my/my_put_adress.c	\
		lib/my/my_strlen.c	\
		lib/my/my_str_to_word_array.c	\
		lib/my/clean_str.c	\
		lib/my/clean_str_b.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_getnbr.c \
		lib/my/my_strcat.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strncat.c

OBJ	=	$(SRC:.c=.o)

INCLUDE =	lib/my/my.h

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -Wall -Wextra -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
