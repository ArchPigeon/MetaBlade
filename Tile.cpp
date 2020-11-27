#include "Tile.h"

using namespace std;

Tile::Tile(Map* p, int x, int y) :
    parent(p), xloc(x), yloc(y) {}

void Tile::setPassable(bool t) {
    this->passable = t;
}

bool Tile::getPassable() const {
    return Tile::passable;
}

char Tile::getSymbol() const{
  switch(tile){
    case floor:
      return '.';
      break;
    case wall:
      return '#';
      break;
    default:
      return '?';
      break;
  }
}

void Tile::setTileType(TileType t) {
    this->tile = t;
}

TileType Tile::getTileType() {
    return this->tile;
}

void Tile::setCreature(Creature* inh) {
    this->inhab = inh;
}

Creature* Tile::getCreature() const {
    
    return inhab;
}

void Tile::setTileMaterial(TileKind t) {
    this->material = t;
}

TileKind Tile::getTileMaterial() const {
    return this->material;

}

tuple <int, int> Tile::getLocation() const {
    return make_tuple(this->xloc, this->yloc);
}

Map* Tile::getParent(){
  return this->parent;
}

void Tile::setLocation(int x, int y){
  this->xloc = x;
  this->yloc = y;
}
