#include <SFML/Graphics.hpp>
#include <stdlib.h>
int main(){
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Love", sf::Style::Close | sf::Style::Resize);
    sf::Texture button1, button2, status, background;
    sf::Sprite Button1, Button2, Status, Background;
    button1.loadFromFile("button1.png");
    button2.loadFromFile("button2.png");
    status.loadFromFile("button3.png");
    background.loadFromFile("background.png");
    Button1.setTexture(button1);
    Button2.setTexture(button2);
    Status.setTexture(status);
    Background.setTexture(background);
    Background.setPosition(sf::Vector2f(0.f,0.f));
    Button1.setPosition(sf::Vector2f(100.f,700.f));
    Button2.setPosition(sf::Vector2f(1606.f,700.f));
    Status.setPosition(sf::Vector2f(-43.f,10.f));
    int ok = 0;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePos = sf::Mouse::getPosition();
            if( (float)mousePos.x >= Button2.getPosition().x && (float)mousePos.x <= Button2.getPosition().x + 214 && (float)mousePos.y >= Button2.getPosition().y && (float)mousePos.y <= Button2.getPosition().y + 172){
                int randX = rand() % (1920 - 214);
                int randY = rand() % (1080 - 172);
                Button2.setPosition(randX,randY);
            }
            if( (float)mousePos.x >= Button1.getPosition().x && (float)mousePos.x <= Button1.getPosition().x + 214 && (float)mousePos.y >= Button1.getPosition().y && (float)mousePos.y <= Button1.getPosition().y + 172){
                ok = 1;
            }
        }
        window.clear();
        window.draw(Background);
        window.draw(Button1);
        window.draw(Button2);
        if(ok) window.draw(Status);
        window.display();
    }
}

