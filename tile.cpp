//tile class method definitions
//tile.cpp

#include "tile.h"

using namespace std;

//the 5 argument constructor
Tile::Tile(char name, int top, int right, int bottom, int left){
  tileName = name;
  rotation = 0;
  edges.push_back(top);
  edges.push_back(right);
  edges.push_back(bottom);
  edges.push_back(left);
}

//rotate the tile
void Tile::rotate(){
  //updating the rotation number
  (rotation == 4) ? rotation = 0 : rotation++;
  //call swap to rotate the elements
  swap();
}

//swap bubbles the first element to the end of the vector list
void Tile::swap(){
  vector<int>::iterator it1 = edges.begin();
  int temp;
  for(vector<int>:: iterator it2 = edges.begin(); it2 != edges.end(); it2++){
      if(it2 == edges.begin()) it2++;
      temp = *it1;
      *it1 = *it2;
      *it2 = temp;
      it1++;
  }
}

//insert takes an integer and pushes it on the back of the edges vector
void Tile::insert(int edge){
  edges.push_back(edge);
}

//overloaded extraction operator to print easier
ostream& operator<<(ostream& os, Tile& rhs){
  os << rhs.tileName << rhs.rotation;
  for(vector<int>::iterator it = rhs.edges.begin(); it != rhs.edges.end(); it++){
    os << " " << *it;
  }
  os << endl;
  return os;
}
