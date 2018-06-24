#include <iostream>
#include <string>
using namespace std;

// keep looping until player press "New game"
void mainMenu(player &world) {
	bool dc = true; // get out of mainMenu function
	bool menu = true; // show starting text, or not
	if (world.getPlayerDeaths() == 3) {
		world.setPlayerUnlocked_BPath(); // unlock "Find Best Path"
		cout << " ** You unlocked \"Find Best Path\" **" << endl << endl;
	}
	while (dc != false) {
		// starting text
		if (menu == true) {
			cout << ">> You are about to play \"Day 1\", a surviving (horror?) text-based game." << endl << endl;
		}
		cout << " 1. Instructions" << endl;
		cout << " 2. New Game" << endl;
		if (world.getPlayerUnlocked_BPath() == true) {
			cout << " 3. Find Best Path (Unlocked)" << endl;
		}
		else {
			cout << " 3. Find Best Path (Locked)" << endl;
		}

		// number of deaths
		cout << " Number of deaths: " << world.getPlayerDeaths() << endl << endl;

		int ans;
		cout << " Please enter a number: ";
		cin >> ans;
		cout << endl;

		system("cls"); // clear screen

		// check answer
		if (ans <= 0 || ans > 3) {
			cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
			menu = false;
			continue;
		}

		// instructions
		if (ans == 1) {
			cout << ">> \"Day 1\" is a surviving (horror?) text-based game set in a suburban location. Your " << endl;
			cout << "    objective is to survive the situation by discovering a path to safety by gathering " << endl;
			cout << "    objects and/or useful weapons across the different scenarios. You can hold one obj-" << endl;
			cout << "    ect at a time, so choose wisely!" << endl << endl;
			menu = false;
		}

		// new game
		else if (ans == 2) {
			dc = false;
			continue;
		}

		// find best path
		else {
			if (world.getPlayerUnlocked_BPath() == false) {
				cout << ">> Sorry. This option is locked at the moment." << endl << endl;
				menu = false;
			}
			else {
				cout << ">> Shortest way to survive: ";
				world.findShortestPath("Room");
				cout << endl << endl;
				menu = false;
			}
		}
	}
}

void Room(player &world) {
	bool Room = true; // get out of Room function
	bool text = true; // show Room text, or not
	while (Room != false) {
		if (text == true) {
			cout << ">> You wake up to a jarring sound. Even though you are still numb from sleeping, your head  " << endl;
			cout << "   is raising red flags. Where is that sound coming from? You rise from bed. To your right a" << endl;
			cout << "   thick curtain is covering the window, letting in a sliver of light. Is that a dull moan  " << endl;
			cout << "   coming from the living room, or is your mind playing tricks on you?" << endl;
			cout << "   What do you do?" << endl << endl;
		}
		else {
			cout << ">> You are in your: " << world.getPlayerLocation() << endl;
			cout << "   What do you do next?" << endl << endl;
		}

		// Room >> Window, Closet, Bathroom, Living Room
		cout << " 1. Take a look at the window" << endl;
		cout << " 2. Better take that bat out of the closet" << endl;
		cout << " 3. Search in the bathroom" << endl;
		cout << " 4. Investigate the living room" << endl << endl;

		int ans;
		cout << " Please enter a number: ";
		cin >> ans;
		cout << endl;

		system("cls"); // clear screen

		// check answer
		if (ans <= 0 || ans > 4) {
			cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
			text = false;
			continue;
		}

		// Room >> Window
		if (ans == 1) {
			world.setPlayerLocation("Window");
			cout << ">> You are at the: " << world.getPlayerLocation() << endl;
			cout << ">> The sky is gray, dream-like. The streets are deserted. Not a single soul can be seen from" << endl;
			cout << "   this angle. Not even Mrs. Dalloway's pooch which is usually very energetic. A weighty    " << endl;
			cout << "   sound pulls you back from your thoughts. That was definitely inside your house. You take " << endl;
			cout << "   whatever is near you: a pencil. You hold it in front of you as you were holding a knive. " << endl << endl;
			
			// set object to: pencil
			world.setPlayerObject("pencil");
			text = false;

			system("pause"); // enter any key to go back to Room
			system("cls"); // clear screen
			world.setPlayerLocation("Room");
		}

		// Room >> Closet
		if (ans == 2) {
			world.setPlayerLocation("Closet");
			cout << ">> You are at the: " << world.getPlayerLocation() << endl;
			cout << ">> You reach the closet and turn on the switch. It does not work. You smell an earthy or " << endl;
			cout << "   musty odor. You can't decide. Groping in the dark you find the bat. Suddenly, you feel" << endl;
			cout << "   safer than before. Just like if someone (or something) had been watching you from the " << endl;
			cout << "   shadows, you hear a plaintive cry coming from the living room. Your senses become more" << endl;
			cout << "   keen as you hold your bat with force." << endl << endl;

			// set object to: bat
			world.setPlayerObject("bat");
			text = false;

			system("pause"); // enter any key to go back to Room
			system("cls"); // clear screen
			world.setPlayerLocation("Room");
		}

		// Room >> Bathroom
		if (ans == 3) {
			world.setPlayerLocation("Bathroom");
			cout << ">> You are at the: " << world.getPlayerLocation() << endl;
			cout << ">> There's nothing unusual in your bathroom. Electricity is out but the water is still ru-" << endl;
			cout << "   nning. You found some towels and a soap. As the sounds coming from the living room are " << endl;
			cout << "   getting louder, your eyes, getting used to the dark, change your mirror reflection into" << endl;
			cout << "   one of a deformed creature. A harsh shiver goes down your spine." << endl << endl;

			text = false;

			system("pause"); // enter any key to go back to Room
			system("cls"); // clear screen
			world.setPlayerLocation("Room");
		}

		// Room >> Living Room
		if (ans == 4) {
			world.setPlayerLocation("Living Room");
			Room = false;
			system("cls"); // clear screen
			continue;
		}
	}
}

