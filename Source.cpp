// Name: Javier A. Pina
// Class: CSCI 2380
// Homework 7

#include <iostream>
#include "player.h"
#include "world.h"
using namespace std;

int main() {
	// create a character
	player world;

	// build the world
	buildWorld(world);

	/*
	//double check that the world is built as desired
	world.testDisplay();
	cout << endl;
	*/

	// start the game
	gameStarts(world);

	system("pause");
	return 0;
}