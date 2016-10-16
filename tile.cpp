//tile class method definitions
//tile.cpp

#include "tile.h"

using namespace std;

//the 5 argument constructor
Tile::Tile(char name, int right, int bottom, int left, int top){
  tileName = name;
  rotation = 0;
  edges.push_back(right);
  edges.push_back(bottom);
  edges.push_back(left);
  edges.push_back(top);
}

//rotate the tile
bool Tile::rotate(){
  //boolean to check if the tile has been fully rotated
  bool returnVar = true;
  //if the tiles rotation number is the same as the size of edges
  if(rotation == edges.size()){
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
  vector<int>::iterator it1 = edges.begin();
  int temp;
  for(vector<int>:: iterator it2 = edges.begin(); it2 != edges.end(); it2++){
      //making it so that it2 starts at the second location
      if(it2 == edges.begin()) it2++;
      //swapping the values of it1 and it2
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
