/*
** EPITECH PROJECT, 2022
** 2eme annee
** File description:
** Arcade: core.cpp
*/

#include "Core.hpp"

Core::Core(std::string glib): _graphic_list{"lib/arcade_ncurses.so", "lib/arcade_sfml.so", "lib/arcade_sdl2.so"},
                              _game_list{"lib/arcade_nibbler.so", "lib/arcade_pacman.so"}
{
    _graphic = loadGraphicLib(glib);
    coreLoop();
}

IGraphic *Core::loadGraphicLib(std::string glib)
{
    _graphic = nullptr;
    _handle_graphic = nullptr;
    IGraphic *(*entryPoint)(bool) = nullptr;
    IGraphic *loaded_lib = nullptr;

    _handle_graphic = dlopen(glib.c_str(), RTLD_LAZY);
    if (_handle_graphic == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw GenericExceptions("dlopen failed.");
    }
    entryPoint = (IGraphic *(*)(bool))dlsym(_handle_graphic, "entryPoint");
    if (entryPoint == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw GenericExceptions("dlsym failed.");
    }
    loaded_lib = (*entryPoint)(true);
    if (loaded_lib == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw GenericExceptions("dlsym failed.");
    }
    return loaded_lib;
}

IGame *Core::loadGameLib(std::string glib)
{
    _game = nullptr;
    _handle_game = nullptr;
    IGame *(*entryPoint)(bool) = nullptr;
    IGame *loaded_lib = nullptr;

    _handle_game = dlopen(glib.c_str(), RTLD_LAZY);
    if (_handle_game == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw GenericExceptions("dlopen failed.");
    }
    entryPoint = (IGame *(*)(bool))dlsym(_handle_game, "entryPoint");
    if (entryPoint == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw GenericExceptions("dlsym failed.");
    }
    loaded_lib = (*entryPoint)(false);
    if (loaded_lib == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw GenericExceptions("dlsym failed.");
    }
    return loaded_lib;
}

void Core::coreLoop(void)
{
    _graphic->graphInit();
    while (_graphic->getKeyPressed() != "Escape") {
        initName();
        inMenu();
        inGame();
        changeGraphicLib();
        _graphic->handleEvents();
        _graphic->graphRefresh();
    }
    _graphic->graphDestroy();
    dlclose(_handle_graphic);

}

void Core::initName(void)
{
    while (!_graphic->getIsNameChoosed()) {
        _graphic->graphMenuDisplay();
        _graphic->handleEvents();
        if (_graphic->getKeyPressed() == "Escape")
            killArcade();
        if (_graphic->getKeyPressed() == "Return" && _graphic->getPlayerName() != "") {
            _graphic->setIsNameChoosed(true);
            _graphic->setKey("");
        }
        if (std::strlen(_graphic->getPlayerName().c_str()) > 0 && _graphic->getKeyPressed() == "Backspace") {
            _graphic->setBackspacePlayerName();
            _graphic->setKey("");
        }
        if (std::strlen(_graphic->getPlayerName().c_str()) < 10 && _graphic->getKeyPressed() != "Return" && _graphic->getKeyPressed() != "Escape" && _graphic->getKeyPressed() != "Up"
        && _graphic->getKeyPressed() != "Down" && _graphic->getKeyPressed() != "Left" && _graphic->getKeyPressed() != "Right" && _graphic->getKeyPressed() != "Backspace") {
            _graphic->setPlayerName(_graphic->getKeyPressed());
            _graphic->setKey("");
        }
        _graphic->graphRefresh();
    }
}

void Core::inMenu(void)
{
    if (_graphic->getInMenu()) {
        _graphic->graphMenuDisplay();
        if (_graphic->getKeyPressed() == "Return") {
            _graphic->transitionFrame(0);
            _graphic->setInMenu(false);
            if (_graphic->getGameChoice() == 0)
                _game = loadGameLib(_game_list[0]);
            else if (_graphic->getGameChoice() == 1)
                _game = loadGameLib(_game_list[1]);
            _game->gameInit();
        }
    }
}

