//driver function definitions
//driver.cpp

#include "driver.h"

//namespace that is defined to be used.
using namespace std;

//void function that loops until the input file has been opened
//has one parameter that is an ifstream which is passed by reference
void fileCheck(ifstream& input){
  char fileName[40];
  do{
    cout << "Input file failed to open. Please input the name of the file: ";
    cin >> fileName;
    input.open(fileName);
  }while(input.fail());
}

//void function that reads in each line of the data file and creates a tile object
//with the data and pushes that object on the back of the tileList vector
void readFile(ifstream& input){
  char name;
  int top, right, bottom, left;
  //creating the tileList vector
  vector<Tile> tileList;
  //while there is a name that can be read
  while(input >> name){
    //read in the elements of the tile
    input >> top >> right >> bottom >> left;
    //construct a tile instantiation
    Tile currentTileRead(name, right, bottom, left, top);
    //push currentTileRead on the back of the tileList vector
    tileList.push_back(currentTileRead);
  }
  Tile tileMatrix[3][3];
  if(solvePattern(tileList, tileMatrix)) printMatrix(tileMatrix);
  else{
    cout << "No solution found.\n";
  }
}

//recursive function that returns true if the solution has been found and false
//if there is no solution.
bool solvePattern(vector<Tile> tileList, Tile tileMatrix[3][3], int tileNum){
  
  return false;
}

//sets the first element as the last element in the tileList vector and shifts the
//other elements forward one index
vector<Tile> rotateTile(vector<Tile> tileList){
  vector<Tile> temp;
  for(vector<Tile>::iterator it = tileList.begin(); it != tileList.end(); it++){
    if(it == tileList.begin()) it++;
    temp.push_back(*it);
  }
  temp.push_back(tileList[0]);
  return temp;
}

//void function that iterates through a 3 by 3 matrix of Tile objects and prints them all out
void printMatrix(Tile tileMatrix[3][3]){
  cout << "The solution is the following:\n";
  for (int i = 0; i < 3; i++){
    for(int j = 0; j<3; j++){
      cout << tileMatrix[i][j];
    }
  }
}
