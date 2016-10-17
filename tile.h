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
  vector<int> edges;
  int rotation;
  bool fixedState;
  void swap();
public:
  Tile(){}
  Tile(char name, int right, int bottom, int left, int top);
  bool rotate();
  void changeState(bool newState) { fixedState = newState;  }
  bool getState() { return fixedState; }
  void insert(int edge);
  int getTop() { return edges[3]; }
  int getBot() { return edges[1]; }
  int getRight() { return edges[0]; }
  int getLeft() { return edges[2]; }
  char getName() { return tileName; }
  //friended extraction operator overloading function
  friend ostream& operator<<(ostream& os, Tile& rhs);
};
