#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "collision.cpp"
#include "environement.cpp"
#include "player.cpp"
#include "view.cpp"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Temple of Garb Age");
    window.setFramerateLimit(60);
    Player* joueur = new Player("sprite_char/playersprite.png", 40,300);
    Map* map =  new Map("sprites/assetnull.png","carte/test1.txt");
    Collision* colli = new Collision("sprites/assetnull.png", "carte/test1col.txt"); 
    sf::Clock clock;
    View* view1 = new View(640,360);
    int animation = 0;

    while (window.isOpen())
    {
        view1->recentrer(joueur);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        animation += clock.restart().asMilliseconds();
        if(animation>joueur->getframeDuration()) joueur->setanimation(1);
        if (animation>joueur->getframeDuration()*2)
        {
            animation =0;
            joueur->setanimation(0);
        }
        window.clear();
        window.setView(view1->getView());
        colli->setTexture(&window);
        joueur->mouvement();
        colli->collision(joueur);
        map->setTexture(&window, map->getMap());
        window.draw(joueur->getSprite());
        window.display();
    }
    delete joueur;
    delete map;
    return 0;
}
