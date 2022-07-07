/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Memory.hpp
*/

#ifndef _GRAPHIC_MEMORY_HPP_
    #define _GRAPHIC_MEMORY_HPP_

    #include <iostream>
    #include "IGraphic.hpp"

    class AGraphicMemory : public IGraphic {
        public:
            AGraphicMemory() = default;
            ~AGraphicMemory() = default;

            virtual void graphInit() = 0;
            virtual void graphDestroy() = 0;
            virtual void graphDisplay(std::vector<std::vector<int>> map, int speed, int score) = 0;
            virtual void graphMenuDisplay() = 0;
            virtual void graphClear() = 0;
            virtual void graphRefresh() = 0;
            virtual void handleEvents() = 0;
            virtual void transitionFrame(int i) = 0;

            std::string getKeyPressed() const;
            std::string getPlayerName() const;
            bool getIsNameChoosed() const;
            bool getInMenu() const;
            int getGameChoice() const;
            int getCurrentLib() const;

            void setKey(std::string key);
            void setPlayerName(std::string letter);
            void setBackspacePlayerName();
            void setIsNameChoosed(bool i);
            void setInMenu(bool b);
            void setGameChoice(int i);
            void setCurrentLib(int i);


        protected:
            bool _is_name_choosed = false;
            std::string _player_name;
            std::string _key;
            int _game_choice = 0; // actual game choice, 0 if Nibbler, 1 if Pacman
            bool _in_menu = true; // true if the user is in the menu, false if in game
            int _current_lib; // 0 = ncurses, 1 = sfml, 2 = sdl
            std::string _welcomeText = "Welcome to the Arcade!";
            std::string _promptText = "Please type your name (only letters from 'a' to 'z' are allowed, press Return to validate): ";
            std::string _chooseText = "Choose your game:";
            std::string _validText = "VALIDATED!";
            std::string _pacmanText = "Pacman";
            std::string _nibblerText = "Nibbler";
            std::string _startText = "Starting game in ";
            std::string _restartText = "Restart game in ";
            std::string _secondsText = " seconds ...";
            std::string _scoreboardText = "Your score will be in the scoreboard in 5 seconds!";
    };

#endif
