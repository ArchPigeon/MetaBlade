#include "Tile.h"

using namespace std;

Tile::Tile(Map& p) : parent(p) {}

void Tile::setPassable(bool t) {
    this->passable = t;
}

bool Tile::getPassable() const {
    return Tile::passable;
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
    
    return Tile::inhab;
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
