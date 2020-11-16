#include "header/collision.h"

Collision::Collision(){}

Collision::Collision (const std::string FILENAME, std::string MAP)
{
  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
  loadCollision(MAP, 3600);
}

void Collision::setTexture(sf::RenderWindow* WINDOW)
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

int* Collision::getMap()
{
    return map;
}

sf::Sprite Collision::getSprite() const
{
  return sprite;
}

void Collision::collision(Player* joueur)
{
    if( map[this->getTile(joueur->getGaucheHautX(),joueur->getGaucheHautY())]==0 ||
        map[this->getTile(joueur->getDroiteHautX(),joueur->getDroiteHautY()-1)]==0 ||
        map[this->getTile(joueur->getDroiteBasX(),joueur->getDroiteBasY()+1)]==0 ||
        map[this->getTile(joueur->getGaucheBasX(),joueur->getGaucheBasY())]==0)
    {
        joueur->setOldPosition();
    }
    else joueur->setNewPosition();
}

int Collision::getTile(float X, float Y) const
{
  int playerTileX = (int)X/spriteLar;
  int playerTileY = (int)Y/spriteLon;
  int spriteNumber = largeur*playerTileY+playerTileX;
  return spriteNumber;
}

void Collision::loadCollision(const std::string FILENAME, int taille)
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
