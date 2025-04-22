// ObjectManager.cpp
// Function initializers 

#include "ObjectManager.hpp"
#include "Utility.hpp"

ObjectManager::ObjectManager() // constructor
{
	// base shape traits
	this->shape = sf::CircleShape(50.f);
	this->name = "";
	this->is_Sliced = false;
	shape.setFillColor(sf::Color::White);
	this->getShape().setPosition(sf::Vector2f(rng() % 880 + 100, 980));

	this->mVelocity = sf::Vector2f(0.f, -500.f); // starts velocity going "up" the screen
}

ObjectManager::~ObjectManager() // "destroys" objects by setting them transparent
{
	// this->shape.setFillColor(sf::Color::Transparent);
}

sf::CircleShape& ObjectManager::getShape() // get shape
{
	return this->shape;
}

void ObjectManager::gravity() // decreases velocity by an amount and moves by that amount
{
	// velocity will start moving shape up, over time will move it back down simulation gravity
	if (mVelocity.y < 0) mVelocity.y += 0.19f;
	else mVelocity.y += 0.19f;
	
	shape.move(mVelocity* 0.0015f);
}

void ObjectManager::setSprite(sf::Texture& texture) // set sprite
{
	this->shape.setTexture(&texture);
}

void ObjectManager::setName(const std::string newName) // set object name
{
	this->name = newName;
}

void ObjectManager::setVelocity(const int newVelocity) // set new velocity
{
	this->mVelocity.y = newVelocity;
}

void ObjectManager::setSliced(bool newBool) // sliceable change
{
	this->is_Sliced = newBool;
}

std::string ObjectManager::getName() const // gets name of fruit object
{
	return this->name;
}

bool ObjectManager::getSliced() const // sliceable?
{
	return this->is_Sliced;
}

sf::Texture& ObjectManager::getFruitTexture() // initial fruit texture
{
	return this->fruitSprite;
}

sf::Texture& ObjectManager::getSlicedTexture() // sliced fruit texture
{
	return this->slicedSprite;
}

void ObjectManager::changeColor(sf::Color newColor) // set new color
{
	this->shape.setFillColor(newColor);

}

void ObjectManager::changeSprite(sf::Texture& sprite) // change sprite texture
{
	this->shape.setTexture(&sprite);
}

void ObjectManager::draw(sf::RenderWindow& window) // draws shape
{
	window.draw(this->shape);
}

