##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Write a Makefile that compiles your libmy.
##

SRC = 		my_compute_square_root.c	\
		my_isneg.c	\
		my_putstr.c	\
		my_show_word_array.c	\
		my_strcmp.c	\
		my_str_isnum.c	\
		my_strlowcase.c	\
		my_strstr.c \
		my_find_prime_sup.c	\
		my_is_prime.c	\
		my_revstr.c	\
		my_sort_int_array.c	\
		my_strcpy.c \
		my_str_isprintable.c	\
		my_strncat.c	\
		my_strupcase.c	\
		my_getnbr.c	\
		my_putchar.c	\
		my_showmem.c	\
		my_strcapitalize.c	\
		my_str_isalpha.c	\
		my_str_isupper.c	\
		my_strncmp.c	\
		my_swap.c	\
		my_compute_power_rec.c	\
		my_put_nbr.c	\
		my_showstr.c	\
		my_strcat.c	\
		my_str_islower.c	\
		my_strlen.c	\
		my_strncpy.c	\
		my_isnum.c	\
		my_getoperator.c	\
		my_isoperator.c	\
		my_putnbr.c	\
		my_isalpha.c	\
		my_str_isnum.c	\
		function1.c	\
		function2.c	\
		function3.c	\
		my_printf.c	\
		my_put_nbr_oct.c	\
		my_put_nbr_unsigned.c	\
		my_putstr.c	\
		my_put_nbr_hexa_min.c	\
		my_put_nbr_hexa_maj.c	\
		my_put_nbr_float.c	\
		my_put_nbr_scientific.c	\
		my_put_nbr_scientific_maj.c	\
		structures.c	\
		void.c	\
		my_str_to_word_array.c	\
		my_strdup.c

CPPFLAGS	=	-I.

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rm -f *~

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
