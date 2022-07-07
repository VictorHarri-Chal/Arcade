/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Sdl.cpp
*/

#include "Sdl.hpp"

extern "C" IGraphic *entryPoint(bool b)
{
    if (b == false)
        return nullptr;
    IGraphic *tmp(new Sdl());
    return tmp;
}

void Sdl::graphInit()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_CreateWindowAndRenderer(_width, _height, SDL_WINDOW_SHOWN, &_window, &_renderer);
    SDL_SetWindowTitle(_window, "Arcade");
    setCurrentLib(2);
    // Set background to black
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void Sdl::graphDestroy()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
}

void Sdl::graphMenuDisplay()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    displaySprite(_welcomeText.c_str(), SDL_Color{0, 0, 255, 0}, 250, 50, 160);
    displaySprite(_promptText.c_str(), SDL_Color{0, 0, 255, 0}, 110, 230, 50);
    menuDisplayNameRect();
    displaySprite(getPlayerName().c_str(), SDL_Color{0, 0, 255, 0}, 500, 315, 130);
    displaySprite(_chooseText.c_str(), SDL_Color{0, 0, 255, 0}, 400, 460, 130);
    menuDisplayNibbler();
    menuDisplayPacman();
    if (getIsNameChoosed())
        displaySprite(_validText.c_str(), SDL_Color{0, 255, 0, 255}, 1100, 370, 80);

    SDL_RenderPresent(_renderer);
}

void Sdl::menuDisplayNameRect()
{
    SDL_Rect nameRect{500, 300, 600, 130};
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 0);
    SDL_RenderFillRect(_renderer, &nameRect);
}

void Sdl::menuDisplayNibbler()
{
    // nibblerRect
    if (getIsNameChoosed())
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 0);
    else
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
    SDL_RenderFillRect(_renderer, &_nibblerRect);

    // nibblerText
    displaySprite(_nibblerText.c_str(), SDL_Color{0, 0, 255, 0}, 200, 750, 120);
}

void Sdl::menuDisplayPacman()
{
    // pacmanRect
    if (getIsNameChoosed())
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 0);
    else
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
    SDL_RenderFillRect(_renderer, &_pacmanRect);

    // pacmanText
    displaySprite(_pacmanText.c_str(), SDL_Color{0, 0, 255, 0}, 1200, 750, 120);
}

void Sdl::displaySprite(const char *text, SDL_Color sdlc, int pos_x, int pos_y, int size)
{
    TTF_Font *Font = TTF_OpenFont("assets/fonts/font.ttf", size);
    SDL_Surface *Text = TTF_RenderText_Blended(Font, text, sdlc);
    SDL_Texture *Texture = SDL_CreateTextureFromSurface(_renderer, Text); // Crée la texture qu'on va afficher a partir de la surface
    SDL_Rect Position;
    Position.x = pos_x;
    Position.y = pos_y;
    SDL_QueryTexture(Texture, nullptr, nullptr, &Position.w, &Position.h); // Récupere la dimension de la welcomeTexture
    SDL_FreeSurface(Text);
    SDL_RenderCopy(_renderer, Texture, nullptr, &Position);
    TTF_CloseFont(Font);
}

void Sdl::displayPixel(SDL_Color sdlc, int i, int j, int w, int h, int mod)
{
    SDL_Rect pixel;
    pixel.x = (j * 30) + mod;
    pixel.y = (i * 30) + mod;
    pixel.w = w;
    pixel.h = h;
    SDL_SetRenderDrawColor(_renderer, sdlc.r, sdlc.g, sdlc.b, sdlc.a);
    SDL_RenderFillRect(_renderer, &pixel);
}

void Sdl::nibbler(std::vector<std::vector<int>> map, int speed, int score)
{
    SDL_Color backgroundColorGreen = {0, 255, 0, 255};
    SDL_Color backgroundColorBlue = {0, 0, 255, 255};
    SDL_Color backgroundColorRed = {255, 0, 0, 100};
    SDL_Color backgroundColorDarkGreen = {0, 100, 0, 255};

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 50; j++) {
            
            if (map[i][j] == 0)
                displayPixel(backgroundColorGreen, i, j, 30, 30, 0);
            if (map[i][j] == 1)
                displayPixel(backgroundColorBlue, i, j, 30, 30, 0);
            if (map[i][j] == 2)
                displayPixel(backgroundColorDarkGreen, i, j, 30, 30, 0);
            if (map[i][j] == 3)
                displayPixel(backgroundColorRed, i, j, 30, 30, 0);
        }
    }
    displaySprite("Name : ", SDL_Color{255, 255, 0, 0}, 30, 780, 50);
    displaySprite(getPlayerName().c_str(), SDL_Color{255, 255, 0, 0}, 150, 780, 50);
    displaySprite("Speed : ", SDL_Color{255, 255, 0, 0}, 30, 830, 50);
    displaySprite(std::to_string(speed).c_str(), SDL_Color{255, 255, 0, 0}, 160, 830, 50);
    displaySprite("Score : ", SDL_Color{255, 255, 0, 0}, 30, 880, 50);
    displaySprite(std::to_string(score).c_str(), SDL_Color{255, 255, 0, 0}, 160, 880, 50);
}

