#pragma once
//Tile class definition
//tile.h

//libraries used
#include <iostream>
#include <vector>

using namespace std;

class Tile{
  char tileName;
  vector<int> edges;
  int rotation;
public:
  Tile(char name, int first, int second, int third, int fourth);
  void rotate();
  void swap();
  void insert(int edge);

  friend ostream& operator<<(ostream& os, Tile& rhs);
};
