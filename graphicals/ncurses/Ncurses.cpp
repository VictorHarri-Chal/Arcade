/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Ncurses.cpp
*/

#include "Ncurses.hpp"

extern "C" IGraphic *entryPoint(bool b)
{
    if (b == false)
        return nullptr;
    IGraphic *tmp(new Ncurses());
    return tmp;
}

void Ncurses::graphInit()
{
    setCurrentLib(0);
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    cbreak();
    start_color();
    if (getIsNameChoosed())
        nodelay(stdscr, true);
}

void Ncurses::graphDestroy()
{
    endwin();
}

void Ncurses::graphMenuDisplay()
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    box(stdscr, 0, 0);
    if (yMax < 35 || xMax < 150)
        mvprintw(LINES/2, COLS/2, "Resize your terminal!");
    else {
        mvprintw(LINES / 4, (COLS-std::strlen(_welcomeText.c_str()))/2, _welcomeText.c_str());
        mvprintw(LINES / 3, (COLS-std::strlen(_promptText.c_str()))/2, _promptText.c_str());
        mvprintw(LINES / 3, (COLS-std::strlen(_promptText.c_str()))/2+92, getPlayerName().c_str());
        if (getIsNameChoosed()) {
            nodelay(stdscr, true);
            mvprintw(LINES / 3, (COLS - std::strlen(_promptText.c_str())) / 2 + 93 + std::strlen(getPlayerName().c_str()), "VALIDATED");
            menuDrawGameChoice();
        }
    }
}

void Ncurses::menuDrawGameChoice()
{
    std::string games[2] = {_nibblerText, _pacmanText};

    for (int i = 0; i < 2; i++) {
        int j = 0;
        if (i == _game_choice)
            wattron(stdscr, A_REVERSE);
        mvprintw((LINES / 2)+i, (COLS-std::strlen(games[i].c_str()))/2, games[i].c_str());
        wattroff(stdscr, A_REVERSE);
        j += 30;
    }
    if (_key == "Up") {
        _game_choice--;
        if (getGameChoice() == -1)
            setGameChoice(0);
    }
    if (_key == "Down") {
        _game_choice++;
        if (getGameChoice() == 2)
            setGameChoice(1);
    }
}

void Ncurses::graphDisplay(std::vector<std::vector<int>> map, int speed, int score)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    int cols;
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

    if (getGameChoice() == 0)
        cols = 50;
    else
        cols = 19;
    box(stdscr, 0, 0);
    if (yMax < 35 || xMax < 150)
        mvprintw(LINES/2, COLS/2, "Resize your terminal!");
    else {
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < cols; j++) {
                if (map[i][j] == 0) // SPACE
                    mvprintw(LINES/6 + i, COLS/3 + j, " ");
                if (map[i][j] == 1) { // MURS
                    attron(COLOR_PAIR(1)); // Bleu
                    mvprintw(LINES/6 + i, COLS/3 + j, " ");
                    attroff(COLOR_PAIR(1));
                }
                if (map[i][j] == 2) // o donc serpent
                    mvprintw(LINES/6 + i, COLS/3 + j, "o");
                if (map[i][j] == 3) { // nourriture serpent
                    attron(COLOR_PAIR(4));
                    mvprintw(LINES/6 + i, COLS/3 + j, "x");
                    attroff(COLOR_PAIR(4));
                }
                if (map[i][j] == 4) { // pacman
                    attron(COLOR_PAIR(2));
                    mvprintw(LINES/6 + i, COLS/3 + j, "C");
                    attroff(COLOR_PAIR(2));
                }
                if (map[i][j] == 5) // Nourritue pacman
                    mvprintw(LINES/6 + i, COLS/3 + j, ".");
                if (map[i][j] == 6) { // Fantômes en rouge
                    attron(COLOR_PAIR(3));
                    mvprintw(LINES/6 + i, COLS/3 + j, "G");
                    attroff(COLOR_PAIR(3));
                }
            }
        }
        attron(COLOR_PAIR(2));
        mvprintw(LINES/6 + 26, COLS/3, "Name : %s  Speed : %i  Score : %i", getPlayerName().c_str(), speed, score);
        attroff(COLOR_PAIR(2));
    }
}

void Ncurses::graphClear()
{
    clear();
}

void Ncurses::graphRefresh()
{
    usleep(20000);
    refresh();
    clear();
}

void Ncurses::handleEvents()
{
    int k = getch();
    if (k == 27)
        _key = "Escape";
    else if (k == '\n')
        _key = "Return";
    else if (k == KEY_BACKSPACE)
        _key = "Backspace";
    else if (k > 96 && k < 123)
        _key = k;
    else if (k == KEY_UP)
        _key = "Up";
    else if (k == KEY_DOWN)
        _key = "Down";
    else if (k == KEY_LEFT)
        _key = "Left";
    else if (k == KEY_RIGHT)
        _key = "Right";
    else
        _key = "";
}

void Ncurses::transitionFrame(int i)
{
    if (i == 0) {
        clear();
        box(stdscr, 0, 0);
        mvprintw(LINES/2, COLS/2 - 20, "%s3%s", _startText.c_str(), _secondsText.c_str());
        refresh();
        usleep(1000000);
        clear();
        box(stdscr, 0, 0);
        mvprintw(LINES/2, COLS/2 - 20, "%s2%s", _startText.c_str(), _secondsText.c_str());
        refresh();
        usleep(1000000);
        clear();
        box(stdscr, 0, 0);
        mvprintw(LINES/2, COLS/2 - 20, "%s1%s", _startText.c_str(), _secondsText.c_str());
        refresh();
        usleep(1000000);
    }
    if (i == 1) {
        clear();
        box(stdscr, 0, 0);
        mvprintw(LINES/2, COLS/2 - 20, "%s3%s", _restartText.c_str(), _secondsText.c_str());
        refresh();
        usleep(1000000);
        clear();
        box(stdscr, 0, 0);
        mvprintw(LINES/2, COLS/2 - 20, "%s2%s", _restartText.c_str(), _secondsText.c_str());
        refresh();
        usleep(1000000);
        clear();
        box(stdscr, 0, 0);
        mvprintw(LINES/2, COLS/2 - 20, "%s1%s", _restartText.c_str(), _secondsText.c_str());
        refresh();
        usleep(1000000);
    }
    if (i == 2) {
        clear();
        box(stdscr, 0, 0);
        mvprintw(LINES/2, COLS/2 - 30, "%s", _scoreboardText.c_str());
        refresh();
        usleep(5000000);
    }
}