bool guestBedroom(player &world) {
	bool gr = true; // get out of guestBedroom function
	bool text = true; // show guestBedroom text, or not
	bool text2 = true; // show 2nd Bathroom text, or not
	while (gr != false) {
		if (text != false) {
			world.setPlayerLocation("Guest Bedroom");
			cout << ">> You are at the: " << world.getPlayerLocation() << endl;
			cout << ">> You close the door trying to make the least amount of sound as possible. You quickly scan" << endl;
			cout << "   the room for something that could be useful. Pillows, shoes, a lamp stand: nothing seems " << endl;
			cout << "   like a weapon upgrade. Your sixth sense (if you believe in that kind of stuff) is telling" << endl; 
			cout << "   you to hurry up. That \"thing\" has been quiet for a while." << endl;
			cout << "   What do you do?" << endl << endl;
		}
		else {
			cout << ">> You are at the: " << world.getPlayerLocation() << endl;
			cout << "   What do you do next?" << endl << endl;
		}

		// Guest Bedroom >> Under the Bed, 2nd Bathroom, Living Room
		cout << " 1. Check under to the bed" << endl;
		cout << " 2. Search in the 2nd Bathroom" << endl;
		cout << " 3. Go back to the living room" << endl << endl;

		int ans;
		cout << " Please enter a number: ";
		cin >> ans;
		cout << endl;

		system("cls"); // clear screen

		// check answer
		if (ans <= 0 || ans > 3) {
			cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
			text = false;
			continue;
		}

		// Guest Bedroom >> Under the Bed
		if (ans == 1) {
			world.setPlayerLocation("Under the Bed");
			cout << ">> You search: " << world.getPlayerLocation() << endl;
			cout << ">> You found a pair of yellow sandals and dust. Better look somewhere else." << endl << endl;

			text = false;

			system("pause"); // enter any key to go back to Room
			system("cls"); // clear screen
			world.setPlayerLocation("Guest Bedroom");
		}

		// Guest Bedroom >> 2nd Bathroom
		if (ans == 2) {
			if (text2 != false) {
				world.setPlayerLocation("2nd Bathroom");
				cout << ">> You are in the: " << world.getPlayerLocation() << endl;
				cout << ">> You rushed to open the drawer. You remember you hid a pair of scissors somewhere here. " << endl;
				cout << "   Alright! You found them at the bottom, next to some Penicillin tablets. You hear growls" << endl;
				cout << "   at certain distance and you start to panic. You realize the sounds are coming from the " << endl;
				cout << "   little window to your left." << endl;
				cout << "   What do you do?" << endl << endl;
				// set object to: scissors
				world.setPlayerObject("scissors");
			}
			else {
				cout << ">> You are at the: " << world.getPlayerLocation() << endl;
				cout << "   What do you do next?" << endl << endl;
			}

			// 2nd Bathroom >> Little Window, Go Back
			cout << " 1. Take a look at the little window" << endl;
			cout << " 2. Go back to the guest bedroom" << endl << endl;

			int anb;
			cout << " Please enter a number: ";
			cin >> anb;
			cout << endl;

			system("cls"); // clear screen

			// check answer
			if (anb <= 0 || anb > 2) {
				cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
				text = false;
				continue;
			}
			
			// 2nd Bathroom >> Little Window
			if (anb == 1) {
				world.setPlayerLocation("Little Window");
				cout << ">> You are in front the: " << world.getPlayerLocation() << endl;
				cout << ">> A broken window followed by a deformed hand is the last thing you see. You get suffocated" << endl;
				cout << "   by the force this arm hold against your neck." << endl << endl;
				
				world.setPlayerLocation("Death");
				cout << "   YOU DIED." << endl << endl;

				system("pause"); // enter any key to go back to Room
				system("cls"); // clears window
				world.increaseDeaths();
				return false;
			}

			// 2nd Bathroom >> Guest Bedroom
			if (anb == 2) {
				world.setPlayerLocation("Guest Bedroom");
				text = false;
			}
		}

		// Guest Bedroom >> Living Room
		if (ans == 3) {
			// get out of the function
			gr = false;
		}
	}
	return true;
}

