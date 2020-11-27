// Name: Map.h
// Author: Cason White

//Map.h is the header for a class that stores tile info and map-based
//functions, including methods that create a debug arena map for
//testing purposes.

//The members are as follows:

// floor - a 2d vector which stores the information of every tile on the 
//       floor, as well as it's location,

//int x = x size of map
//int y = y size of map

//Tile* pcLoc - current Tile location of the player character



#ifndef MAP_H
#define MAP_H

#include "Creature.h"
#include "Tile.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

#include <tuple>
#include <vector>
#include <ncurses.h>

using namespace std;

class Tile;
class Creature;
//class Pc;
class Map {

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & floor;
        ar & pcLoc;
        ar & xmax;
        ar & ymax;
        ar & x;
        ar & y;
	
    }
    vector <vector <Tile*> > floor;
    Tile* pcLoc = NULL;
    int x = 0;
    int y = 0;
    int xmax;
    int ymax;
    WINDOW* mainscr;
    WINDOW* status;
    WINDOW* message;

    //  void Valloc(vector<Tile*> t);

public:

    tuple<int, int> getSize();
    
    Tile* getTileAt(int x, int y);

    void cRow(int row, int r1, int r2, TileType tile, bool value);
    void cColumn(int col, int r1, int r2, TileType tile, bool value);

    void refreshAll();
    void refreshMain();
    void refreshStatus();
    void refreshMsg();
    void input();
    void exitMap();
    void createArena();
    void pMovePlayer(char dir);

    void printMap();

    Tile* getPcLoc();
    void setPcLoc(Tile* loc);

    
    
    
    Map(int x, int y);
    Map() {}
    ~Map();


};
#endif
