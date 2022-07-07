/*
** EPITECH PROJECT, 2021
** B-OOP-400-NAN-4-1-arcade-victor.harri-chal
** File description:
** Sfml.cpp
*/

#include "Sfml.hpp"

extern "C" IGraphic *entryPoint(bool b)
{
    if (b == false)
        return nullptr;
    IGraphic *tmp(new Sfml());
    return tmp;
}

void Sfml::graphInit()
{
    setCurrentLib(1);
    _window.create(sf::VideoMode(_width, _height), "Arcade");
    _window.setFramerateLimit(60);
    _font.loadFromFile("assets/fonts/font.ttf");
}

void Sfml::graphDestroy()
{
    _window.close();
}

void Sfml::graphDisplay(std::vector<std::vector<int>> map, int speed, int score)
{
    _window.clear();
    if (getGameChoice() == 0)
        nibbler(map, speed, score);
    else if (getGameChoice() == 1)
        pacman(map, speed, score);
}

void Sfml::nibbler(std::vector<std::vector<int>> map, int speed, int score)
{
    sf::RectangleShape nibblerBackground(sf::Vector2f(30, 30));
    sf::Color backgroundColorGreen(0, 255, 0);
    sf::Color backgroundColorBlue(0, 0, 255);
    sf::Color backgroundColorRed(255, 0, 0);
    sf::Color backgroundColorDarkGreen(0, 100, 0);
    sf::Text nameText("Name : ", _font, 50);
    sf::Text nameValueText(getPlayerName().c_str(), _font, 50);
    sf::Text speedText("Speed : ", _font, 50);
    sf::Text speedValueText(std::to_string(speed).c_str(), _font, 50);
    sf::Text scoreText("Score : ", _font, 50);
    sf::Text scoreValueText(std::to_string(score).c_str(), _font, 50);
    nameText.setPosition(sf::Vector2f(30, 780));
    nameValueText.setPosition(sf::Vector2f(150, 780));
    speedText.setPosition(sf::Vector2f(30, 830));
    speedValueText.setPosition(sf::Vector2f(160, 830));
    scoreText.setPosition(sf::Vector2f(30, 880));
    scoreValueText.setPosition(sf::Vector2f(160, 880));
    nameText.setFillColor(sf::Color::Yellow);
    nameValueText.setFillColor(sf::Color::Yellow);
    speedText.setFillColor(sf::Color::Yellow);
    speedValueText.setFillColor(sf::Color::Yellow);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreValueText.setFillColor(sf::Color::Yellow);

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (map[i][j] == 0) {
                nibblerBackground.setFillColor(backgroundColorGreen);
                nibblerBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(nibblerBackground);
            }
            if (map[i][j] == 1) {
                nibblerBackground.setFillColor(backgroundColorBlue);
                nibblerBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(nibblerBackground);
            }
            if (map[i][j] == 2) {
                nibblerBackground.setFillColor(backgroundColorDarkGreen);
                nibblerBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(nibblerBackground);
            }
            if (map[i][j] == 3) {
                nibblerBackground.setFillColor(backgroundColorRed);
                nibblerBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(nibblerBackground);
            }
        }
    }
    _window.draw(nameText);
    _window.draw(nameValueText);
    _window.draw(speedText);
    _window.draw(speedValueText);
    _window.draw(scoreText);
    _window.draw(scoreValueText);
}

