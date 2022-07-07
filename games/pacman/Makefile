##
## EPITECH PROJECT, 2021
## B-OOP-400-NAN-4-1-arcade-victor.harri-chal
## File description:
## Makefile
##

SRC		=		Pacman.cpp \
				../AGameMemory.cpp \
			
NAME	=	arcade_pacman.so

CC 		= 	g++

RM 		= 	rm -f

all:	$(NAME)

$(NAME):
			$(CC) -c -fPIC $(SRC)
			$(CC) Pacman.o AGameMemory.o -shared -o $(NAME)
			mv $(NAME) ../../lib/
			$(RM) Pacman.o AGameMemory.o

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) ../../lib/$(NAME)

re:	fclean all

.PHONY: all clean fclean re