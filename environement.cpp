#include "header/environement.h"

Map::Map(){}

Map::Map (const std::string FILENAME, std::string MAP)
{
  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
  loadMap(MAP,3600);
}

void Map::setTexture(sf::RenderWindow* WINDOW, int* map)
{
  int tilecount =-1;

  for (int y = 0; y < hauteur ; y++)
  {
    for (int x = 0; x < largeur ;  x++)
    {
      tilecount++;
      int colonne = map[tilecount] % tilsetWidth; 
      int ligne = map[tilecount] / tilsetWidth; 


      sprite.setPosition(x * spriteLar, y * spriteLon);
      sprite.setTextureRect(sf::IntRect(colonne * spriteLar , ligne * spriteLon, spriteLar, spriteLon)); 

      WINDOW->draw(sprite); 
    }
  }

}

int* Map::getMap()
{
    return map;
}

sf::Sprite Map::getSprite() const
{
  return sprite;
}

void Map::loadMap(const std::string FILENAME, int taille)
{
  string* ligne = new string[taille];
  
  ifstream myFile (FILENAME);
  if(myFile.is_open())
  {
    getline(myFile,ligne[0],' ');
    for(int i=0;i<taille;i++)
    {
      getline(myFile,ligne[0],',');
      map[i] = stod(ligne[0]);
    }
  }
  else printf("erreur de chargement");
  delete [] ligne;
}