##
## EPITECH PROJECT, 2021
## B-OOP-400-NAN-4-1-arcade-victor.harri-chal
## File description:
## Makefile
##

SRC		=		Sdl.cpp \
				../AGraphicMemory.cpp \

NAME	=	arcade_sdl2.so

CC 		= 	g++

RM 		= 	rm -f

all:	$(NAME)

$(NAME):
			$(CC) -c -fPIC $(SRC)
			$(CC) Sdl.o AGraphicMemory.o -shared -o $(NAME) -lSDL2main -lSDL2_ttf -lSDL2
			mv $(NAME) ../../lib/
			$(RM) Sdl.o AGraphicMemory.o

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) ../../lib/$(NAME)

re:	fclean all

.PHONY: all clean fclean re
