#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

class Player
{
private:

    // Coordonées sur la carte 2D
    float x;
    float y;

    // taille de la texture
    float spriteLar = 33; 
    float spriteLon = 55; 
    int frameDuration = 100;
    int animation;
      
    // Rendu 2d du personnage
    sf::Texture texture;
    sf::Sprite sprite;

    bool colli;

public:

    Player();
    Player(const std::string FILENAME, float x, float y);

    sf::Sprite getSprite() const;

    void animations(int position);
    void mouvement();

    void setColli(bool colli);
    void setNewPosition();
    void setOldPosition();
    void setanimation(int ANIMATION);

    int getframeDuration();
    float getGaucheHautX();
    float getDroiteHautX();
    float getGaucheHautY();
    float getDroiteHautY();
    float getDroiteBasY();
    float getDroiteBasX();
    float getGaucheBasY();
    float getGaucheBasX();
};
#endif