void Sdl::pacman(std::vector<std::vector<int>> map, int speed, int score)
{
    SDL_Color backgroundColorGreen = {0, 255, 0, 255};
    SDL_Color backgroundColorBlue = {0, 0, 255, 255};
    SDL_Color backgroundColorRed = {255, 0, 0, 100};
    SDL_Color backgroundColorYellow = {255, 255, 0, 0};
    SDL_Color backgroundColorBlack = {0, 0, 0, 0};
    SDL_Color backgroundColorWhite = {255, 255, 255, 0};

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 19; j++) {
            if (map[i][j] == 0)
                displayPixel(backgroundColorBlack, i, j, 30, 30, 0);
            if (map[i][j] == 1)
                displayPixel(backgroundColorBlue, i, j, 30, 30, 0);
            if (map[i][j] == 3)
                displayPixel(backgroundColorGreen, i, j, 30, 30, 0);
            if (map[i][j] == 4)
                displayPixel(backgroundColorYellow, i, j, 30, 30, 0);
            if (map[i][j] == 5) {
                displayPixel(backgroundColorBlack, i, j, 30, 30, 0);
                displayPixel(backgroundColorWhite, i, j, 5, 5, 15);
            }
            if (map[i][j] == 6)
                displayPixel(backgroundColorRed, i, j, 30, 30, 0);
        }
    }
    displaySprite("Name : ", SDL_Color{255, 255, 0, 0}, 30, 780, 50);
    displaySprite(getPlayerName().c_str(), SDL_Color{255, 255, 0, 0}, 150, 780, 50);
    displaySprite("Speed : ", SDL_Color{255, 255, 0, 0}, 30, 830, 50);
    displaySprite(std::to_string(speed).c_str(), SDL_Color{255, 255, 0, 0}, 160, 830, 50);
    displaySprite("Score : ", SDL_Color{255, 255, 0, 0}, 30, 880, 50);
    displaySprite(std::to_string(score).c_str(), SDL_Color{255, 255, 0, 0}, 160, 880, 50);
}

void Sdl::graphDisplay(std::vector<std::vector<int>> map, int speed, int score)
{
    // Set Background to black
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 50);
    SDL_RenderClear(_renderer);
    if (getGameChoice() == 0)
        nibbler(map, speed, score);
    else if (getGameChoice() == 1)
        pacman(map, speed, score);
    SDL_RenderPresent(_renderer);
}

void Sdl::graphClear()
{
    SDL_RenderClear(_renderer);
}

void Sdl::graphRefresh()
{
    SDL_RenderPresent(_renderer);
}

void Sdl::handleEvents()
{
    while (SDL_PollEvent(&_event))
    {
        if (_event.type == SDL_QUIT)
            setKey("Escape");
        handleKeys();
        if (_event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (isBtnClicked(_event.button, _nibblerRect))
            {
                setGameChoice(0);
                setKey("Return");
            }
            else if (isBtnClicked(_event.button, _pacmanRect))
            {
                setGameChoice(1);
                setKey("Return");
            }
        }
    }
}

