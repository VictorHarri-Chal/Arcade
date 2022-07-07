##
## EPITECH PROJECT, 2021
## B-OOP-400-NAN-4-1-arcade-victor.harri-chal
## File description:
## Makefile
##

SRC		=		Ncurses.cpp \
				../AGraphicMemory.cpp \

NAME	=	arcade_ncurses.so

CC 		= 	g++

RM 		= 	rm -f

all:	$(NAME)

$(NAME):
			$(CC) -c -fPIC $(SRC)
			$(CC) Ncurses.o AGraphicMemory.o -shared -o $(NAME) -lncurses
			mv $(NAME) ../../lib/
			$(RM) Ncurses.o AGraphicMemory.o

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) ../../lib/$(NAME)

re:	fclean all

.PHONY: all clean fclean re