bool livingRoom(player &world) {
	bool lr = true; // get out of livingRoom function
	bool text = true; // show livingRoom text, or not
	bool phase1 = true; // player status (alive or dead)
	while (lr != false) {
		if (text == true) {
			cout << ">> You moved to the: " << world.getPlayerLocation() << endl;
			if (world.getPlayerObject() != "") {
				cout << ">> As you enter the room, what looks like a person moves to the kitchen. You heart beats vio-" << endl;
				cout << "   lently inside your chest. You are extremely nervous. You almost drop what you are holding " << endl;
				cout << "   at the realization that you are apparently not alone. Can him/her notice it?" << endl;
				cout << "   What do you do?" << endl << endl;
			}
			else {
				cout << ">> As you enter the room, what looks like a person moves to the kitchen. You heart beats vio-" << endl;
				cout << "   lently inside your chest. You are extremely nervous. Does him/her notice it?" << endl;
				cout << "   What do you do?" << endl << endl;
			}
		}
		else {
			cout << ">> You are at the: " << world.getPlayerLocation() << endl;
			cout << "   What do you do next?" << endl << endl;
		}

		// Living Room >> TV, Guest Bedroom, Kitchen
		cout << " 1. Try to turn on the TV" << endl;
		cout << " 2. Go to the guest bedroom" << endl;
		cout << " 3. Investigate the kitchen" << endl << endl;

		int ans;
		cout << " Please enter a number: ";
		cin >> ans;
		cout << endl;

		system("cls"); // clear screen

		// check answer
		if (ans <= 0 || ans > 3) {
			cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
			text = false;
			continue;
		}

		// Living Room >> TV
		if (ans == 1) {
			world.setPlayerLocation("TV");
			cout << ">> You are in front of the: " << world.getPlayerLocation() << endl;
			cout << ">> It is useless. Without electricity the TV cannot be turn on. A wild noise is heard   " << endl;
			cout << "   from the kitchen." << endl << endl;

			text = false;

			system("pause"); // enter any key to go back to Room
			system("cls"); // clear screen
			world.setPlayerLocation("Living Room");
		}

		// Living Room >> Guest Bedroom
		if (ans == 2) {
			phase1 = guestBedroom(world); // call guestBedroom function
			// if player dies, get out of livingRoom function
			if (phase1 == false) {
				return false;
			}
			else {
				text = false;
				world.setPlayerLocation("Living Room");
			}
		}

		// Living Room >> Kitchen
		if (ans == 3) {
			world.setPlayerLocation("Kitchen");
			system("cls"); // clear screen
			lr = false;
		}
	}
	return phase1;
}

