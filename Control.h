#include "Map.h"
#include <map>
#include <boost/serialization/vector.hpp>
#include <queue>
#include "Action.h"

class Control{
public: 
	enum DIRECTION {UP,DOWN,LEFT,RIGHT};
	static map<string, Control> PC_Controls;
	// Using a map so that actions can be referred to by name
	static void listPC_Controls();
	static void listPC_Controls(string Action);
	static vector<Creature> controlledCreatures; // Container for the purpose of enabling jank movement interactions such as mimiced movement ex.
	static bool canMove(DIRECTION dir);

	priority_queue<Action> actionList; // By breaking actions down and giving them priority their individual effects can be reused
	};