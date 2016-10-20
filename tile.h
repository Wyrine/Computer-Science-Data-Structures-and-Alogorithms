#pragma once
//Tile class definition
//tile.h

//libraries used
#include <iostream>
#include <vector>

using namespace std;

//class definition
class Tile{
  //private member functions
  char tileName;
  int edges[4];
  int rotation;
  void swap();
public:
  Tile(){}
  Tile(char name, int right, int bottom, int left, int top);
  bool rotate();
  int getTop() { return edges[3]; }
  int getBot() { return edges[1]; }
  int getRight() { return edges[0]; }
  int getLeft() { return edges[2]; }
  char getName() { return tileName; }
  int getRotation() { return rotation;  }
  //friended extraction operator overloading function
  friend ostream& operator<<(ostream& os, Tile& rhs);
  //assignement operator overloading
  Tile operator=(Tile& rhs);
};