void Sdl::handleKeys()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (_event.type == SDL_KEYDOWN)
    {
        switch (_event.key.keysym.sym) {
            case SDLK_a:
                setKey("a");
                break;
            case SDLK_b:
                setKey("b");
                break;
            case SDLK_c:
                setKey("c");
                break;
            case SDLK_d:
                setKey("d");
                break;
            case SDLK_e:
                setKey("e");
                break;
            case SDLK_f:
                setKey("f");
                break;
            case SDLK_g:
                setKey("g");
                break;
            case SDLK_h:
                setKey("h");
                break;
            case SDLK_i:
                setKey("i");
                break;
            case SDLK_j:
                setKey("j");
                break;
            case SDLK_k:
                setKey("k");
                break;
            case SDLK_l:
                setKey("l");
                break;
            case SDLK_m:
                setKey("m");
                break;
            case SDLK_n:
                setKey("n");
                break;
            case SDLK_o:
                setKey("o");
                break;
            case SDLK_p:
                setKey("p");
                break;
            case SDLK_q:
                setKey("q");
                break;
            case SDLK_r:
                setKey("r");
                break;
            case SDLK_s:
                setKey("s");
                break;
            case SDLK_t:
                setKey("t");
                break;
            case SDLK_u:
                setKey("u");
                break;
            case SDLK_v:
                setKey("v");
                break;
            case SDLK_w:
                setKey("w");
                break;
            case SDLK_x:
                setKey("x");
                break;
            case SDLK_y:
                setKey("y");
                break;
            case SDLK_z:
                setKey("z");
                break;
            case SDLK_LEFT:
                setKey("Left");
                break;
            case SDLK_UP:
                setKey("Up");
                break;
            case SDLK_RIGHT:
                setKey("Right");
                break;
            case SDLK_DOWN:
                setKey("Down");
                break;
            case SDLK_ESCAPE:
                setKey("Escape");
                break;
            case SDLK_RETURN:
                setKey("Return");
                break;
            case SDLK_BACKSPACE:
                setKey("Backspace");
                break;
            default:
                break;
        }
        // Hack: only listens to the chars from a to z or the special keybindings
        if (getKeyPressed().length() > 1 && getKeyPressed() != "Escape" && getKeyPressed() != "Return" && getKeyPressed() != "Backspace"
        && getKeyPressed() != "Left" && getKeyPressed() != "Up" && getKeyPressed() != "Right" && getKeyPressed() != "Down")
            setKey("");
    }
}

bool Sdl::isBtnClicked(SDL_MouseButtonEvent event, SDL_Rect rect)
{
    if (event.x >= rect.x && event.x < (rect.x + rect.w)) {
        if (event.y >= rect.y && event.y < (rect.y + rect.h))
            return true;
    }
    return false;
}

void Sdl::transitionFrame(int i)
{
    if (i == 0) {
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 50);
        SDL_RenderClear(_renderer);
        displaySprite(_startText.c_str(), SDL_Color{0, 0, 255, 0}, 400, 500, 100);
        displaySprite("3", SDL_Color{0, 0, 255, 0}, 920, 500, 100);
        displaySprite(_secondsText.c_str(), SDL_Color{0, 0, 255, 0}, 980, 500, 100);
        SDL_RenderPresent(_renderer);
        usleep(1000000);
        displaySprite("3", SDL_Color{0, 0, 0, 0}, 920, 500, 100);
        displaySprite("2", SDL_Color{0, 0, 255, 0}, 920, 500, 100);
        SDL_RenderPresent(_renderer);
        usleep(1000000);
        displaySprite("2", SDL_Color{0, 0, 0, 0}, 920, 500, 100);
        displaySprite("1", SDL_Color{0, 0, 255, 0}, 920, 500, 100);
        SDL_RenderPresent(_renderer);
        usleep(1000000);
    }
    if (i == 1) {
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 50);
        SDL_RenderClear(_renderer);
        displaySprite(_restartText.c_str(), SDL_Color{0, 0, 255, 0}, 400, 500, 100);
        displaySprite("3", SDL_Color{0, 0, 255, 0}, 920, 500, 100);
        displaySprite(_secondsText.c_str(), SDL_Color{0, 0, 255, 0}, 980, 500, 100);
        SDL_RenderPresent(_renderer);
        usleep(1000000);
        displaySprite("3", SDL_Color{0, 0, 0, 0}, 920, 500, 100);
        displaySprite("2", SDL_Color{0, 0, 255, 0}, 920, 500, 100);
        SDL_RenderPresent(_renderer);
        usleep(1000000);
        displaySprite("2", SDL_Color{0, 0, 0, 0}, 920, 500, 100);
        displaySprite("1", SDL_Color{0, 0, 255, 0}, 920, 500, 100);
        SDL_RenderPresent(_renderer);
        usleep(1000000);
    }
    if (i == 2) {
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 50);
        SDL_RenderClear(_renderer);
        displaySprite(_scoreboardText.c_str(), SDL_Color{0, 0, 255, 0}, 300, 500, 75);
        SDL_RenderPresent(_renderer);
        usleep(5000000);
    }
}
