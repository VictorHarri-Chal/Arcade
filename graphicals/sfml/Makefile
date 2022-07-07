##
## EPITECH PROJECT, 2021
## B-OOP-400-NAN-4-1-arcade-victor.harri-chal
## File description:
## Makefile
##

SRC		=		Sfml.cpp \
				../AGraphicMemory.cpp \

NAME	=	arcade_sfml.so

CC 		= 	g++

RM 		= 	rm -f

all:	$(NAME)

$(NAME):
			$(CC) -c -fPIC $(SRC)
			$(CC) Sfml.o AGraphicMemory.o -shared -o $(NAME) -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window
			mv $(NAME) ../../lib/
			$(RM) Sfml.o AGraphicMemory.o

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) ../../lib/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
