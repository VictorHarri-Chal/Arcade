/*
** EPITECH PROJECT, 2022
** 2eme annee
** File description:
** Arcade: IGraphic.hpp
*/

#ifndef IGraphics_hpp
#define IGraphics_hpp

#include <string>
#include <vector>
#include <unistd.h>

class IGraphic {
    public:
        virtual ~IGraphic() = default;

        virtual void graphInit() = 0;
        virtual void graphDestroy() = 0;
        virtual void graphDisplay(std::vector<std::vector<int>> map, int speed, int score) = 0;
        virtual void graphMenuDisplay() = 0;
        virtual void graphClear() = 0;
        virtual void graphRefresh() = 0;
        virtual void handleEvents() = 0;
        virtual void transitionFrame(int i) = 0;

        virtual std::string getKeyPressed() const = 0;
        virtual std::string getPlayerName() const = 0;
        virtual bool getIsNameChoosed() const = 0;
        virtual bool getInMenu() const = 0;
        virtual int getGameChoice() const = 0;
        virtual int getCurrentLib() const = 0;

        virtual void setKey(std::string key) = 0;
        virtual void setPlayerName(std::string letter) = 0;
        virtual void setBackspacePlayerName() = 0;
        virtual void setIsNameChoosed(bool i) = 0;
        virtual void setInMenu(bool b) = 0;
        virtual void setGameChoice(int i) = 0;
        virtual void setCurrentLib(int i) = 0;
};

#endif