void Core::inGame(void)
{
    if (!_graphic->getInMenu()) {
        _graphic->graphDisplay(_game->getMap(), _game->getSpeed(),_game->getScore());
        if (_graphic->getKeyPressed() == "t")
            _graphic->setInMenu(true);
        if (_graphic->getKeyPressed() == "y") {
            _game->setSpeed(false);
            _graphic->setKey("");
        }
        if (_graphic->getKeyPressed() == "u") {
            _game->setSpeed(true);
            _graphic->setKey("");
        }
        if (_graphic->getKeyPressed() == "Left")
            _game->gameMoveLeft(false);
        if (_graphic->getKeyPressed() == "Up")
            _game->gameMoveUp(false);
        if (_graphic->getKeyPressed() == "Right")
            _game->gameMoveRight(false);
        if (_graphic->getKeyPressed() == "Down")
            _game->gameMoveDown(false);
        _game->gameMoveDefault();
        if (_graphic->getKeyPressed() == "Escape")
            killArcadeInGame();
        if (_game->getIsGameOver()) {
            _game->gameScore(_graphic->getPlayerName());
            _graphic->transitionFrame(2);
            killArcadeInGame();
        }
        changeGameLib();
    }
}

void Core::changeGraphicLib(void)
{
    if (_graphic->getKeyPressed() == "a") {
        std::string player_name = _graphic->getPlayerName();
        bool in_menu = _graphic->getInMenu();
        int game_choice = _graphic->getGameChoice();
        _graphic->graphClear();
        _graphic->graphDestroy();
        if (_graphic->getCurrentLib() == 1 || _graphic->getCurrentLib() == 2)
            _graphic = loadGraphicLib(_graphic_list[_graphic->getCurrentLib() - 1]);
        else if (_graphic->getCurrentLib() == 0)
            _graphic = loadGraphicLib(_graphic_list[_graphic->getCurrentLib() + 2]);
        _graphic->setPlayerName(player_name);
        _graphic->setIsNameChoosed(true);
        _graphic->setInMenu(in_menu);
        _graphic->setGameChoice(game_choice);
        _graphic->graphInit();
    }
    if (_graphic->getKeyPressed() == "e") {
        std::string player_name = _graphic->getPlayerName();
        bool in_menu = _graphic->getInMenu();
        int game_choice = _graphic->getGameChoice();
        _graphic->graphClear();
        _graphic->graphDestroy();
        if (_graphic->getCurrentLib() == 0 || _graphic->getCurrentLib() == 1)
            _graphic = loadGraphicLib(_graphic_list[_graphic->getCurrentLib() + 1]);
        else if (_graphic->getCurrentLib() == 2)
            _graphic = loadGraphicLib(_graphic_list[_graphic->getCurrentLib() - 2]);
        _graphic->setPlayerName(player_name);
        _graphic->setIsNameChoosed(true);
        _graphic->setInMenu(in_menu);
        _graphic->setGameChoice(game_choice);
        _graphic->graphInit();
    }
}

void Core::changeGameLib(void)
{
    if (_graphic->getKeyPressed() == "d" || _graphic->getKeyPressed() == "q") {
        if (_graphic->getGameChoice() == 0) {
            _graphic->setGameChoice(1);
            _game = loadGameLib(_game_list[1]);
        }
        else if (_graphic->getGameChoice() == 1) {
            _graphic->setGameChoice(0);
            _game = loadGameLib(_game_list[0]);
        }
        _game->gameInit();
        _graphic->setKey("");
    }
    if (_graphic->getKeyPressed() == "r") {
        _graphic->transitionFrame(1);
        _game = loadGameLib(_game_list[_graphic->getGameChoice()]);
        _game->gameInit();
        _graphic->setKey("");
    }
}

void Core::killArcade(void)
{
    _graphic->graphClear();
    _graphic->graphDestroy();
    dlclose(_handle_graphic);
    exit(0);
}

void Core::killArcadeInGame(void)
{
    _graphic->graphClear();
    _graphic->graphDestroy();
    dlclose(_handle_game);
    dlclose(_handle_graphic);
    exit(0);
}

