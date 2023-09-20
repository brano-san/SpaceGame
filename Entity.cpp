#include "Entity.h"

Entity::Entity()
	: _hitbox(new sf::RectangleShape())
{

}

Entity::~Entity()
{
	delete this->_hitbox;
}
