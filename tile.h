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
public:
  Tile(char name, int top, int right, int bottom, int left);
  void rotate();
  void swap();
  void insert(int edge);
  //friended extraction operator overloading function
  friend ostream& operator<<(ostream& os, Tile& rhs);
};
