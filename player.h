#include <iostream>
#include <queue>
#include "directedGraph.h"
using namespace std;

class player : public directedGraph
{
private:
	vertex * playerVertex;
	string object;
	bool decision;
	bool unlocked_bpath;
	int deaths;

public:
	player() {
		playerVertex = NULL;
		object = "";
		decision = true;
		unlocked_bpath = false;
		deaths = 0;
	}

	vertex * getVertex(string x) {
		vertex * myVertex = findVertex(x);
		return myVertex;
	}

	string getPlayerLocation() {
		if (playerVertex == NULL) {
			return "Nowhere!!";
		}
		return playerVertex->data;
	}

	string getPlayerLocationExits() {
		string ans;
		for (size_t i = 0; i<playerVertex->neighbors.size(); i++)
		{
			ans = ans + playerVertex->neighbors[i]->data + ", ";
		}
		return ans;
	}

	bool getPlayerDecision() {
		return decision;
	}

	bool getPlayerUnlocked_BPath() {
		return unlocked_bpath;
	}

	string getPlayerObject() {
		return object;
	}

	int getPlayerDeaths() {
		return deaths;
	}

	void setPlayerLocation(string x) {
		playerVertex = findVertex(x);
		if (playerVertex == NULL) {
			cout << "Error: invalid input" << endl;
		}
	}

	void setPlayerDecision(bool myDec) {
		decision = myDec;
	}

	void setPlayerObject(string x) {
		object = x;
	}

	void setPlayerUnlocked_BPath() {
		unlocked_bpath = true;
	}

	void increaseDeaths() {
		deaths++;
	}

	bool travelTo(string x) {
		bool valid = false;
		for (size_t i = 0; i<playerVertex->neighbors.size(); i++)
		{
			if (playerVertex->neighbors[i]->data == x) {
				valid = true;
				setPlayerLocation(x);
			}
		}
		return valid;
	}
};
