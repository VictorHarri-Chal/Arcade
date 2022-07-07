/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Nibbler.cpp
*/

#include "Nibbler.hpp"
#include <iostream>

extern "C" IGame *entryPoint(bool b)
{
    if (b == true)
        return nullptr;
    IGame *tmp(new Nibbler());
    return tmp;
}

void Nibbler::gameInit()
{
    std::srand(std::time(nullptr));
    int x = 0;
    std::ifstream filepath("./games/nibbler/map.txt");

    for (int cols = 0; cols < 25; cols++) {
        std::vector<int> tmp;
        for (int rows = 0; rows < 50; rows++)
            tmp.push_back(0);
        _map.push_back(tmp);
    }
    for (std::string line; std::getline(filepath, line); x++) {
        for (int y = 0; y < 50; y++) {
            if (line[y] == ' ')
                _map[x][y] = SPACE;
            if (line[y] == '#')
                _map[x][y] = WALL;
            if (line[y] == 'o')
                _map[x][y] = SNAKE;
            if (line[y] == 'x')
                _map[x][y] = FOOD;
        }
    }
    _dir = RIGHT;
    // Vecteur de pair tuple qui permet d'initialiser les positions du serpents
    for (int i = 0; i < 5; i++) {
        _snk.push_back(std::make_pair(12, 14 - i));
    }
}

void Nibbler::gameMoveDefault()
{
    handleSpeed();
    // Prend un bool en argument quand le bool est à true (fct de déplacement auto qui conserve sa trajectoire)
    // False pour changer de direction (cf. getKeyPressed() -> dans le core pour les bools a false)
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
}

void Nibbler::moveSnake()
{
    int i = _snk.size() - 1;

    if (findFood())
        _map[_snk.back().first][_snk.back().second] = SPACE;
    else {
        _map[_snk.back().first][_snk.back().second] = SNAKE;
        _snk.push_back(std::make_pair(_snk[_snk.size()-1].first, _snk[_snk.size()-1].second));
        setScore(500);
        handleFood();
    }
    // Décaler tous les movements du serpent
    while (i != 0) {
        _snk[i] = _snk[i - 1];
        // = SNAKE signifie -> ajoute à la fin et au début
        _map[_snk[i - 1].first][_snk[i - 1].second] = SNAKE;
        i--;
    }
}

void Nibbler::gameMoveLeft(bool isAuto)
{
    if ((_dir != RIGHT && _dir != LEFT) || isAuto ) {
        if (_map[_snk.front().first][_snk.front().second - 1] == WALL || _map[_snk.front().first][_snk.front().second - 1] == SNAKE)
            setIsGameOver(true);
        if (_map[_snk.front().first][_snk.front().second - 1] != WALL || _map[_snk.front().first][_snk.front().second - 1] != SNAKE) {
            moveSnake();
            _snk.front().second--;
            _dir = LEFT;
        }
    }
}

void Nibbler::gameMoveRight(bool isAuto)
{
    if ((_dir != LEFT && _dir != RIGHT) || isAuto) {
        if (_map[_snk.front().first][_snk.front().second + 1] == WALL || _map[_snk.front().first][_snk.front().second + 1] == SNAKE)
            setIsGameOver(true);
        if (_map[_snk.front().first][_snk.front().second + 1] != WALL || _map[_snk.front().first][_snk.front().second + 1] != SNAKE) {
            moveSnake();
            _snk.front().second++;
            _dir = RIGHT;
        }
    }
}

void Nibbler::gameMoveUp(bool isAuto)
{
    if ((_dir != DOWN && _dir != UP) || isAuto) {
        if (_map[_snk.front().first - 1][_snk.front().second] == WALL || _map[_snk.front().first - 1][_snk.front().second] == SNAKE)
            setIsGameOver(true);
        if (_map[_snk.front().first - 1][_snk.front().second] != WALL || _map[_snk.front().first - 1][_snk.front().second] != SNAKE) {
            moveSnake();
            _snk.front().first--;
            _dir = UP;
        }
    }
}

void Nibbler::gameMoveDown(bool isAuto)
{
    if ((_dir != UP && _dir != DOWN) || isAuto) {
        if (_map[_snk.front().first + 1][_snk.front().second] == WALL || _map[_snk.front().first + 1][_snk.front().second] == SNAKE)
            setIsGameOver(true);
        if (_map[_snk.front().first + 1][_snk.front().second] != WALL || _map[_snk.front().first + 1][_snk.front().second] != SNAKE) {
            moveSnake();
            _snk.front().first++;
            _dir = DOWN;
        }
    }
}

void Nibbler::handleFood()
{
    bool isThereFood = findFood();
    if (isThereFood)
        return ;
    else {
        int i = std::rand() % 25;
        int j = std::rand() % 50;
        if (_map[i][j] != SPACE)
            handleFood();
        else
            _map[i][j] = FOOD;
    }
}

// Si il trouve encore de la nourriture retrun true sinon ca en remture false et ca rajoute
bool Nibbler::findFood()
{
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 50; j++) {
            if (_map[i][j] == FOOD)
                return true;
        }
    }
    return false;
}

void Nibbler::gameScore(std::string playerName)
{
    int score = getScore();

    std::fstream file;
    file.open("Scoreboard.txt",  std::fstream::in | std::fstream::out | std::fstream::app);

    if(!file.is_open()){
        std::ifstream file("Scoreboard.txt");
        file.open("Scoreboard.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    }
    file << "-------- Nibbler --------" << std::endl;
    file << "LOSE" << std::endl;
    file << "Player : " << playerName << std::endl;
    file << "\tScore = " << getScore() << std::endl << std::endl;;
    file.close();

}
