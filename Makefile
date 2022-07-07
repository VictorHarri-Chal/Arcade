##
## EPITECH PROJECT, 2021
## B-OOP-400-NAN-4-1-arcade-victor.harri-chal
## File description:
## Makefile
##

all:	core games graphicals

core:
			make -C core/

games:
			make -C games/nibbler/
			make -C games/pacman/

nibbler:
			make -C games/nibbler/

pacman:
			make -C games/pacman/

graphicals:
			make -C graphicals/ncurses/
			make -C graphicals/sdl/
			make -C graphicals/sfml/

ncurses:
			make -C graphicals/ncurses/

sdl:
			make -C graphicals/sdl/

sfml:
			make -C graphicals/sfml/

clean:
			make clean -C core/
			make clean -C games/nibbler/
			make clean -C games/pacman/
			make clean -C graphicals/ncurses/
			make clean -C graphicals/sdl/
			make clean -C graphicals/sfml/

fclean:
			make fclean -C core/
			make fclean -C games/nibbler
			make fclean -C games/pacman
			make fclean -C graphicals/ncurses/
			make fclean -C graphicals/sdl/
			make fclean -C graphicals/sfml/

re:	fclean all

.PHONY: all core games nibbler pacman graphicals ncurses sdl sfml clean fclean re
