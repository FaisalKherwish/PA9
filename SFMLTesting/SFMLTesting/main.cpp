#include "ObjectManager.hpp"
#include "Objects.hpp"
#include "Game.hpp"

int main(void)
{
	Game game; // game object
	bool gameActive = true; // whether game can be continued or is continued

	do
	{
		// main menu window state
		gameActive = game.mainMenu();

		// if user wants game to continue / start
		if (gameActive)
		{
			// main game wrapper / runner
			game.runGame();
			// game over window state
			game.gameOver();
		}

	} while (gameActive); // loops while esc key is not pressed on main menu
}