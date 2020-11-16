#ifndef ENVIRONEMENT_H
#define ENVIRONEMENT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <string.h>
using namespace std;

class Map
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

    Map();
    Map (const std::string FILENAME, std::string MAP);
    void setTexture ( sf::RenderWindow* WINDOW, int* map);
    int *getMap();
    sf::Sprite getSprite() const;
    void loadMap(const std::string FILENAME, int taille);
};
#endif