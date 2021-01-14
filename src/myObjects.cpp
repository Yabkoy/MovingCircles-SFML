#include "myObjects.h"



void myObjects::draw(sf::RenderWindow &win, int &mainRandomjedno, float &thisMinus, float &mainScaleShapeClass, int &mainHeigh, int &mainWeigh, int* randomColors)
{
    if(mainScaleShapeClass > 0.004)
    {
        mainScaleShapeClass = mainScaleShapeClass - thisMinus;
    }
    else
    {
        mainScaleShapeClass = 1;
        mainRandomjedno = rand()%50+2;
        for(int i=0; i<=3; i++)
        {
            randomColors[i] = rand()%255;
        }

    }
    if(mainScaleShapeClass > 1)
    {
        mainScaleShapeClass = 0.004;
        mainRandomjedno = rand()%50+2;
        for(int i=0; i<=3; i++)
        {
            randomColors[i] = rand()%255;
        }
    }


    float radiumForShape = (mainHeigh >= mainWeigh)? mainWeigh-100 : mainHeigh-100;
    sf::CircleShape mainShape(radiumForShape, mainRandomjedno+1);
    mainShape.setOrigin(sf::Vector2f(radiumForShape, radiumForShape));
    mainShape.setPosition(sf::Vector2f(mainWeigh/2, mainHeigh/2));
    mainShape.setOutlineThickness(100.f);
    mainShape.setOutlineColor(sf::Color(randomColors[0], randomColors[1], randomColors[2]));
    mainShape.setFillColor(sf::Color::Black);


    mainShape.scale(sf::Vector2f(mainScaleShapeClass, mainScaleShapeClass));

    win.draw(mainShape);

}


void myObjects::showText(sf::RenderWindow &win1, float Wx, float Wy, std::string mainTXT)
{
    sf::Font font;
    if (!font.loadFromFile("FallingSky-JKwK.otf"))
    {
        std::cout<<"ERROR FONT!\n";
    }
    sf::Text myShowText;
    myShowText.setFont(font);
    //std::string thisRand = to_string(mainRandomjedno);

    myShowText.setString(mainTXT);
    myShowText.setCharacterSize(25);
    myShowText.setFillColor(sf::Color::White);
    myShowText.setPosition(sf::Vector2f(Wx, Wy));
    win1.draw(myShowText);
}

