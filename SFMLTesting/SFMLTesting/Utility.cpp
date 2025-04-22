// Utility cpp
// function initializers for each utility function


#include "Utility.hpp"

#include <ctime>
#include <cstdlib>
#include <random>

// random number generated with an optional range value
int rng(const int range) 
{
	// cool mersene twister engine rng found through google

	std::random_device num; // obtain a random number
	std::mt19937 gen(num()); // mersene twister engine seed generated with num

	std::uniform_int_distribution<> distrib(1, range); // generate numbers in this range 

	return distrib(gen); // returns number generated
}

float spawnInterval(const int minutes, const int seconds) // spawn fruit interval based off time
{
	float interval = 4.5 - minutes * 0.5; // initially 4.5 seconds, decreases by 0.5 every minute 

	if (interval <= 1) interval = 1; // if it ever goes below, set it back to 1

	if (minutes >= 7 && minutes % 2 == 1) // every other minute starting at 7 minutes, enters a "frenzy" mode
	{
		// fruits will spawn faster every seconds till 0.4
		interval -= seconds * 0.01;
	}

	return interval; // returns interval of spawntime 
}

