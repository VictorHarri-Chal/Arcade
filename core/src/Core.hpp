/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Core.hpp
*/

#ifndef CORE_HEADER
    #define CORE_HEADER
    #include <stdio.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>
    #include <iostream>
    #include <chrono>
    #include <thread>
    #include <string>
    #include <cstring>
    #include <dlfcn.h>
    #include <unistd.h>
    #include <vector>
    #include "../../games/IGame.hpp"
    #include "../../games/AGameMemory.hpp"
    #include "../../graphicals/IGraphic.hpp"
    #include "../../graphicals/AGraphicMemory.hpp"
    #include "Exceptions/GenericExceptions.hpp"

    class Core {
        public:
            // Ctor & Dtor
            Core(std::string glib);
            ~Core() = default;

            // Members Functions
            IGraphic *loadGraphicLib(std::string glib);
            IGame *loadGameLib(std::string glib);
            void coreLoop();
            void initName(void);
            void inMenu(void);
            void inGame(void);
            void changeGraphicLib(void);
            void changeGameLib(void);
            void killArcade(void);
            void killArcadeInGame(void);

        private:
            IGame *_game;
            IGraphic *_graphic;
            void *_handle_game = nullptr;
            void *_handle_graphic = nullptr;
            std::string _game_list[2];
            std::string _graphic_list[3];
    };

#endif
