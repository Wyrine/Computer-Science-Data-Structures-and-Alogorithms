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
  Tile tileMatrix[MATRIXSIZE][MATRIXSIZE];
  if(solvePattern(tileList, tileMatrix)) printMatrix(tileMatrix);
  else{
    cout << "No solution found.\n";
  }
}

//recursive function that returns true if the solution has been found and false
//if there is no solution.
bool solvePattern(vector<Tile> tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int tileNum, int row, int col){
  if(tileNum+1 == tileList.size()) return false;
  for(int i = tileNum; i < tileList.size(); i++){
      tileMatrix[row][col] = tileList[i]; // inserting the element into the matrix
      do{
        if(row==0){//first row
          do{
            //if the edges additively equate to zero
            if((tileMatrix[row][col].getRight() + tileList[i+1].getLeft()) == 0){
              if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
                if(solvePattern(tileList, tileMatrix, i+1, row, col+1)) return true;
              }
              else{//otherwise call the function at location row 1 column 0
                if(solvePattern(tileList, tileMatrix, i+1, row+1, 0)) return true;
              }
            }
          }while(tileList[i+1].rotate());
        }
        else if(row == 1){//second row
          do{
            //if the edges additively equate to zero
            if((tileMatrix[row][col].getRight() + tileList[i+1].getLeft()) == 0){
              if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
                if(solvePattern(tileList, tileMatrix, i+1, row, col+1)) return true;
              }
              else{//otherwise call the function at location row 1 column 0
                if(solvePattern(tileList, tileMatrix, i+1, row+1, 0)) return true;
              }
            }
          }while(tileList[i+1].rotate());
        }
        else{//third row
          do{
            //if the edges additively equate to zero
            if((tileMatrix[row][col].getRight() + tileList[i+1].getLeft()) == 0){
              if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
                if(solvePattern(tileList, tileMatrix, i+1, row, col+1)) return true;
              }
              else{//otherwise call the function at location row 1 column 0
                if(solvePattern(tileList, tileMatrix, i+1, row+1, 0)) return true;
              }
            }
          }while(tileList[i+1].rotate());
        }

      }while(tileMatrix[row][col].rotate());
  }
  //there is no matching solution
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

//void function that iterates through a MATRIXSIZE by MATRIXSIZE matrix of Tile objects and prints them all out
void printMatrix(Tile tileMatrix[MATRIXSIZE][MATRIXSIZE]){
  cout << "The solution is the following:\n";
  for (int i = 0; i < MATRIXSIZE; i++){
    for(int j = 0; j < MATRIXSIZE; j++){
      cout << tileMatrix[i][j];
    }
  }
}
