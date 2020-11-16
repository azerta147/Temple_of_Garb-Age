#include "header/player.h"


Player::Player(){}

Player::Player(const std::string FILENAME, float x, float y)
{
  texture.loadFromFile(FILENAME);
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0,0,spriteLar,spriteLon));
  this->x = x;
  this->y = y;
  sprite.setPosition(x,y);
  colli = false;
  this->animation = 0;
}

void Player::mouvement()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    sprite.move(3,0);
    sprite.setTextureRect(sf::IntRect(spriteLar*0,0,spriteLar,spriteLon));
    animations(0);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    sprite.move(-3,0);
    sprite.setTextureRect(sf::IntRect(spriteLar*1,0,spriteLar,spriteLon));
    animations(1);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    sprite.move(0,-3);
    sprite.setTextureRect(sf::IntRect(spriteLar*2,0,spriteLar,spriteLon));
    animations(2);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    sprite.move(0,3);
    sprite.setTextureRect(sf::IntRect(spriteLar*3,0,spriteLar,spriteLon));
    animations(3);
  }
}

void Player::setColli(bool colli)
{
    this->colli = colli;
}

void Player::setOldPosition()
{
    sprite.setPosition(x,y);
}

void Player::setNewPosition()
{
    x=sprite.getPosition().x;
    y=sprite.getPosition().y;
}

void Player::setanimation(int animation)
{
  this->animation = animation;
}

sf::Sprite Player::getSprite() const
{
  return sprite;
}

void Player::animations(int position)
{
  sprite.setTextureRect(sf::IntRect(spriteLar*position,spriteLon*this->animation,spriteLar,spriteLon));
}

int Player::getframeDuration()
{
  return this->frameDuration;
}

float Player::getGaucheHautX()
{
  return sprite.getPosition().x;
}

float Player::getDroiteHautX()
{
  return sprite.getPosition().x+spriteLar;
}

float Player::getGaucheHautY()
{
  return sprite.getPosition().y;
}

float Player::getDroiteBasY()
{
  return sprite.getPosition().y+spriteLon;
}
float Player::getGaucheBasX()
{
  return sprite.getPosition().x;
}

float Player::getDroiteBasX()
{
  return sprite.getPosition().x+spriteLar;
}

float Player::getGaucheBasY()
{
  return sprite.getPosition().y+spriteLon;
}

float Player::getDroiteHautY()
{
  return sprite.getPosition().y;
}

