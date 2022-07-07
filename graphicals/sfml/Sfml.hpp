/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../IGraphic.hpp"
#include "../AGraphicMemory.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sfml : public AGraphicMemory {
    typedef struct game_btn
    {
        sf::RectangleShape rect;
        sf::Text text;
        sf::Vector2f positionRect;
        sf::Vector2f positionText;
    } game_btn_t;

    public:
        Sfml() = default;
        ~Sfml() = default;
        void graphInit();
        void graphDestroy();
        void graphDisplay(std::vector<std::vector<int>> map, int speed, int score);
        void graphMenuDisplay();
        void graphClear();
        void graphRefresh();
        void handleEvents();
        void transitionFrame(int i);

        void menuDrawName();
        void menuDisplayNibbler();
        void menuDisplayPacman();
        void nibbler(std::vector<std::vector<int>> map, int speed, int score);
        void pacman(std::vector<std::vector<int>> map, int speed, int score);
        bool isBtnClicked(sf::Event::MouseButtonEvent event, game_btn_t button);
    private:
        sf::RenderWindow _window{};
        sf::Font _font{};
        sf::Event _event{};
        game_btn_t _nibbler_btn;
        game_btn_t _pacman_btn;
        unsigned int _width = 1600;
        unsigned int _height = 1700;
        sf::RectangleShape _gridRect;
        sf::RectangleShape _gridPieces[25][50];
        int _gridArray[25][50];
};

#endif /* !SFML_HPP_ */
