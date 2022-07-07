##
## EPITECH PROJECT, 2021
## B-OOP-400-NAN-4-1-arcade-victor.harri-chal
## File description:
## Makefile
##

SRC		=		src/Main.cpp							\
				src/Core.cpp							\
				src/Exceptions/GenericExceptions.cpp 	\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade

CC 		= 	g++

RM 		= 	rm -f

FLAGS	=	-Wall -Wextra -Werror -ldl -fno-gnu-unique

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ)
			mv $(NAME) ../
			$(RM) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re
