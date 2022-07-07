/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Ncurses.hpp
*/

#ifndef _NCURSES_HPP_
    #define _NCURSES_HPP_

    #include "../IGraphic.hpp"
    #include "../AGraphicMemory.hpp"
    #include <ncurses.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <cstring>

    class Ncurses : public AGraphicMemory {
        public:
            Ncurses() = default;
            ~Ncurses() = default;
            void graphInit();
            void graphDestroy();
            void graphDisplay(std::vector<std::vector<int>> map, int speed, int score);
            void graphMenuDisplay();
            void graphClear();
            void graphRefresh();
            void handleEvents();
            void transitionFrame(int i);

            void menuDrawGameChoice();
        private:
    };

#endif
