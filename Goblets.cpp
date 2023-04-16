#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


struct Goblet
{
    int x = 0;
    int y = 400;

};

struct Ball
{
    int x = 0;
    int y = 700;
    int position = 2;
};


int main()
{
    srand(time(0));

    const int width(1920), heigth(1080);
    const int gobletSize(400), ballSize(200);
    int firstX(200), secondX(800), thirdX(1400);
    int copyFirst(200), copySecond(800), copyThird(1400);

    sf::RenderWindow window(sf::VideoMode(width, heigth), "Goblets");

    Texture backgroundTexture, gobletTexture, ballTexture, button1Texture,
        button2Texture, button3Texture, button4Texture, button5Texture, button6Texture;

    Goblet Goblet1, Goblet2, Goblet3;

    Ball ballStruct;

    Goblet1.x = firstX;
    Goblet2.x = secondX;
    Goblet3.x = thirdX;

    ballStruct.x = secondX + 100;

    backgroundTexture.loadFromFile("images/background.jpg");
    gobletTexture.loadFromFile("images/goblet.png");
    ballTexture.loadFromFile("images/ball.png");
    button1Texture.loadFromFile("images/button100.png");
    button2Texture.loadFromFile("images/button200.png");
    button3Texture.loadFromFile("images/button500.png");
    button4Texture.loadFromFile("images/button1000.png");
    button5Texture.loadFromFile("images/button5000.png");
    button6Texture.loadFromFile("images/button50000.png");

    Sprite background(backgroundTexture), goblet1(gobletTexture),
        goblet2(gobletTexture), goblet3(gobletTexture), ball(ballTexture),
        button1(button1Texture), button2(button2Texture), button3(button3Texture),
        button4(button4Texture), button5(button5Texture), button6(button6Texture);

    goblet1.setPosition(Goblet1.x, Goblet1.y);
    goblet2.setPosition(Goblet2.x, Goblet2.y);
    goblet3.setPosition(Goblet3.x, Goblet3.y);
    ball.setPosition(ballStruct.x, ballStruct.y);
    button1.setPosition(600, 820);
    button2.setPosition(720, 820);
    button3.setPosition(840, 820);
    button4.setPosition(600, 900);
    button5.setPosition(720, 900);
    button6.setPosition(840, 900);

    bool move = false;
    bool isMoveFirst = false, isMoveSecond = false, isMoveThird = false;

    int mix = 0;
    int a = 0;
    const int mixTimes = 4;

    int balance = 1000;
    int bet = 0;
    bool once = false;

    Font font;
    font.loadFromFile("sprites/ARLRDBD.TTF");
    Text balanceText;
    balanceText.setFont(font);
    balanceText.setFillColor(Color::White);
    balanceText.setCharacterSize(40);
    balanceText.setPosition(width / 2, 100);
    
    balanceText.setString(to_string(balance) + " $");
  
    Clock clock;

    float timer(0), delay(0.01f);

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        if (!move && mix > 0)
        {
            a = rand() % 3;
            mix--;   
            move = true;
        }

        if (event.type == Event::MouseButtonPressed)
            if (event.key.code == Mouse::Left && !move)
            {
                if (goblet1.getGlobalBounds().contains(pos.x, pos.y))isMoveFirst = true;
                if (goblet2.getGlobalBounds().contains(pos.x, pos.y))isMoveSecond = true;
                if (goblet3.getGlobalBounds().contains(pos.x, pos.y))isMoveThird = true;
    
                if (button1.getGlobalBounds().contains(pos.x, pos.y) && balance >= 100)
                {
                    balance -= 100;
                    bet = 100;
                    mix = mixTimes;
                    once = false;
                    isMoveFirst = false;
                    isMoveSecond = false;
                    isMoveThird = false;
                }
                else if (button2.getGlobalBounds().contains(pos.x, pos.y) && balance >= 200)
                {
                    balance -= 200;
                    bet = 200;
                    mix = mixTimes;
                    once = false;
                    isMoveFirst = false;
                    isMoveSecond = false;
                    isMoveThird = false;
                }
                else if (button3.getGlobalBounds().contains(pos.x, pos.y) && balance >= 500)
                {
                    balance -= 500;
                    bet = 500;
                    mix = mixTimes;
                    once = false;
                    isMoveFirst = false;
                    isMoveSecond = false;
                    isMoveThird = false;
                }
                else if (button4.getGlobalBounds().contains(pos.x, pos.y) && balance >= 1000)
                {
                    balance -= 1000;
                    bet = 1000;
                    mix = mixTimes;
                    once = false;
                    isMoveFirst = false;
                    isMoveSecond = false;
                    isMoveThird = false;
                }
                else if (button5.getGlobalBounds().contains(pos.x, pos.y) && balance >= 5000)
                {
                    balance -= 5000;
                    bet = 5000;
                    mix = mixTimes;
                    once = false;
                    isMoveFirst = false;
                    isMoveSecond = false;
                    isMoveThird = false;
                }
                else if (button6.getGlobalBounds().contains(pos.x, pos.y) && balance >= 50000)
                {
                    balance -= 50000;
                    bet = 50000;
                    mix = mixTimes;
                    once = false;
                    isMoveFirst = false;
                    isMoveSecond = false;
                    isMoveThird = false;
                }
                if (timer > delay)
                {

                    Goblet1.y = 400;
                    goblet1.setPosition(Goblet1.x, Goblet1.y);
                    Goblet2.y = 400;
                    goblet2.setPosition(Goblet2.x, Goblet2.y);
                    Goblet3.y = 400;
                    goblet3.setPosition(Goblet3.x, Goblet3.y);
                
                    timer = 0;
                }
            
            }

        if (timer > delay)
        {
            if (isMoveFirst && !once)
            {
                if (bet > 0)Goblet1.y = 200;
                if (ballStruct.position == 1)balance += bet * 3;
                once = true;
                isMoveFirst = false;
                goblet1.setPosition(Goblet1.x, Goblet1.y);
                timer = 0;
            }
            if (isMoveSecond && !once)
            {
                if (bet > 0)Goblet2.y = 200;
                if (ballStruct.position == 2)balance += bet * 3;
                once = true;
                isMoveSecond = false;
                goblet2.setPosition(Goblet2.x, Goblet2.y);
                timer = 0;
            }
            if (isMoveThird && !once)
            {
                if (bet > 0)Goblet3.y = 200;
                if (ballStruct.position == 3)balance += bet * 3;
                once = true;
                isMoveThird = false;
                goblet3.setPosition(Goblet3.x, Goblet3.y);
                timer = 0;
            }
        }

        //first <-> second
        if (a == 0 && move && Goblet1.x != copySecond)
        {
            if (timer > delay)
            {
                switch (ballStruct.position)
                {
                case 1:
                    ballStruct.x += 20;
                    ball.setPosition(ballStruct.x, ballStruct.y);
                    if (ballStruct.x == secondX + 100)ballStruct.position = 2;
                    break;

                case 2:
                    ballStruct.x -= 20;
                    ball.setPosition(ballStruct.x, ballStruct.y);
                    if (ballStruct.x == firstX + 100)ballStruct.position = 1;
                    break;
                }

                Goblet1.x += 20;
                Goblet2.x -= 20;
                goblet1.setPosition(Goblet1.x, Goblet1.y);
                goblet2.setPosition(Goblet2.x, Goblet2.y);

                timer = 0;
            }
            if (Goblet1.x == copySecond)
            {
                Goblet1.x = firstX;
                Goblet2.x = secondX;
                goblet1.setPosition(Goblet1.x, Goblet1.y);
                goblet2.setPosition(Goblet2.x, Goblet2.y);
                move = false;
            }
        }

        //first <-> third
        if (a == 1 && move && Goblet1.x != copyThird)
        {
            if (timer > delay)
            {

                switch (ballStruct.position)
                {
                case 1:
                    ballStruct.x += 20;
                    ball.setPosition(ballStruct.x, ballStruct.y);
                    if (ballStruct.x == thirdX + 100)ballStruct.position = 3;
                    break;

                case 3:
                    ballStruct.x -= 20;
                    ball.setPosition(ballStruct.x, ballStruct.y);
                    if (ballStruct.x == firstX + 100)ballStruct.position = 1;
                    break;
                }
                Goblet1.x += 20;
                Goblet3.x -= 20;
                goblet1.setPosition(Goblet1.x, Goblet1.y);
                goblet3.setPosition(Goblet3.x, Goblet3.y);
                timer = 0;
            }
            if (Goblet1.x == copyThird)
            {
                Goblet1.x = firstX;
                Goblet3.x = thirdX;
                goblet1.setPosition(Goblet1.x, Goblet1.y);
                goblet3.setPosition(Goblet3.x, Goblet3.y);
                move = false;
            }

        }

        //second <-> third
        if (a == 2 && move && Goblet2.x != copyThird)
        {
            if (timer > delay)
            {
                switch (ballStruct.position)
                {
                case 2:
                    ballStruct.x += 20;
                    ball.setPosition(ballStruct.x, ballStruct.y);
                    if (ballStruct.x == thirdX + 100)ballStruct.position = 3;
                    break;

                case 3:
                    ballStruct.x -= 20;
                    ball.setPosition(ballStruct.x, ballStruct.y);
                    if (ballStruct.x == secondX + 100)ballStruct.position = 2;
                    break;
                }

                Goblet2.x += 20;
                Goblet3.x -= 20;
                goblet2.setPosition(Goblet2.x, Goblet2.y);
                goblet3.setPosition(Goblet3.x, Goblet3.y);
                timer = 0;
            }
            if (Goblet2.x == copyThird)
            {
                Goblet2.x = secondX;
                Goblet3.x = thirdX;
                goblet2.setPosition(Goblet2.x, Goblet2.y);
                goblet3.setPosition(Goblet3.x, Goblet3.y);

                move = false;
            }

        }

        balanceText.setString(to_string(balance) + " $");

        window.clear();
        window.draw(background);
        window.draw(ball);
        window.draw(goblet1);
        window.draw(goblet2);
        window.draw(goblet3);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
        window.draw(button5);
        window.draw(button6);
        window.draw(balanceText);

        window.display();
    }

    return 0;
}