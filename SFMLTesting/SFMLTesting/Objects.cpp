// Objects cpp file
// Constructed off base class ObjectManager
// Grabs textures of base fruit and sliced fruit

#include "Objects.hpp"
#include "Utility.hpp"

Watermelon::Watermelon() : ObjectManager()
{
	this->setName("Watermelon"); // gives a unique name

	this->getFruitTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_Watermelon.png"); // load base texture from file
	this->changeSprite(this->getFruitTexture()); // sets texture of shape to base texture 
	this->getSlicedTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_WatermelonD1.png"); // load sliced texture from file
	 
}

Kiwi::Kiwi() : ObjectManager()
{
	this->setName("Kiwi");

	this->getFruitTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_Kiwi.png");
	this->changeSprite(this->getFruitTexture());
	this->getSlicedTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_KiwiD1.png");
}

Orange::Orange() : ObjectManager()
{
	this->setName("Orange");

	this->getFruitTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_Orange.png");
	this->changeSprite(this->getFruitTexture());
	this->getSlicedTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_OrangeD1.png");
}

Apple::Apple() : ObjectManager()
{
	this->setName("Apple");

	this->getFruitTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_Apple.png");
	this->changeSprite(this->getFruitTexture());
	this->getSlicedTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_AppleD1.png");
}

Coconut::Coconut() : ObjectManager()
{
	this->setName("Coconut");

	this->getFruitTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_Coconut.png");
	this->changeSprite(this->getFruitTexture());
	this->getSlicedTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_CoconutD1.png");
}

Dragonfruit::Dragonfruit() : ObjectManager()
{
	this->setName("Dragonfruit");

	this->getFruitTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_DragonFruit.png");
	this->changeSprite(this->getFruitTexture());
	this->getSlicedTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_DragonFruitD1.png");
}

Bomb::Bomb()
{
	this->setName("Bomb");

	this->getFruitTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_Bomb.png");
	this->changeSprite(this->getFruitTexture());
	this->getSlicedTexture().loadFromFile("Project\\Sources\\Assets\\Sprites\\sprite_BombD1.png");
}