void Sfml::pacman(std::vector<std::vector<int>> map, int speed, int score)
{
    sf::RectangleShape pacmanBackground(sf::Vector2f(30, 30));
    sf::RectangleShape pacmanFood(sf::Vector2f(5, 5));
    sf::Color backgroundColorGreen(0, 255, 0);
    sf::Color backgroundColorBlue(0, 0, 255);
    sf::Color backgroundColorRed(255, 0, 0);
    sf::Color backgroundColorDarkGreen(0, 100, 0);
    sf::Color backgroundColorYellow(255, 255, 0);
    sf::Color backgroundColorWhite(255, 255, 255);
    sf::Color backgroundColorBlack(0, 0, 0);
    sf::Text nameText("Name : ", _font, 50);
    sf::Text nameValueText(getPlayerName().c_str(), _font, 50);
    sf::Text speedText("Speed : ", _font, 50);
    sf::Text speedValueText(std::to_string(speed).c_str(), _font, 50);
    sf::Text scoreText("Score : ", _font, 50);
    sf::Text scoreValueText(std::to_string(score).c_str(), _font, 50);
    nameText.setPosition(sf::Vector2f(30, 780));
    nameValueText.setPosition(sf::Vector2f(150, 780));
    speedText.setPosition(sf::Vector2f(30, 830));
    speedValueText.setPosition(sf::Vector2f(160, 830));
    scoreText.setPosition(sf::Vector2f(30, 880));
    scoreValueText.setPosition(sf::Vector2f(160, 880));
    nameText.setFillColor(sf::Color::Yellow);
    nameValueText.setFillColor(sf::Color::Yellow);
    speedText.setFillColor(sf::Color::Yellow);
    speedValueText.setFillColor(sf::Color::Yellow);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreValueText.setFillColor(sf::Color::Yellow);

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (map[i][j] == 0) {
                pacmanBackground.setFillColor(backgroundColorBlack);
                pacmanBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(pacmanBackground);
            }
            if (map[i][j] == 1) {
                pacmanBackground.setFillColor(backgroundColorBlue);
                pacmanBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(pacmanBackground);
            }
            if (map[i][j] == 3) {
                pacmanBackground.setFillColor(backgroundColorGreen);
                pacmanBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(pacmanBackground);
            }
            if (map[i][j] == 4) {
                pacmanBackground.setFillColor(backgroundColorYellow);
                pacmanBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(pacmanBackground);
            }
            if (map[i][j] == 5) {
                pacmanBackground.setFillColor(backgroundColorBlack);
                pacmanBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(pacmanBackground);
                pacmanFood.setFillColor(backgroundColorWhite);
                pacmanFood.setPosition(sf::Vector2f(j * 30 + 15, i * 30 + 15));
                _window.draw(pacmanFood);
            }
            if (map[i][j] == 6) {
                pacmanBackground.setFillColor(backgroundColorRed);
                pacmanBackground.setPosition(sf::Vector2f(j * 30, i * 30));
                _window.draw(pacmanBackground);
            }
        }
    }
    _window.draw(nameText);
    _window.draw(nameValueText);
    _window.draw(speedText);
    _window.draw(speedValueText);
    _window.draw(scoreText);
    _window.draw(scoreValueText);
}

void Sfml::graphMenuDisplay()
{
    _window.clear();
    sf::Text welcomeText(_welcomeText, _font, 160);
    sf::Text promptText(_promptText, _font, 50);
    sf::Text chooseText(_chooseText, _font, 130);
    sf::Text validText(_validText, _font, 80);
    sf::RectangleShape nameRect(sf::Vector2f(600, 130));

    welcomeText.setPosition(sf::Vector2f(250, 30));
    promptText.setPosition(sf::Vector2f(110, 230));
    chooseText.setPosition(sf::Vector2f(300, 460));
    validText.setPosition(sf::Vector2f(1100, 370));
    nameRect.setPosition(sf::Vector2f(450, 350));

    welcomeText.setFillColor(sf::Color::Blue);
    promptText.setFillColor(sf::Color::Blue);
    chooseText.setFillColor(sf::Color::Blue);
    validText.setFillColor(sf::Color::Yellow);

    if (getIsNameChoosed())
        _window.draw(validText);
    _window.draw(welcomeText);
    _window.draw(promptText);
    _window.draw(nameRect);
    menuDrawName();
    menuDisplayNibbler();
    menuDisplayPacman();
}

void Sfml::menuDrawName() {
        sf::String string(_player_name);
        sf::Text nameText;

        nameText.setString(_player_name);
        nameText.setFont(_font);
        nameText.setCharacterSize(130);
        nameText.setPosition(sf::Vector2f(500, 315));
        nameText.setFillColor(sf::Color::Blue);
        _window.draw(nameText);
}

void Sfml::menuDisplayNibbler()
{
    // Rect
    _nibbler_btn.rect.setSize(sf::Vector2f(600, 330));
    _nibbler_btn.rect.setFillColor(sf::Color::Red);
    if (getIsNameChoosed())
        _nibbler_btn.rect.setFillColor(sf::Color::White);
    _nibbler_btn.rect.setPosition(sf::Vector2f(50, 650));
    _nibbler_btn.positionRect = sf::Vector2f(600, 330);

    // Text
    _nibbler_btn.text.setString(_nibblerText);
    _nibbler_btn.text.setFont(_font);
    _nibbler_btn.text.setCharacterSize(120);
    _nibbler_btn.text.setFillColor(sf::Color::Blue);
    _nibbler_btn.text.setPosition(sf::Vector2f(200, 750));

    _window.draw(_nibbler_btn.rect);
    _window.draw(_nibbler_btn.text);
}

void Sfml::menuDisplayPacman()
{
    // Rect
    _pacman_btn.rect.setSize(sf::Vector2f(600, 330));
    _pacman_btn.rect.setFillColor(sf::Color::Red);
    if (getIsNameChoosed())
        _pacman_btn.rect.setFillColor(sf::Color::White);
    _pacman_btn.rect.setPosition(sf::Vector2f(950, 650));
    _pacman_btn.positionRect = sf::Vector2f(600, 330);

    // Text
    _pacman_btn.text.setString(_pacmanText);
    _pacman_btn.text.setFont(_font);
    _pacman_btn.text.setCharacterSize(120);
    _pacman_btn.text.setFillColor(sf::Color::Blue);
    _pacman_btn.text.setPosition(sf::Vector2f(1200, 750));

    _window.draw(_pacman_btn.rect);
    _window.draw(_pacman_btn.text);

}

