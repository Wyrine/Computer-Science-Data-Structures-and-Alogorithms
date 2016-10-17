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

  if(solvePattern(tileList, tileMatrix, tileList.size()-1)) printMatrix(tileMatrix);
  else{
    cout << "No solution found.\n";
  }
}
/*
//recursive function that returns true if the solution has been found and false
//if there is no solution.
bool solvePattern(vector<Tile> tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int tileNum, int row, int col){
  tileMatrix[row][col] = tileList[tileNum]; // inserting the element into the matrix
  for(int i = tileNum; i < tileList.size(); i++){
      do{
        if(row == 0){//first row
          if(firstRow(tileList, tileMatrix, i, row, col)) return true;
        }
        else if(row == 1 || row == 2){//second or third rows
          if(secondOrThirdRow(tileList, tileMatrix, i, row, col)) return true;
        }
      }while(tileMatrix[row][col].rotate());//rotate 'A'
  }
  //there is no matching solution
  return false;
}

bool firstRow(vector<Tile> tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int i, int row, int col){
  //if(i+1 == tileList.size()) return false;
  cout << "firstRow\n";
  cout << "Row: "<<row << " Col: "<<col << " i: "<<i << endl;
  cout << "Matrix: " << tileMatrix[row][col] << endl;
  cout << "list size " << (int)tileList.size() << endl;
  cout << "List: " << tileList[i+1] << endl;
  do{
    //if the edges additively equate to zero
    if((tileMatrix[row][col].getRight() + tileList[i+1].getLeft()) == 0){
      if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
        if(solvePattern(tileList, tileMatrix, i+1, row, col+1)) return true;
      }
      else{//otherwise call the function at location row+1 column 0
        if(solvePattern(tileList, tileMatrix, i+1, row+1, 0)) return true;
      }
    }
  }while(tileList[i+1].rotate()); //rotate 'B'
  return false;
}

bool secondOrThirdRow(vector<Tile> tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int i, int row, int col){
  //if(i+1 == tileList.size()) return false;
  cout << "secondOrThirdRow\n";
  cout << "Row: "<<row << " Col: "<<col << " i: "<<i << endl;
  cout << "Matrix: " << tileMatrix[row][col];
  cout << "list size " << (int)tileList.size() << endl;
  cout << "List: " << tileList[i+1] << endl;
  do{
    //if the edges additively equate to zero
    if(((tileMatrix[row][col].getRight() + tileList[i+1].getLeft()) == 0) &&
      ((tileMatrix[row-1][col+1].getBot() + tileList[i+1].getTop()) == 0)){
      if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
        if(solvePattern(tileList, tileMatrix, i+1, row, col+1)) return true;
      }
      else{//otherwise call the function at location row+1 column 0
        if(solvePattern(tileList, tileMatrix, i+1, row+1, 0)) return true;
      }
    }
  }while(tileList[i+1].rotate());
  return false;
}
*/
//sets the first element as the last element in the tileList vector and shifts the
//other elements forward one index
void rotateTile(vector<Tile> &tileList, int current){
  Tile temp = tileList[current];
  for(int i = current; i > 0; i--){
    tileList[i] = tileList[i-1];
  }
  tileList[0] = temp;
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

//possible solution
bool solvePattern(vector<Tile> &tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int tileNum, int row, int col){
  for(int i = tileNum; i > 0 ; i--){
    cout << "Inserting: " << tileList[i] << endl;
    tileMatrix[row][col] = tileList[i]; // inserting the element into the matrix
    tileList.pop_back();
    /*if(i==0){
      cout << "Nothing found." << endl;
      tileList.push_back(tileMatrix[row][col]);
      return false;
    }*/
    if(!tileMatrix[row][col].getState()){
      cout << "Doing the first element: " << tileMatrix[row][col] << endl;
      do{
        if(row == 0){//first row
          if(firstRow(tileList, tileMatrix, i, row, col, true)) return true;
        }
        else if(row == 1 || row == 2){//second or third rows
          if(secondOrThirdRow(tileList, tileMatrix, i, row, col)) return true;
        }
      }while(tileMatrix[row][col].rotate());//rotate 'A'
    }
    else{
      if(row == 0){//first row
        if(firstRow(tileList, tileMatrix, i, row, col, false)) return true;
      }
      else if(row == 1 || row == 2){//second or third rows
        if(secondOrThirdRow(tileList, tileMatrix, i, row, col)) return true;
      }
    }
    tileList.push_back(tileMatrix[row][col]);
    rotateTile(tileList, i);
  }
  //there is no matching solution
  return false;
}

bool firstRow(vector<Tile> &tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int i, int row, int col, bool firstElement){
  do{
    //if the edges additively equate to zero
    if((tileMatrix[row][col].getRight() + tileList[i-1].getLeft()) == 0){
      if (firstElement) tileMatrix[row][col].changeState(true);
      tileList[i-1].changeState(true);
      if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
        if(solvePattern(tileList, tileMatrix, i-1, row, col+1)) return true;
        else {
          if(firstElement) tileMatrix[row][col].changeState(false);
          tileList[i-1].changeState(false);
        }
      }
      else{//otherwise call the function at location row+1 column 0
        if(solvePattern(tileList, tileMatrix, i-1, row+1, 0)) return true;
        else {
          if(firstElement) tileMatrix[row][col].changeState(false);
          tileList[i-1].changeState(false);
        }
      }
    }
  }while(tileList[i-1].rotate()); //rotate 'B'
  return false;
}

bool secondOrThirdRow(vector<Tile> &tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int i, int row, int col){
  do{
    //if the edges additively equate to zero
    if(((tileMatrix[row][col].getRight() + tileList[i-1].getLeft()) == 0) &&
      ((tileMatrix[row-1][col+1].getBot() + tileList[i-1].getTop()) == 0)){
      tileList[i-1].changeState(true);
      if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
        if(solvePattern(tileList, tileMatrix, i-1, row, col+1)) return true;
        else {
          tileList[i-1].changeState(false);
        }
      }
      else{//otherwise call the function at location row+1 column 0
        if(solvePattern(tileList, tileMatrix, i-1, row+1, 0)) return true;
        else {
          tileList[i-1].changeState(false);
        }
      }
    }
  }while(tileList[i-1].rotate());
  return false;
}
