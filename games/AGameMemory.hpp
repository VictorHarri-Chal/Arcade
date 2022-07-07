/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** AGameMemory.hpp
*/

#ifndef _GAME_MEMORY_HPP_
    #define _GAME_MEMORY_HPP_

    #include "IGame.hpp"

    class AGameMemory : public IGame {
        public:
            AGameMemory() = default;
            ~AGameMemory() = default;

            virtual void gameInit() = 0;
            virtual void gameScore(std::string playerName) = 0;

            virtual void gameMoveLeft(bool isAuto) = 0;
            virtual void gameMoveRight(bool isAuto) = 0;
            virtual void gameMoveUp(bool isAuto) = 0;
            virtual void gameMoveDown(bool isAuto) = 0;
            virtual void gameMoveDefault() = 0;

            std::vector<std::vector<int>> getMap() const;
            bool getIsGameOver() const;
            int getScore() const;
            int getSpeed() const;

            void setMap(std::vector<std::vector<int>> map);
            void setIsGameOver(bool b);
            void setScore(int addScore);
            void setSpeed(bool sign);

            void handleSpeed();
        protected:
            std::vector<std::vector<int>> _map;
            int _dir; // (cf. Enum dir)
            bool _game_over;
            int _score;
            int _speed = 5; // from 1 to 9, start at 5
    };

#endif
