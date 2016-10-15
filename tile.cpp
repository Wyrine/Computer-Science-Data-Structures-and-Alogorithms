//tile class method definitions
//tile.cpp

#include "tile.h"

using namespace std;

Tile::Tile(char name, int first, int second, int third, int fourth){
  tileName = name;
  rotation = 0;
  edges.push_back(first);
  edges.push_back(second);
  edges.push_back(third);
  edges.push_back(fourth);
}
void Tile::rotate(){

}
void Tile::swap(){

}
void Tile::insert(int edge){
  edges.push_back(edge);
}

ostream& operator<<(ostream& os, Tile& rhs){
  os << rhs.tileName << rhs.rotation;
  for(vector<int>::iterator it = rhs.edges.begin(); it != rhs.edges.end(); it++){
    os << " " << *it;
  }
  os << endl;
  return os;
}