void Sfml::graphClear()
{
    _window.clear();
}

void Sfml::graphRefresh() {
    _window.display();
}

void Sfml::handleEvents()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            setKey("Escape");
        if (sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape)
                setKey("Escape");
            if (_event.key.code == sf::Keyboard::Backspace)
                setKey("Backspace");
            if (_event.key.code == sf::Keyboard::Return && !getIsNameChoosed())
                setKey("Return");
            if (_event.key.code == sf::Keyboard::Left)
                setKey("Left");
            if (_event.key.code == sf::Keyboard::Up)
                setKey("Up");
            if (_event.key.code == sf::Keyboard::Right)
                setKey("Right");
            if (_event.key.code == sf::Keyboard::Down)
                setKey("Down");
            if (_event.key.code > 96 && _event.key.code < 123)
                    _key = _event.key.code;
        }
        if (getIsNameChoosed()) {
            if (_event.type == sf::Event::MouseButtonPressed) {
                if (isBtnClicked(_event.mouseButton, _nibbler_btn)) {
                    setGameChoice(0);
                    setKey("Return");
                }
                if (isBtnClicked(_event.mouseButton, _pacman_btn)) {
                    setGameChoice(1);
                    setKey("Return");
                }
            }
        }
    }
}

bool Sfml::isBtnClicked(sf::Event::MouseButtonEvent event, game_btn_t button)
{
    sf::Vector2f rect_pos = button.rect.getPosition();
    sf::Vector2f rect_size = button.rect.getSize();

    if ((event.x >= rect_pos.x && event.x <= rect_pos.x + rect_size.x) &&
        event.y >= rect_pos.y && event.y <= rect_pos.y + rect_size.y)
    {
        return true;
    }
    return false;
}

void Sfml::transitionFrame(int i)
{
    sf::Text unText("1", _font, 100);
    sf::Text deuxText("2", _font, 100);
    sf::Text troisText("3", _font, 100);
    sf::Text secText(_secondsText.c_str(), _font, 100);
    troisText.setFillColor(sf::Color::Blue);
    deuxText.setFillColor(sf::Color::Blue);
    unText.setFillColor(sf::Color::Blue);
    secText.setFillColor(sf::Color::Blue);
    if (i == 0) {
        _window.clear();
        sf::Text startText(_startText.c_str(), _font, 100);
        startText.setFillColor(sf::Color::Blue);
        startText.setPosition(sf::Vector2f(500, 500));
        unText.setPosition(sf::Vector2f(1020, 500));
        deuxText.setPosition(sf::Vector2f(1020, 500));
        troisText.setPosition(sf::Vector2f(1020, 500));
        secText.setPosition(sf::Vector2f(1080, 500));
        _window.draw(startText);
        _window.draw(troisText);
        _window.draw(secText);
        _window.display();
        usleep(1000000);
        troisText.setFillColor(sf::Color::Black);
        _window.draw(troisText);
        _window.draw(deuxText);
        _window.display();
        usleep(1000000);
        deuxText.setFillColor(sf::Color::Black);
        _window.draw(deuxText);
        _window.draw(unText);
        _window.display();
        usleep(1000000);
    }
    if (i == 1) {
        _window.clear();
        sf::Text restartText(_restartText.c_str(), _font, 100);
        restartText.setFillColor(sf::Color::Blue);
        restartText.setPosition(sf::Vector2f(500, 500));
        unText.setPosition(sf::Vector2f(1020, 500));
        deuxText.setPosition(sf::Vector2f(1020, 500));
        troisText.setPosition(sf::Vector2f(1020, 500));
        secText.setPosition(sf::Vector2f(1080, 500));
        _window.draw(restartText);
        _window.draw(troisText);
        _window.draw(secText);
        _window.display();
        usleep(1000000);
        troisText.setFillColor(sf::Color::Black);
        _window.draw(troisText);
        _window.draw(deuxText);
        _window.display();
        usleep(1000000);
        deuxText.setFillColor(sf::Color::Black);
        _window.draw(deuxText);
        _window.draw(unText);
        _window.display();
        usleep(1000000);
    }
    if (i == 2) {
        _window.clear();
        sf::Text scoreboardText(_scoreboardText.c_str(), _font, 75);
        scoreboardText.setFillColor(sf::Color::Blue);
        scoreboardText.setPosition(sf::Vector2f(400, 500));
        _window.draw(scoreboardText);
        _window.display();
        usleep(5000000);
    }
}
