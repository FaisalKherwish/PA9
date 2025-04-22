#pragma once

// includes
#include "Game.hpp"
#include "Objects.hpp"
#include "Utility.hpp"

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


Game::Game() // constructor, default values for data members
{
	this->mLives = 3;
	this->mCombo = 0;
	this->mPoints = 0;
	this->mHighScore = 0;
}

// WINDOW STATES
// 
// Main menu window 
// Return type determines whether game is continued/started
bool Game::mainMenu()
{
	sf::RenderWindow window(sf::VideoMode({ 1080, 1080 }), "Fruit Slicers");

	sf::Font font("Project\\Sources\\Japers-DK3W.ttf"); // load font

	// Texts used in window
	sf::Text titleText(font); // Title text
	titleText.setString("Fruit Slicers");
	titleText.setCharacterSize(48);
	titleText.setFillColor(sf::Color::White);
	titleText.setStyle(sf::Text::Bold);
	titleText.setPosition(sf::Vector2f(400, 500));

	sf::Text startText(titleText); // Start
	startText.setString("Press Enter to start");
	startText.setPosition(sf::Vector2f(330, 600));

	sf::Text exitText(titleText); // Exit
	exitText.setString("Press Escape to Exit");
	exitText.setPosition(sf::Vector2f(330, 700));

	sf::Text hsText(titleText); // Highscore
	hsText.setString("Highscore: " + std::to_string(this->mHighScore));
	hsText.setPosition(sf::Vector2f(20, 0));
	

	while (window.isOpen()) // default window game loop
	{
		while (const std::optional event = window.pollEvent()) // if window is closed
		{
			if (event->is<sf::Event::Closed>()) window.close();
		}

		// Render and display
		window.clear();
		window.draw(titleText);
		window.draw(startText);
		window.draw(exitText);
		window.draw(hsText);
		window.display();

		// Exits and returns whether game should start/continue
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			return true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			return false;
		}
	}
	
}

// Main game wrapper
void Game::runGame()
{
	sf::RenderWindow gameWindow(sf::VideoMode({ 1080,1080 }), "Slice em!"); // windows

	// TIMER SETUP
	sf::Clock gameClock;
	int seconds = 0, minutes = 0;

	// font loadings
	sf::Font textFont;
	textFont.openFromFile("C:\\Users\\ThemN\\OneDrive\\Desktop\\Project\\Sources\\Japers-DK3W.ttf");

	sf::Text minuteText(textFont); // Minutes for timer
	minuteText.setString(std::to_string(minutes) + ":");
	minuteText.setCharacterSize(24);
	minuteText.setFillColor(sf::Color::White);
	minuteText.setStyle(sf::Text::Bold);
	minuteText.setPosition(sf::Vector2f(980, 0));

	sf::Text secondsText(minuteText); // Seconds for timer
	secondsText.setString(std::to_string(seconds));
	secondsText.setPosition(sf::Vector2f(1000, 0));

	sf::Text comboText(minuteText); // Text for combo display
	comboText.setString(std::to_string(this->mCombo));
	comboText.setPosition(sf::Vector2f(-100, -100));

	sf::Text livesText(minuteText); // Text for lives display
	livesText.setString("Lives " + std::to_string(this->mLives));
	livesText.setPosition(sf::Vector2f(20, 0));

	sf::Text pointsText(minuteText); // Text for points display
	pointsText.setString("Points " + std::to_string(this->mPoints));
	pointsText.setPosition(sf::Vector2f(20, 30));

	// Vector of fruit objects
	std::vector<std::unique_ptr<ObjectManager>> fruitObjects;

	while (gameWindow.isOpen()) // default game loop window
	{
		while (const std::optional event = gameWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) gameWindow.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // whilst holding the left mouse button down
			{
				// Gets mouse position and converts it to the world position from window position
				sf::Vector2i mouseWindowPosition = sf::Mouse::getPosition(gameWindow);
				sf::Vector2f mouseWorldPosition = gameWindow.mapPixelToCoords(sf::Vector2i(mouseWindowPosition.x, mouseWindowPosition.y));

				for (const auto& fruit : fruitObjects) // loops through each fruit in vector fruit objects
				{
					// if the shapes bounds has the mouse and fruit hasnt been sliced
					if (fruit->getShape().getGlobalBounds().contains(mouseWorldPosition) && !fruit->getSliced() )
					{
						// fruit has now been sliced
						fruit->setSliced(true);
						// Fruit must not be a bomb
						if (fruit->getName() == "Bomb")
						{
							// if it is a bomb, combo resets, lives decreases, Text is updated
							this->mCombo = 0;
							this->mLives--;
							comboText.setString("COMBO LOST!");
							livesText.setString("Lives " + std::to_string(this->mLives));
						}
						else // Non bomb fruit
						{
							// Points goes up by 1 and scales with combo
							this->mPoints += 1 + mCombo;
							this->mCombo++;
							comboText.setString(std::to_string(this->mCombo));
							pointsText.setString("Points " + std::to_string(this->mPoints));
						}
						// sprite changes to sliced version, combo text appears on mouse
						fruit->changeSprite(fruit->getSlicedTexture());
						comboText.setPosition(mouseWorldPosition);
					}
				}
			}
		}

		// Update game states
		minuteText.setString(std::to_string(minutes) + ":"); // timers
		secondsText.setString(std::to_string(seconds));

		seconds = gameClock.getElapsedTime().asSeconds();
		if (seconds == 60) // once seconds is 60 change to minutes
		{
			seconds = 0;
			gameClock.reset();
			gameClock.start();
			if (gameClock.getElapsedTime().asMilliseconds() == 0)
			{
				minutes += 1;
			}
		}

		// new fruit spawning
		if (this->fruitClock.getElapsedTime().asSeconds() >= spawnInterval(minutes, seconds))
		{
			respawnFruit(fruitObjects);
			fruitClock.restart();
		}

		// fruit position update
		for (int i = 0; i < fruitObjects.size(); i++)
		{
			auto& fruit = fruitObjects[i];
			fruit->gravity(); // sends fruit up and down

			
			if (fruit->getShape().getPosition().y > 1080) // fruit is out of bounds
			{
				if (!fruit->getSliced() && fruit->getName() != "Bomb") // not a bomb object
				{
					// decreases lives for fruits that arent bombs and unsliced
					this->mLives--;
					livesText.setString("Lives " + std::to_string(this->mLives));
				}
				// Removes fruit from vector
				fruitObjects.erase(fruitObjects.begin() + i);
				i--; 
			}
		}

		// render
		gameWindow.clear();

		// drawing
		gameWindow.draw(minuteText);
		gameWindow.draw(secondsText);
		gameWindow.draw(comboText);
		gameWindow.draw(livesText);
		gameWindow.draw(pointsText);

		for (const auto& fruit : fruitObjects)
		{
			fruit->draw(gameWindow);
		}

		gameWindow.display();

		// Out of lives, returns and goes to game over
		if (this->mLives <= 0)
		{
			if (this->mPoints > this->mHighScore) this->mHighScore = this->mPoints;
			return;
		}
	}

}

