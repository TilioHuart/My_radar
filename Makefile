##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_radar

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS = -W -Wall -Wextra

CPPFLAGS = -I./include/

CC = gcc -g

DIRLIB = lib/my/

LIB = -L./lib/my/

NAMELIB = -lmy

all: $(NAME)

$(NAME): compile $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(CSFML) $(LIB) $(NAMELIB)

clean:	lclean
	@rm -f $(OBJ)
	@find . -name "*~" -delete

fclean: clean lfclean
	@rm -f $(NAME)

lclean:
	@make clean -C $(DIRLIB)

re: fclean all

lfclean:
	@make fclean -C $(DIRLIB)

compile:
	@make -C $(DIRLIB)

.PHONY:-all clean fclean re compile
