#include <SFML/Graphics.hpp>
#include <iostream>


const std::string BG_PATH = "bg.png";
const std::string B_PATH = "ball.png";

const float ymax = 725.0 ;
const float acc = 3.0 ;
const float inc = 1.0 ;


int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    window.setFramerateLimit(60);

     sf::Texture BallTexture , BackgroundTexture;

    BackgroundTexture.loadFromFile(BG_PATH);

    sf::Sprite BallS , BackS;

    BackS.setTexture(BackgroundTexture);

    BallTexture.loadFromFile(B_PATH);
    BallTexture.setSmooth(true);

    BallS.setTexture(BallTexture);
    BallS.setOrigin(1726/2 , 1725/2.0);
    BallS.scale(100.0/1726,100.0/1725);
    
    float x = 450.0 , y = 0.0 ;
    float vy = 0.0 , vx = 0.0;
    float angle = 0.0 ; 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        	vx -= inc ;
        	angle = int(angle - 15 +360)%360;
                
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        	vy = -50 ;
        	//angle = int(angle - 15 +360)%360;
                
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        	vx += inc ;
        	angle = int(angle + 15 + 360)%360;
            
        }

        // clear
        window.clear();
        

        //logic for ball movement

        vy += acc ;

        y += vy ;
        x += vx;

        vx *= 0.8 ;
        y = std::min(y , ymax);

        if(y == ymax) vy *= -0.95 ;

        BallS.setPosition(x,y);
        BallS.setRotation(angle);

        //drawing 
        window.draw(BackS);
        window.draw(BallS);
        window.display();
    }

    return 0;
}