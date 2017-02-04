/*
Created February 3rd 2017 by Mr. 1337
This is my first real project that I have put a lot of thought and work into, and hopefully I can make something special
This is also a spiritual successor to "platformgame.swf", an earlier project. Some of you may probably remember that abomination, but it was my first legitimate introduction into the field.
I know that this probably won't be the magnum opus that I'd really like it to be, but one can dream right?
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

//Loads and unloads SDL + accompanying libraries
bool initialize();
void shutdown();

int main()
{
	std::cout << "Welcome to the console for Just a Thought!" << std::endl << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::vector<std::string> quotes(10);
	std::srand(time(nullptr));
	quotes = {
		"We are shaped by our thoughts; we become what we think. When the mind is pure, joy follows like a shadow that never leaves.",
		"It is the mark of an educated mind to be able to entertain a thought without accepting it.",
		"For every minute you remain angry, you give up sixty seconds of peace of mind.",
		"The face is the mirror of the mind, and eyes without speaking confess the secrets of the heart.",
		"You cannot have a positive life and a negative mind.",
		"The mind is everything. What you think you become.",
		"As a single footstep will not make a path on the earth, so a single thought will not make a pathway in the mind. To make a deep physical path, we walk again and again. To make a deep mental path, we must think over and over the kind of thoughts we wish to dominate our lives.",
		"It is a man's own mind, not his enemy or foe, that lures him to evil ways.",
		"JUST DO IT! DON'T LET YOUR DREAMS BE DREAMS.",
		"There are no constraints on the human mind, no walls around the human spirit, no barriers to our progress except those we ourselves erect."
	};
	//Loads and displays a random quote
	std::cout << quotes[std::rand() % 10] << std::endl;

	if (initialize())
	{

	}
	else
	{
		std::cout << "The program failed to initialize, therminating";
		shutdown();
		return -1;
	}

	shutdown();

	std::cin.get();
	return 0;
}

bool initialize()
{
	bool success = true;
	return success;
}

void shutdown()
{

}