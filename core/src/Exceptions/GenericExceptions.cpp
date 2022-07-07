/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** GenericExceptions.cpp
*/

#include "GenericExceptions.hpp"


GenericExceptions::GenericExceptions(const std::string &message) noexcept: _message(message) {}

const char *GenericExceptions::what() const noexcept
{
    return _message.data();
}

void GenericExceptions::dispErrorMessage() noexcept
{
    std::cerr << "Error: " << _message << std::endl;
}