#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <string.h>
#include "player.h"
using namespace std;


class Collision
{
private:
    int largeur = 80;
    int hauteur = 45;

    float spriteLar = 16; 
    float spriteLon = 16; 

    int tilsetWidth = 64;
    int tilsetHeight = 16;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::VertexArray vertices;

    int map[3600];

public:

    Collision();
    Collision (const std::string FILENAME, std::string MAP);
    void setTexture ( sf::RenderWindow* WINDOW);
    int *getMap();
    sf::Sprite getSprite() const;
    void collision(Player* joueur);
    int getTile(float X, float Y) const;
    void loadCollision(const std::string FILENAME, int taille);
};
#endif
