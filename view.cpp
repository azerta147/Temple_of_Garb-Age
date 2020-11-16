#include "header/view.h"

View::View(){}

View::View(int x,int y)
{
    setLargeur(x);
    setHauteur(y);
    camera.setSize(x,y);
}

sf::View View::getView()
{
    return camera;
}

int View::getLargeur()
{
    return largeur;
}

int View::getHauteur()
{
    return hauteur;
}

void View::setView(sf::View view)
{
    this->camera = view;
}

void View::setLargeur(int largeur)
{
    this->largeur = largeur;
}

void View::setHauteur(int hauteur)
{
    this->hauteur = hauteur;
}

void View::recentrer(Player* player)
{
    camera.setCenter(player->getSprite().getPosition());
}