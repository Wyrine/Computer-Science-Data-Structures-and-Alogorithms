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
  //declaring an array of 9 Tile objects which will be our solution if there is one
  Tile matrix[9];
  //call the boolean recursive function to check if solveable
  //if it is, call the printMatrix
  if(solvePattern(tileList, matrix)) printMatrix(matrix);
  else //otherwise, there is no solution
    cout << "No solution found.\n";
}


//boolean function that returns true if the matrix has been filled in the proper order
//otherwise false.
//The function checks to see if startNum is 9, if it is then return true and that is the base case
//otherwise iterates through the tileList vector from startNum to 9
//and calls checkInsertion, if it returns true then just return true because that would mean
//the solution has been found.
//if the loop ends return false because this path has no solution
bool solvePattern(vector<Tile> tileList, Tile matrix[9],  int startNum, int k){
  if(startNum == 9) return true;
  for(int i = startNum; i< tileList.size(); i++){
	if (checkInsertion(tileList, matrix, i, k, startNum)) return true;
  }
  return false;
}

//boolean function that returns true if solvePattern returns true, otherwise false.
//false means the solution was found otherwise true means the solution was found
bool swapAndInsert(vector<Tile> tileList, Tile matrix[9], int i, int k, int startNum){
  //assigns the element at index i of tileList to element k of matrix
  matrix[k] = tileList[i];
  //calls swapTiles if i < size of tileList - 1 which swaps the element to be inserted with the
  //element of the startNum location
  if (i < tileList.size() - 1) tileList = swapTiles(tileList, startNum, i);
  //calls solvePattern with the next startNum+1 and k+1 to do the next location
  //if it returns true then the solution is found
  if (solvePattern(tileList, matrix, startNum+1, k + 1)) return true;
  //otherwise returns false
  return false;
}

//returns true if a solution if found otherwise false
//the function finds the location in the matrix array with the location k and with that
//does the appropriate checks and calls swapAndInsert if the appropriate edges cancel out
//and returns true if swapAndInsert returns true
//otherwise rotates until the tile is reset to it's original orientation then returns false
bool checkInsertion(vector<Tile> tileList, Tile matrix[9], int i, int k, int startNum){
	do {
		switch (k) {
			case 0: //row 0 column 0
				  if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				break;
			case 1: //row 0 column 1
        //case 1 and two do the same case checks
			case 2: //row 0 column 2
        //check right edge of the last element inserted with the left edge of the current location
				if ((matrix[k - 1].getRight() + tileList[i].getLeft()) == 0) {
		      if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				}
				break;
			case 3: //row 1 column 0
        //check bottom edge of the first element inserted with the top edge of the current location
				if (matrix[0].getBot() + tileList[i].getTop() == 0) {
					if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				}
				break;
			case 4: //row 1 column 1
        //check right edge of the last element inserted with the left edge of the current location
        //and the bottom edge of element 1 in the matrix and and the top edge of the current location
				if ((matrix[k - 1].getRight() + tileList[i].getLeft() == 0) && (matrix[1].getBot() + tileList[i].getTop() == 0)) {
					if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				}
				break;
			case 5: //row 1 column 2
        //check right edge of the last element inserted with the left edge of the current location
        //and the bottom edge of element 2 in the matrix and and the top edge of the current location
				if ((matrix[k - 1].getRight() + tileList[i].getLeft() == 0) && (matrix[2].getBot() + tileList[i].getTop() == 0)) {
					 if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				}
				break;
			case 6: //row 3 column 0
        //check bottom edge of the first element inserted with the top edge of the current location
				if (matrix[3].getBot() + tileList[i].getTop() == 0) {
					if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				}
				break;
			case 7: //row 3 column 1
        //check right edge of the last element inserted with the left edge of the current location
        //and the bottom edge of element 4 in the matrix and and the top edge of the current location
				if ((matrix[k - 1].getRight() + tileList[i].getLeft() == 0) && (matrix[4].getBot() + tileList[i].getTop() == 0)) {
					if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				}
				break;
			case 8: //row 3 column 2
        //check right edge of the last element inserted with the left edge of the current location
        //and the bottom edge of element 5 in the matrix and and the top edge of the current location
				if ((matrix[k - 1].getRight() + tileList[i].getLeft() == 0) && (matrix[5].getBot() + tileList[i].getTop() == 0)) {
					if (swapAndInsert(tileList, matrix, i, k, startNum)) return true;
				}
				break;
			}
	} while (tileList[i].rotate()); //rotating
  //return false if the solution was not found within these four rotations
	return false;
}

//returns a vector<Tile> and it swaps two elements in the tileList vector
//and then returns the new tileList
vector<Tile> swapTiles(vector<Tile> tileList, int start, int current){
	Tile temp = tileList[start];
	tileList[start] = tileList[current];
	tileList[current] = temp;
	return tileList;
}

//void function that iterates through an array of Tile objects and prints out the name and the rotation
//in a 3 by 3 layout
void printMatrix(Tile tileMatrix[9]){
  cout << "The solution is the following:\n";
  for (int i = 0; i < 9; i++){
    if(i == 3 || i == 6)
      cout << endl;
      cout << tileMatrix[i].getName() << tileMatrix[i].getRotation() << " ";
  }
  cout << endl;
}
