/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Nibbler.hpp
*/

#ifndef _NIBBLER_HPP_
    #define _NIBBLER_HPP

    #include "../IGame.hpp"
    #include "../AGameMemory.hpp"

    class Nibbler : public AGameMemory {
        public:
            Nibbler() = default;
            ~Nibbler() = default;

            void gameInit();
            void gameScore(std::string playerName);

            void gameMoveLeft(bool isAuto);
            void gameMoveRight(bool isAuto);
            void gameMoveUp(bool isAuto);
            void gameMoveDown(bool isAuto);
            void gameMoveDefault();

            void moveSnake();
            void handleFood();
            bool findFood();
        private:
            std::vector<std::pair<int, int>> _snk;
    };

#endif
