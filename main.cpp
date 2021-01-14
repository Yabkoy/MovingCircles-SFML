#include <iostream>
#include <SFML/Graphics.hpp>
#include <myObjects.h>
#include <time.h>
#include <fstream>


using namespace std;

int heigh;
int weigh;

int testFoloat = 2;

float mainScaleShape = 1;
int mainRandomjednoGlobal = 0;
float mainMinusNumber = 0.001;
int allColors[3];


int main()
{
    srand(time(NULL));

    ifstream resConfig;
    string out[3];
    resConfig.open("myRes.set");

    if(resConfig.is_open())
    {

        getline(resConfig, out[0]);
        getline(resConfig, out[1]);
        getline(resConfig, out[2]);
    }
    cout<<out[1]<<" - "<<out[0]<<endl;
    heigh = stoi(out[0]);
    weigh = stoi(out[1]);
    //sf::Style thisS(sf::);

    sf::Uint32 myStyle = (stoi(out[2]) == 0)? sf::Style::Default : sf::Style::Fullscreen;


    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow RW(sf::VideoMode(weigh, heigh,32), "RandomCircle", myStyle, settings);



    myObjects M1;


    while(RW.isOpen())
    {
        sf::Event mainEvent;

        while(RW.pollEvent(mainEvent))
        {
            if(mainEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                RW.close();
            }

            if(mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::Equal)
            {
                mainMinusNumber = mainMinusNumber + 0.0001;
                cout<<"+"<<endl;
            }
            if(mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::Hyphen )
            {
                mainMinusNumber = mainMinusNumber - 0.0001;
                cout<<"-"<<endl;
            }


        }
        RW.clear(sf::Color::Black);

        M1.draw(RW, mainRandomjednoGlobal, mainMinusNumber, mainScaleShape, heigh, weigh, allColors);
        string t1 = to_string(mainRandomjednoGlobal);
        M1.showText(RW, 10, 10, t1);
        string t2 = to_string(mainMinusNumber);

        M1.showText(RW, 10, 40, t2);


        RW.display();

    }


    return 0;
}
