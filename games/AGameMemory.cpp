/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** AGameMemory.cpp
*/

#include "AGameMemory.hpp"

std::vector<std::vector<int>> AGameMemory::getMap() const
{
    return _map;
}

bool AGameMemory::getIsGameOver() const
{
    return _game_over;
}

int AGameMemory::getScore() const
{
    return _score;
}

int AGameMemory::getSpeed() const
{
    return _speed;
}

void AGameMemory::setMap(std::vector<std::vector<int>> map)
{
    _map = map;
}

void AGameMemory::setIsGameOver(bool b)
{
    _game_over = b;
}

void AGameMemory::setScore(int addScore)
{
    _score += addScore;
}

void AGameMemory::setSpeed(bool sign)
{
    if (sign) {
        _speed++;
        if (_speed == 10)
            _speed = 9;
    }
    else if (!sign) {
        _speed--;
        if (_speed == 0)
            _speed = 1;
    }
}

void AGameMemory::handleSpeed()
{
    int i = _speed * 20000;
    usleep(190000 - i);
}
