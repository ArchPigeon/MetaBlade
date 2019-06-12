//Name: Pc.h
//Author: Cason White
//Pc.h is an inherited sub-class of the Creature class that contains information and methods
// relating to only the Player Character
// it contains the following members


// tuple <int, int> movePc(int d) - moves the pc a keypad direction and returns the pc's new location within
// the map

#ifndef PC_H
#define PC_H

#include "Creature.h"
#include <tuple>

using namespace std;

class Pc : public Creature {
    
public:

    tuple <int, int> movePc(int d);
    
};


#endif
