//tile class method definitions
//tile.cpp

#include "tile.h"

using namespace std;

//the 5 argument constructor
Tile::Tile(char name, int right, int bottom, int left, int top){
  tileName = name;
  rotation = 0;
  edges[0] = right;
  edges[1] = bottom;
  edges[2] = left;
  edges[3] = top;
}

//rotate the tile
bool Tile::rotate(){
  //boolean to check if the tile has been fully rotated
  bool returnVar = true;
  //if the tiles rotation number is the same as the size of edges
  if(rotation == 4){
    //rotation goes back to zero
    rotation = 0;
    //returnVar will be false so that the recursive function may move on
    returnVar = false;
  }
  //otherwise increment rotation by one
  else rotation++;
  //call swap to rotate the elements
  swap();
  //return the boolean
  return returnVar;
}

//swap bubbles the first element to the end of the vector list
void Tile::swap(){
	int i1 = 0, temp;
	for (int i2 = 1; i2 < 4; i2++) {
		temp = edges[i1];
		edges[i1] = edges[i2];
		edges[i2] = temp;
	}
}

//overloading the assignment operator
Tile Tile::operator=(Tile & rhs)
{
	tileName = rhs.tileName;
	for (int i = 0; i < 4; i++) {
		edges[i] = rhs.edges[i];
	}
	//edges = rhs.edges;
	rotation = rhs.rotation;
	return *this;
}

//overloaded extraction operator to print easier
ostream& operator<<(ostream& os, Tile& rhs){
  os << rhs.tileName << rhs.rotation;
  for (int i = 0; i < 4; i++) {
	  os << " " << rhs.edges[i];
  }
  return os;
}
