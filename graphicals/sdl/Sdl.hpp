/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Sdl.hpp
*/

#ifndef _SDL_HPP_
#define _SDL_HPP_

#include "../IGraphic.hpp"
#include "../AGraphicMemory.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Sdl : public AGraphicMemory
{
    public:
        Sdl() = default;
        ~Sdl() = default;
        void graphInit();
        void graphDestroy();
        void graphDisplay(std::vector<std::vector<int>> map, int speed, int score);
        void graphMenuDisplay();
        void graphClear();
        void graphRefresh();
        void handleEvents();
        void transitionFrame(int i);

        void menuDisplayNameRect();
        void menuDisplayNibbler();
        void menuDisplayPacman();
        void displaySprite(const char *text, SDL_Color sdlc, int pos_x, int pos_y, int size);
        void displayPixel(SDL_Color sdlc, int i, int j, int w, int h, int mod);
        void handleKeys();
        void nibbler(std::vector<std::vector<int>> map, int speed, int score);
        void pacman(std::vector<std::vector<int>> map, int speed, int score);
        bool isBtnClicked(SDL_MouseButtonEvent event, SDL_Rect rect);
    private :
        SDL_Window *_window{nullptr};
        SDL_Renderer *_renderer {nullptr};
        SDL_Event _event;
        SDL_Rect _nibblerRect{50, 650, 600, 330};
        SDL_Rect _pacmanRect{950, 650, 600, 330};
        int _width = 1600;
        int _height = 1700;
};

#endif