void kitchen(player &world) {
	bool kt = true; // get out of kitchen function
	bool text = true; // show Kitchen text, or not
	bool shadow = false; // is the mailman dead?
	while (kt != false) {
		if (text == true) {
			cout << ">> You moved to the: " << world.getPlayerLocation() << endl;
			cout << ">> The first thing you see is a shadow lying in front of the fridge. It is curved in an im- " << endl;
			cout << "   possible position as it was trying to bite desperately its back or nape. Its breathing is" << endl;
			cout << "   very weak; it sounds like a dying animal." << endl;
			cout << "   What do you do?" << endl << endl;
		}
		else {
			cout << ">> You are in your: " << world.getPlayerLocation() << endl;
			cout << "   What do you do next?" << endl << endl;
		}

		// Kitchen >> Shadow, Kitchen's Door to Outside
		cout << " 1. Get a closer look to that \"thing\"" << endl;
		cout << " 2. Open the kitchen door to get outside" << endl << endl;

		int ans;
		cout << " Please enter a number: ";
		cin >> ans;
		cout << endl;

		system("cls"); // clear screen

		// check answer
		if (ans <= 0 || ans > 2) {
			cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
			text = false;
			continue;
		}

		// Kitchen >> Shadow
		if (ans == 1) {
			world.setPlayerLocation("Shadow");
			if (shadow == false) {
				cout << ">> You are in front of the: " << world.getPlayerLocation() << endl;
				cout << ">> As you approach the shadow, human-like features start to appear. Now you know it is a" << endl;
				cout << "   HE. It's the mailman. His face is inflamated, contaminated by a repulsive pink susta-" << endl;
				cout << "   nce. \"They came from the corners\", he whispers. With a sudden contortion, he breaks" << endl;
				cout << "   his own neck." << endl << endl;

				shadow = true; // he dies
			}
			else {
				cout << ">> You are in front of the: Dead Mailman" << endl;
				cout << ">> There's nothing you can do for him at the moment. He is dead. \"Poor man\", you think." << endl << endl;
			}

			text = false;

			system("pause"); // enter any key to go back to Kitchen
			system("cls"); // clear screen
			world.setPlayerLocation("Kitchen");
		}

		// Kitchen >> Outside
		if (ans == 2) {
			world.setPlayerLocation("Kitchen's Door to Outside");
			system("cls"); // clear screen
			kt = false;
		}
	}
}

bool kitchenDoorOutside(player &world) {
	bool kt = true; // get out of kitchenDoorOutside function
	while (kt != false) {
		cout << ">> You are: Outside" << endl;
		cout << ">> The light hurts your eyeballs. As you try to get used to daylight again, one big creature " << endl;
		cout << "   meets you in front of the door. It is thin, hairless, of bulging, deformed womb. Its head " << endl;
		cout << "   is a bizarre imitation of a human face; it has a big, empty grin. From its teeth, huge dr-" << endl;
		cout << "   ops of a pink substance are falling to the ground." << endl << endl;

		system("pause"); // enter any key to continue
		system("cls"); // clear screen

		// if player is holding "" as an object
		if (world.getPlayerObject() == "") {
			cout << ">> You are: Outside" << endl;
			cout << ">> You have nothing to defend yourself. You try to escape but all is in vain. The creature is" << endl;
			cout << "   way more faster than you are. You feel how its teeth pierce your neck. After several minu-" << endl;
			cout << "   tes of uncomfortable chewing, you die from blood loss." << endl << endl;

			world.setPlayerLocation("Death");
			cout << "   YOU DIED." << endl << endl;

			kt = false; // get out of kitchenDoorOutside

			system("pause"); // enter any key to continue
			system("cls"); // clears window
			world.increaseDeaths();
		}

		// if player is holding a "pencil" as an object
		if (world.getPlayerObject() == "pencil") {
			cout << ">> You are: Outside" << endl;
			cout << ">> You try to stick the pencil you were holding in the creature's right eye but it breaks.   " << endl;
			cout << "   Desperate, you try to escape but all is in vain. The creature is way more faster than you " << endl;
			cout << "   are. You feel how its teeth pierce your neck. After several minutes of uncomfortable chew-" << endl;
			cout << "   ing, you die from blood loss." << endl << endl;

			world.setPlayerLocation("Death");
			cout << "   YOU DIED." << endl << endl;

			kt = false; // get out of kitchenDoorOutside

			system("pause"); // enter any key to continue
			system("cls"); // clears window
			world.increaseDeaths();
		}

		// if player is holding a "bat" as an object
		if (world.getPlayerObject() == "bat") {
			world.setPlayerLocation("_if_bat");
			return true;
		}

		// if player is holding the "scissors" as an object
		if (world.getPlayerObject() == "scissors") {
			world.setPlayerLocation("_if_scissors");
			return true;
		}
	}
	return false;
}

