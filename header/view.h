#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
#include "view.h"
#include "player.h"
#include "environement.h"
using namespace std;

class View
{
private:
    sf::View camera;
    int largeur = 640;
    int hauteur = 360;

public:
    View();
    View(int x, int y);

    sf::View getView();
    int getLargeur();
    int getHauteur();

    void setView(sf::View view);
    void setLargeur(int largeur);
    void setHauteur(int hauteur);
    void recentrer(Player* player);

};
#endif