#include <iostream>
#include "story.h"
using namespace std;

#include <windows.h>
#include <MMSystem.h>

// This is going to be the world of "Day 1"
void buildWorld(player &world)
{
	// locations in the game
	world.addVertex("Room");
	world.addVertex("Window");
	world.addVertex("Closet");
	world.addVertex("Bathroom");
	world.addVertex("Living Room");
	world.addVertex("TV");
	world.addVertex("Kitchen");
	world.addVertex("Guest Bedroom");
	world.addVertex("2nd Bathroom");
	world.addVertex("Little Window");
	world.addVertex("Under the Bed");
	world.addVertex("Shadow");
	world.addVertex("Kitchen's Door to Outside");
	world.addVertex("_if_scissors");
	world.addVertex("_if_bat");
	world.addVertex("_if_pencil");
	world.addVertex("_if_nothing");
	world.addVertex("Street");
	world.addVertex("_shiny_object");
	world.addVertex("Go Back to the House");
	world.addVertex("Death");
	world.addVertex("Neighbor's House");
	world.addVertex("Neighbor's Living Room");
	world.addVertex("Survived");

	// all different paths
	world.addEdge("Room", "Window");
	world.addEdge("Room", "Closet");
	world.addEdge("Room", "Bathroom");
	world.addDirectedEdge("Room", "Living Room");
	world.addEdge("Living Room", "TV");
	world.addEdge("Living Room", "Guest Bedroom");
	world.addEdge("Guest Bedroom", "2nd Bathroom");
	world.addEdge("2nd Bathroom", "Little Window");
	world.addDirectedEdge("Little Window", "Death");
	world.addEdge("Guest Bedroom", "Under the Bed");
	world.addDirectedEdge("Living Room", "Kitchen");
	world.addEdge("Kitchen", "Shadow");
	world.addDirectedEdge("Kitchen", "Kitchen's Door to Outside");
	world.addDirectedEdge("Kitchen's Door to Outside", "_if_scissors");
	world.addDirectedEdge("Kitchen's Door to Outside", "_if_bat");
	world.addDirectedEdge("Kitchen's Door to Outside", "_if_pencil");
	world.addDirectedEdge("Kitchen's Door to Outside", "_if_nothing");
	world.addDirectedEdge("_if_scissors", "Neighbor's House");
	world.addDirectedEdge("Neighbor's House", "Neighbor's Living Room");
	world.addDirectedEdge("Neighbor's Living Room", "Survived");
	world.addDirectedEdge("_if_scissors", "Street");
	world.addDirectedEdge("_if_bat", "Street");
	world.addDirectedEdge("_if_bat", "Go Back to the House");
	world.addDirectedEdge("Go Back to the House", "Death");
	world.addDirectedEdge("Street", "_shiny_object");
	world.addDirectedEdge("_shiny_object", "Death");
	world.addDirectedEdge("_if_pencil", "Death");
	world.addDirectedEdge("_if_nothing", "Death");
}

void gameStarts(player &world) {
	while (world.getPlayerDecision() != false) {
		// play soundtrack
		PlaySound(TEXT("soundtrack.wav"), NULL, SND_FILENAME | SND_ASYNC);
		// loop "Main Menu" until user enters "New Game"
		mainMenu(world);
		// starts "New Game"
		newGame(world);
	}
}