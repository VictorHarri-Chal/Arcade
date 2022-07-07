/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Pacman.hpp
*/

#ifndef _PACMAN_HPP
    #define _PACMAN_HPP_

    #include "../IGame.hpp"
    #include "../AGameMemory.hpp"

    class Pacman : public AGameMemory {
        public:
            Pacman() = default;
            ~Pacman() = default;

            void gameInit();
            void gameScore(std::string playerName);

            void gameMoveLeft(bool isAuto);
            void gameMoveRight(bool isAuto);
            void gameMoveUp(bool isAuto);
            void gameMoveDown(bool isAuto);
            void gameMoveDefault();

            void ghostMouvement();
            void changeDir();
            void countScore();
            bool checkWin();

        private:
            std::pair<int, int> _pacman;
            std::pair<int, int> _ghost1;
            int _ghostDir; // 0 = left, 1 = up, 2 == right, 3 == down
    };
#endif
