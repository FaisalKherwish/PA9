// Object Manager File
// Manages the objects / fruits
// Base class build to use inheritence

#ifndef PA9
#define PA9
// includes
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

class ObjectManager
{
public:
	ObjectManager(); // constructor
	~ObjectManager(); // destructor

	// setters
	void setSprite(sf::Texture& texture);
	void setName(const std::string newName);
	void setVelocity(const int newVelocity = 0);
	void setSliced(bool newBool);

	// getters
	sf::CircleShape& getShape();
	std::string getName() const;
	bool getSliced() const;
	sf::Texture& getFruitTexture();
	sf::Texture& getSlicedTexture();

	// Functions
	void changeColor(sf::Color newColor); // color change
	void changeSprite(sf::Texture& sprite); // sprite change
	void draw(sf::RenderWindow& window); // draws shape
	void gravity(); // "gravity" simulator

private:
	// Data members
	sf::CircleShape shape;
	std::string name;
	sf::Vector2f mVelocity;
	// Textures
	sf::Texture fruitSprite;
	sf::Texture slicedSprite;
	// Sliceable
	bool is_Sliced;
};

#endif