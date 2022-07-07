/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** AGraphicMemory.cpp
*/

#include "AGraphicMemory.hpp"

std::string AGraphicMemory::getKeyPressed() const
{
    return _key;
}

std::string AGraphicMemory::getPlayerName() const
{
    return _player_name;
}

bool AGraphicMemory::getIsNameChoosed() const
{
    return _is_name_choosed;
}

bool AGraphicMemory::getInMenu() const
{
    return _in_menu;
}

int AGraphicMemory::getGameChoice() const
{
    return _game_choice;
}

int AGraphicMemory::getCurrentLib() const
{
    return _current_lib;
}

void AGraphicMemory::setKey(std::string key)
{
    _key = key;
}

void AGraphicMemory::setPlayerName(std::string letter)
{
    _player_name = _player_name + letter;
}

void AGraphicMemory::setBackspacePlayerName(void)
{
    _player_name.pop_back();
}

void AGraphicMemory::setIsNameChoosed(bool i)
{
    _is_name_choosed = i;
}

void AGraphicMemory::setInMenu(bool b)
{
    _in_menu = b;
}

void AGraphicMemory::setGameChoice(int i)
{
    _game_choice = i;
}

void AGraphicMemory::setCurrentLib(int i)
{
    _current_lib = i;
}
