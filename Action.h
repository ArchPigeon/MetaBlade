#include "Creature.h"
#include <map>
class Action{
	public:
		static map<string, Action*> allActions;
		static int actionID_Counter;
		int actionID;
		// Actions will be pointers to functions which shall return an error code.
		// The various signatures represent the manners in which actions can be performed.
		//		Ex. - execute( (f)(Creature) ) will execute some function which takes a singular creature as an argument (ex. move a creature).
		//		Ex. - execute( (f)(Creature, vector<string>) ) will execute some function which takes a singular creature as an argument with some vector of string options
		int execute(int (*f)(Creature*));
		int execute(int (*f)(Creature*, vector<string>));
		int execute(int (*f)(Creature*, Creature*));
		int execute(int (*f)(Creature*, Creature*, vector<string>));
		int execute(int (*f)(Creature*, vector<string>));
		int execute(int (*f)(Creature*, vector<Creature*>, vector<string>));
};