void street(player &world) {
	cout << ">> You are in the: " << world.getPlayerLocation() << endl;
	cout << ">> You run as far and as fast as your feet allow. You see at least five creatures looking at " << endl;
	cout << "   you from different parts of the neighborhood. You start to regret having left your house. " << endl;
	cout << "   The creatures start running towards you." << endl << endl;

	system("pause"); // enter any key to continue
	system("cls"); // clear screen

	cout << ">> You are in the: " << world.getPlayerLocation() << endl;
	cout << ">> You find a piece of metal in the ground. It looks strong enough to defend yourself, at lea-" << endl;
	cout << "   st for the moment. You keep running as fast as you find possible but you know the creatures" << endl;
	cout << "   are a few steps behind you." << endl << endl;

	// set object to: piece of metal
	world.setPlayerObject("piece of metal");

	system("pause"); // enter any key to continue
	system("cls"); // clear screen

	cout << ">> You are in the: " << world.getPlayerLocation() << endl;
	cout << ">> A machinegun is heard. The creatures flee away in multiple directions. \"That's luck\", you" << endl;
	cout << "   say to yourself. Here's the moment you find out you are bleeding from the chest. Somehow,  " << endl;
	cout << "   a lost bullet found its way to your left lung. After a few minutes of agonizing pain, you  " << endl; 
	cout << "   die of asphyxiation." << endl << endl;

	world.setPlayerLocation("Death");
	cout << "   YOU DIED." << endl << endl;

	system("pause"); // enter any key to continue
	system("cls"); // clears window
	world.increaseDeaths();
}

void if_bat(player &world) {
	bool ib = true; // get out of if_bat function
	bool text = true;
	while (ib != false) {
		if (text != false) {
			cout << ">> You are: Outside" << endl;
			cout << ">> You hit the creature's head with your bat a few times. It looks like the creature has fall- " << endl;
			cout << "   en. No, it is still moving. Its angry growl gives you goosebumps." << endl;
			cout << "   What do you do?" << endl << endl;
		}
		else {
			cout << ">> You are: Outside" << endl;
			cout << "   What do you do?" << endl << endl;
		}

		// _if_bat >> Street, Go back
		cout << " 1. Run down the street" << endl;
		cout << " 2. Go back to the house" << endl << endl;

		int ans;
		cout << " Please enter a number: ";
		cin >> ans;
		cout << endl;

		system("cls"); // clear screen

		// check answer
		if (ans <= 0 || ans > 2) {
			cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
			text = false;
			continue;
		}

		// _if_bat >> Street
		if (ans == 1) {
			world.setPlayerLocation("Street");
			street(world);
			ib = false; // get out of if_bat
		}

		// _if_bat >> Go back
		if (ans == 2) {
			cout << ">> You are: Outside" << endl;
			cout << ">> You try to enter the house but the door is closed from the inside. The creature is standing " << endl;
			cout << "   in its feet right behind you. Desperate, you try to hit it one more time but all is in vain." << endl;
			cout << "   The creature is way more faster than you are. You feel how its teeth pierce your neck. After" << endl;
			cout << "   several minutes of uncomfortable chewing, you die from blood loss." << endl << endl;

			world.setPlayerLocation("Death");
			cout << "   YOU DIED." << endl << endl;

			ib = false; // get out of if_bat

			system("pause"); // enter any key to continue
			system("cls"); // clears window
			world.increaseDeaths();
		}
	}
}

