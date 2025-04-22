// Test cases cpp file
#include "TestCases.hpp"
#include <fstream>

void testGravity()
{
	sf::RenderWindow window(sf::VideoMode({ 1080, 1080 }), "Test Case");

	ObjectManager testObj;


	while (window.isOpen()) // default window game loop
	{
		while (const std::optional event = window.pollEvent()) // if window is closed
		{
			if (event->is<sf::Event::Closed>()) window.close();
		}

		testObj.gravity();
		window.clear();
		testObj.draw(window);
		window.display();
	}
}

void testFontLoad()
{
	sf::Font testFont;

	if (!testFont.openFromFile("Project\\Sources\\Japers-DK3W.ttf"))
	{
		std::cout << "Font Failed to Load";
	}
	else
	{
		std::cout << "Font Succesfully Loaded";
	}
}

void testSlice()
{
	sf::RenderWindow window(sf::VideoMode({ 1080,1080 }), "Test");
	ObjectManager testObject;
	testObject.getShape().setPosition(sf::Vector2f({ 400, 400 }));

	while (window.isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // whilst holding the left mouse button down
		{
			// Gets mouse position and converts it to the world position from window position
			sf::Vector2i mouseWindowPosition = sf::Mouse::getPosition(window);
			sf::Vector2f mouseWorldPosition = window.mapPixelToCoords(sf::Vector2i(mouseWindowPosition.x, mouseWindowPosition.y));


			// if the shapes bounds has the mouse and fruit hasnt been sliced
			if (testObject.getShape().getGlobalBounds().contains(mouseWorldPosition))
			{
				std::cout << "Sliced";
			}
		}

		window.clear();
		testObject.draw(window);
		window.display();

	}
}

void testDraw()
{
	sf::RenderWindow window(sf::VideoMode({ 1080, 1080 }), "Test Case");
	ObjectManager testObj;
	testObj.getShape().setPosition(sf::Vector2f({ 400, 400 }));

	while (window.isOpen()) // default window game loop
	{
		while (const std::optional event = window.pollEvent()) // if window is closed
		{
			if (event->is<sf::Event::Closed>()) window.close();
		}

		window.clear();
		testObj.draw(window);
		window.display();
	}
}

void testSpriteChange()
{
	sf::RenderWindow window(sf::VideoMode({ 1080, 1080 }), "Test Case");
	ObjectManager testObject;
	testObject.getShape().setPosition(sf::Vector2f({ 400, 400 }));

	while (window.isOpen()) // default window game loop
	{
		while (const std::optional event = window.pollEvent()) // if window is closed
		{
			if (event->is<sf::Event::Closed>()) window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			testObject.changeSprite(testObject.getSlicedTexture());
		}

		window.clear();
		testObject.draw(window);
	}


}