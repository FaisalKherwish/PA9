#include "ObjectManager.hpp"

/*
Game wrapper hpp class
Displays Main menu, game screen, and game over screen
Contains the lives, combo, points and high score for the current game
*/

class Game
{
public:
	Game(); // constructor

	// 3 Window states 
	bool mainMenu();
	void runGame();
	void gameOver();

	// Helpers
	void respawnFruit(std::vector<std::unique_ptr<ObjectManager>>& fruitObjects); 
	void drawBackground(sf::RenderWindow& window, const int state);


private:
	// Data members 
	int mLives;
	int mCombo;
	int mPoints;
	int mHighScore;

	// Current clock to spawn fruits
	sf::Clock fruitClock;
};