void Game::gameOver() // out of live screen
{
	sf::RenderWindow window(sf::VideoMode({ 1080, 1080 }), "Game Over!");

	sf::Font font("C:\\Users\\ThemN\\OneDrive\\Desktop\\Project\\Sources\\Japers-DK3W.ttf");

	sf::Text gOverText(font); // game over text
	gOverText.setString("GAME OVER");
	gOverText.setCharacterSize(48);
	gOverText.setFillColor(sf::Color::White);
	gOverText.setStyle(sf::Text::Bold);
	gOverText.setPosition(sf::Vector2f(400, 500));

	sf::Text continueText(gOverText); // continuation text
	continueText.setString("Press Enter to continue");
	continueText.setPosition(sf::Vector2f(330, 600));

	sf::Text hsText(gOverText); // highscore
	hsText.setString("Highscore: " + std::to_string(this->mHighScore));
	hsText.setPosition(sf::Vector2f(20, 0));

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) window.close();
		}

		// render and draw
		window.clear();
		window.draw(gOverText);
		window.draw(continueText);
		window.draw(hsText);
		window.display();

		// returns and goes to next screen
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			return;
		}
	}
	
}

// Helpers
//
// Respawn Fruits
void Game::respawnFruit(std::vector<std::unique_ptr<ObjectManager>>& fruitObjects)
{
	switch (rng(7)) // random fruit respawn based off rng and creates new unique fruit for each
	{
	case 1: fruitObjects.push_back(std::make_unique<Watermelon>());
		break;
	case 2: fruitObjects.push_back(std::make_unique<Kiwi>());
		break;
	case 3: fruitObjects.push_back(std::make_unique<Orange>());
		break;
	case 4: fruitObjects.push_back(std::make_unique<Coconut>());
		break;
	case 5: fruitObjects.push_back(std::make_unique<Apple>());
		break; 
	case 6: fruitObjects.push_back(std::make_unique<Dragonfruit>());
		break;
	case 7 : fruitObjects.push_back(std::make_unique<Bomb>());
		break;
	}
	
}
