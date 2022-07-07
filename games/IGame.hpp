/*
** EPITECH PROJECT, 2022
** 2eme annee
** File description:
** Arcade: IGame.hpp
*/

#ifndef IGAME_HPP
#define IGAME_HPP

#include "../graphicals/IGraphic.hpp"
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

enum Dir {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

enum Obj {
    SPACE,
    WALL,
    SNAKE,
    FOOD,
    PACMAN,
    PACFOOD,
    GHOST
};

class IGame {
    public:
        virtual ~IGame() = default;
        virtual void gameInit() = 0;
        virtual void gameScore(std::string playerName) = 0;

        virtual void gameMoveLeft(bool isAuto) = 0;
        virtual void gameMoveRight(bool isAuto) = 0;
        virtual void gameMoveUp(bool isAuto) = 0;
        virtual void gameMoveDown(bool isAuto) = 0;
        virtual void gameMoveDefault() = 0;

        virtual std::vector<std::vector<int>> getMap() const = 0;
        virtual bool getIsGameOver() const = 0;
        virtual int getScore() const = 0;
        virtual int getSpeed() const = 0;

        virtual void setMap(std::vector<std::vector<int>> map) = 0;
        virtual void setIsGameOver(bool b) = 0;
        virtual void setScore(int addScore) = 0;
        virtual void setSpeed(bool sign) = 0;

        virtual void handleSpeed() = 0;
};

#endif
