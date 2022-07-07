/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** main.cpp
*/

#include "Exceptions/GenericExceptions.hpp"
#include "Core.hpp"
#include "../../games/IGame.hpp"
#include "../../graphicals/IGraphic.hpp"

static void usage(void)
{
    std::cout << "USAGE : \n\t" << "./arcade graphical_lib.so" << std::endl << std::endl;
    std::cout << "The graphical libraries available are in the ./lib/ folder" << std::endl;
    std::cout << "\t- arcade_ncurses.so" << std::endl;
    std::cout << "\t- arcade_sld2.so" << std::endl;
    std::cout << "\t- arcade_sfml.so" << std::endl << std::endl;
    std::cout << "KEYBINDS" << std::endl;
    std::cout << "\tUse the Keypad to move during the game" << std::endl;
    std::cout << "\tChange the speed of the games                 -> -Y U+" << std::endl;
    std::cout << "\tSwap to/Choose the next graphical library     -> A" << std::endl;
    std::cout << "\tSwap to/Choose the previous graphical library -> E" << std::endl;
    std::cout << "\tSwap to/Choose to the next game               -> D" << std::endl;
    std::cout << "\tSwap to/Choose to the previous game           -> Q" << std::endl;
    std::cout << "\tRestart the game                              -> R" << std::endl;
    std::cout << "\tGo back to the menu                           -> T" << std::endl;
    std::cout << "\tQuit the arcade                               -> ESC" << std::endl;
}

int main(int argc, char **argv)
{
    try {
        if (argc != 2) {
            usage();
            return 0;
        } else if (argc == 2 && strcmp(argv[1], "-h") == 0) {
            usage();
            return 0;
        }
        Core core(argv[1]);
    }
    catch (GenericExceptions &message) {
        message.dispErrorMessage();
        return 84;
    }
    return 0;
}
