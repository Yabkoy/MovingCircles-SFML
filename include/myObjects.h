#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef MYOBJECTS_H
#define MYOBJECTS_H


class myObjects
{
    public:
        void draw(sf::RenderWindow &win, int &mainRandomjedno, float &thisMinus, float &mainScaleShapeClass, int &mainHeigh, int &mainWeigh, int* randomColors);
        void showText(sf::RenderWindow &win1, float Wx, float Wy, std::string mainTXT);

};

#endif // MYOBJECTS_H
