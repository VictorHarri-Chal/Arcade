/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"
#include <iostream>

extern "C" IGame *entryPoint(bool b)
{
    if (b == true)
        return nullptr;
    IGame *tmp(new Pacman());
    return tmp;
}

void Pacman::gameInit()
{
    std::srand(std::time(nullptr));
    int x = 0;
    std::ifstream filepath("./games/pacman/map.txt");

    for (int cols = 0; cols < 25; cols++) {
        std::vector<int> tmp;
        for (int rows = 0; rows < 19; rows++)
            tmp.push_back(0);
        _map.push_back(tmp);
    }
    for (std::string line; std::getline(filepath, line); x++) {
        for (int y = 0; y < 19; y++) {
            if (line[y] == ' ')
                _map[x][y] = SPACE;
            if (line[y] == '#')
                _map[x][y] = WALL;
            if (line[y] == 'x')
                _map[x][y] = FOOD;
            if (line[y] == 'C')
                _map[x][y] = PACMAN;
            if (line[y] == '.')
                _map[x][y] = PACFOOD;
            if (line[y] == 'G')
                _map[x][y] = GHOST;
        }
    }
    _dir = RIGHT;
    _ghostDir = UP;
    _pacman = std::make_pair(19, 9);
    _ghost1 = std::make_pair(10, 9);
}

void Pacman::ghostMouvement()
{
    if (_ghostDir == LEFT) {
        if (_map[_ghost1.first][_ghost1.second - 1] != WALL) {
            int i = _map[_ghost1.first][_ghost1.second - 1];
            _map[_ghost1.first][_ghost1.second - 1] = GHOST;
            _map[_ghost1.first][_ghost1.second] = i;
            _ghost1.second--;
        }
    }
    if (_ghostDir == UP) {
        if (_map[_ghost1.first - 1][_ghost1.second] != WALL) {
            int i = _map[_ghost1.first - 1][_ghost1.second];
            _map[_ghost1.first - 1][_ghost1.second] = GHOST;
            _map[_ghost1.first][_ghost1.second] = i;
            _ghost1.first--;
        }
    }
    if (_ghostDir == RIGHT) {
        if (_map[_ghost1.first][_ghost1.second + 1] != WALL) {
            int i = _map[_ghost1.first][_ghost1.second + 1];
            _map[_ghost1.first][_ghost1.second + 1] = GHOST;
            _map[_ghost1.first][_ghost1.second] = i;
            _ghost1.second++;
        }
    }
    if (_ghostDir == DOWN) {
        if (_map[_ghost1.first + 1][_ghost1.second] != WALL) {
            int i = _map[_ghost1.first + 1][_ghost1.second];
            _map[_ghost1.first + 1][_ghost1.second] = GHOST;
            _map[_ghost1.first][_ghost1.second] = i;
            _ghost1.first++;
        }
    }
    changeDir();
}

void Pacman::changeDir()
{
    int i = std::rand() % 4;
    if ((_ghostDir == LEFT && i == RIGHT) || (_ghostDir == RIGHT && i == LEFT) || (_ghostDir == UP && i == DOWN) || (_ghostDir == DOWN && i == UP))
        changeDir();
    else
        _ghostDir = i;
}

void Pacman::gameMoveDefault()
{
    handleSpeed();
    switch (_dir) {
        case LEFT:
            gameMoveLeft(true);
            break;
        case UP:
            gameMoveUp(true);
            break;
        case RIGHT:
            gameMoveRight(true);
            break;
        case DOWN:
            gameMoveDown(true);
            break;
        default:
            break;
    }
    if (((_pacman.first == _ghost1.first) && (_pacman.second == _ghost1.second)) || checkWin()) {
        countScore();
        setIsGameOver(true);
    }
    ghostMouvement();
    if (((_pacman.first == _ghost1.first) && (_pacman.second == _ghost1.second)) || checkWin()) {
        countScore();
        setIsGameOver(true);
    }
}

void Pacman::gameMoveLeft(bool isAuto)
{
    if (_dir != LEFT || isAuto ) {
        if (_map[_pacman.first][_pacman.second - 1] != WALL) {
            _map[_pacman.first][_pacman.second - 1] = PACMAN;
            _map[_pacman.first][_pacman.second] = SPACE;
            _pacman.second--;
            _dir = LEFT;
        }
    }
}

void Pacman::gameMoveRight(bool isAuto)
{
    if (_dir != RIGHT || isAuto ) {
        if (_map[_pacman.first][_pacman.second + 1] != WALL) {
            _map[_pacman.first][_pacman.second + 1] = PACMAN;
            _map[_pacman.first][_pacman.second] = SPACE;
            _pacman.second++;
            _dir = RIGHT;
        }
    }
}

void Pacman::gameMoveUp(bool isAuto)
{
    if (_dir != UP || isAuto) {
        if (_map[_pacman.first - 1][_pacman.second] != WALL) {
            _map[_pacman.first - 1][_pacman.second] = PACMAN;
            _map[_pacman.first][_pacman.second] = SPACE;
            _pacman.first--;
            _dir = UP;
        }
    }
}

void Pacman::gameMoveDown(bool isAuto)
{
    if (_dir != DOWN || isAuto) {
        if (_map[_pacman.first + 1][_pacman.second] != WALL) {
            _map[_pacman.first + 1][_pacman.second] = PACMAN;
            _map[_pacman.first][_pacman.second] = SPACE;
            _pacman.first++;
            _dir = DOWN;
        }
    }
}

void Pacman::countScore()
{
    if (getScore() != 0)
        return ;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 19; j++) {
            if (_map[i][j] == PACFOOD)
                setScore(25);
        }
    }
}

bool Pacman::checkWin()
{
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 19; j++) {
            if (_map[i][j] == PACFOOD)
                return false;
        }
    }
    return true;
}

void Pacman::gameScore(std::string playerName)
{
    int score = getScore();

    std::fstream file;
    file.open("Scoreboard.txt",  std::fstream::in | std::fstream::out | std::fstream::app);

    if(!file.is_open()){
        std::ifstream file("Scoreboard.txt");
        file.open("Scoreboard.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    }
    file << "-------- Pacman --------" << std::endl;
    if (checkWin())
        file << "WIN" << std::endl;
    else
        file << "LOSE" << std::endl;
    file << "Player : " << playerName << std::endl;
    file << "\tScore = " << getScore() << std::endl << std::endl;;
    file.close();
}