void if_scissors(player &world) {
	bool is = true; // get out of if_scissors function
	bool text = true;
	while (is != false) {
		if (text != false) {
			cout << ">> You are: Outside" << endl;
			cout << ">> You stick the scissors you were holding in the creature's right eye. It is quite effective." << endl;
			cout << "   After an agonizing growl, the creature falls dead." << endl;
			cout << "   What do you do now?" << endl << endl;
		}
		else {
			cout << ">> You are: Outside" << endl;
			cout << "   What do you do now?" << endl << endl;
		}

		// _if_scissors >> Street, Go back, Go to neighbor's house
		cout << " 1. Run down the street" << endl;
		cout << " 2. Check your surroundings" << endl << endl;

		int ans;
		cout << " Please enter a number: ";
		cin >> ans;
		cout << endl;

		system("cls"); // clear screen

		// check answer
		if (ans <= 0 || ans > 2) {
			cout << ">> Sorry. That's an invalid input. Try again." << endl << endl;
			text = false;
			continue;
		}

		// _if_scissors >> Street
		if (ans == 1) {
			world.setPlayerLocation("Street");
			street(world);
			is = false; // get out of if_scissors
		}

		// _if_scissors >> Go to neighbor's house
		if (ans == 2) {
			cout << ">> You are: Outside" << endl;
			cout << ">> You decide to search for a better weapon at your neighbor's house. You remember him bragging " << endl;
			cout << "   about his huge gun collection the last time you visited him." << endl << endl;
			world.setPlayerLocation("Neighbor's House");
			
			system("pause"); // enter any key to continue
			system("cls"); // clears window

			cout << ">> You are at the: " << world.getPlayerLocation() << endl;
			cout << ">> You cross his border. Even though you try hard to find a way in, his kitchen's door is   " << endl;
			cout << "   stuck by some heavy object from the inside. You try the windows. They are all closed from" << endl;
			cout << "   the inside as well. \"Damn it\", you say at loud. Suddenly, a deformed face looks back at" << endl;
			cout << "   you from the darkness: it is another creature." << endl << endl;

			system("pause"); // enter any key to continue
			system("cls"); // clears window

			cout << ">> You are the: " << world.getPlayerLocation() << endl;
			cout << ">> A machinegun is heard. The window gets contaminated from the inside by a pink subtance. " << endl;
			cout << "   The creature is dead. \"Who is this?\", your neighbor asks. After you tell him your na- " << endl;
			cout << "   me he opens his kitchen's door. \"What are you waiting for? Come on in!\", he tells you. " << endl << endl;
			world.setPlayerLocation("Neighbor's Living Room");

			system("pause"); // enter any key to continue
			system("cls"); // clears window

			cout << ">> You are the: " << world.getPlayerLocation() << endl;
			cout << ">> \"If it had not been for your reckless distraction, I would have been killed by that " << endl;
			cout << "   \"thing\". I suppose I own a thank you\". He tells you that he has sufficient weapons" << endl;
			cout << "   to protect his property and more than enough canned food for at least two months. He " << endl;
			cout << "   tells you that you are welcome to stay as long as you please." << endl << endl;
			
			world.setPlayerLocation("Survived");
			cout << "   YOU SURVIVED." << endl << endl;

			is = false; // get out of if_scissors

			system("pause"); // enter any key to continue
			system("cls"); // clears window
		}
	}
}

void newGame(player &world) {
	// set character at location "Room"
	world.setPlayerLocation("Room");

	// set weapon to "" (in case of second round)
	world.setPlayerObject("");

	// start in Room
	Room(world);

	// go to Living Room
	bool phase1 = livingRoom(world);

	// go to Kitchen if player didn't die
	if (phase1 == true) {
		kitchen(world);
		
		// go Outside
		bool phase2 = kitchenDoorOutside(world);

		if (phase2 == true) {
			// if player has the bat
			if (world.getPlayerLocation() == "_if_bat") {
				if_bat(world);
			}
			
			// if player has the scissors
			else {
				if_scissors(world);
			}
		}
	}
}
