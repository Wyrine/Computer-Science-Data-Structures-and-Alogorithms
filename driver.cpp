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
  Tile tileMatrix[9];
  vector<char> listOfInsertedTiles;

  if(solvePattern(tileList, tileMatrix, listOfInsertedTiles)) printMatrix(tileMatrix);
  else{
    cout << "No solution found.\n";
  }
}

bool charInList(vector<char> tileInList, char tileName){
  for (int i = 0; i < tileInList.size(); i++){
    if(tileInList[i] == tileName) return true;
  }
  return false;
}

bool solvePattern(vector<Tile> tileList, Tile matrix[9], vector<char> listOfInsertedTiles, int i, int k){
  if(i == 9 || k == 9) return true;
  for(i=0 ; i< 9; i++){
    cout << " i = " << i << " k = " << k << endl;
    if(charInList(listOfInsertedTiles, tileList[i].getName()));
    else if(checkInsertion(tileList, matrix, listOfInsertedTiles, i, k)) return true;
  }
  return false;
}


bool checkInsertion(vector<Tile> tileList, Tile matrix[9], vector<char> listOfInsertedTiles, int i, int k){
  do{
    switch(k){
      case 0:
        //do{
          listOfInsertedTiles.push_back(tileList[i].getName());
          matrix[k] = tileList[i];
          cout << "Case 0 with: i = " << i << " and k = " << k << " " <<tileList[i] << endl;
          if(solvePattern(tileList, matrix, listOfInsertedTiles, i+1, k+1)) return true;
          listOfInsertedTiles.pop_back();
        //}while(matrix[k].rotate());
        break;
      case 1:
      case 2:
        //do{
          cout << "Case 1 & 2 with: i = " << i << " and k = " << k-1 << " " <<tileList[i] << endl;
          if(matrix[k-1].getRight() + tileList[i].getLeft() == 0){
            cout << "hey";
            listOfInsertedTiles.push_back(tileList[i].getName());
            cout << "Case 1 & 2 with: i = " << i << " and k = " << k << " " <<tileList[i] << endl;
            if(solvePattern(tileList, matrix, listOfInsertedTiles, i+1, k+1)) return true;
            listOfInsertedTiles.pop_back();
          }
        //}while(tileList[i].rotate());
        break;
      case 3:
        cout << "Case 3 k = " << k/2 - 1 << endl;
        //do{
          if(matrix[k/2-1].getBot() + tileList[i].getTop() == 0){
            listOfInsertedTiles.push_back(tileList[i].getName());
            cout << "Case 3 with: i = " << i << " and k = " << k << " " <<tileList[i] << endl;
            if(solvePattern(tileList, matrix, listOfInsertedTiles, i+1, k+1)) return true;
            listOfInsertedTiles.pop_back();
          }
        //}while(tileList[i].rotate());
        break;
      case 4:
      case 5:
        cout << "Case 5 k = " << k - 1  << " and k = " << k/2 -1 << endl;
        //do{
          if(matrix[k-1].getRight() + tileList[i].getLeft() == 0 && matrix[k/2-1].getBot() + tileList[i].getTop() == 0){
            listOfInsertedTiles.push_back(tileList[i].getName());
            cout << "Case 4 and 5 with: i = " << i << " and k = " << k << " " <<tileList[i] << endl;
            if(solvePattern(tileList, matrix, listOfInsertedTiles, i+1, k+1)) return true;
            listOfInsertedTiles.pop_back();
          }
        //}while(tileList[i].rotate());
        break;
      case 6:
        cout << "Case 6 k = " << k/2 << endl;
        //do{
          if(matrix[k/2].getBot() + tileList[i].getTop() == 0){
            listOfInsertedTiles.push_back(tileList[i].getName());
            cout << "Case 6 with: i = " << i << " and k = " << k << " " <<tileList[i] << endl;
            if(solvePattern(tileList, matrix, listOfInsertedTiles, i+1, k+1)) return true;
            listOfInsertedTiles.pop_back();
          }
        //}while(tileList[i].rotate());
        break;
      case 7:
      case 8:
        cout << "Case 8 k = " << k - 1  << " and k = " << k/2 + 1 << endl;
        //do{
          if(matrix[k-1].getRight() + tileList[i].getLeft() == 0 && matrix[k/2+1].getBot() + tileList[i].getTop() == 0){
            listOfInsertedTiles.push_back(tileList[i].getName());
            cout << "Case 7 & 8 with: i = " << i << " and k = " << k << " " <<tileList[i] << endl;
            if(solvePattern(tileList, matrix, listOfInsertedTiles, i+1, k+1)) return true;
            listOfInsertedTiles.pop_back();
          }
        //}while(tileList[i].rotate());
        break;
    }
    cout << "Gonna rotate with: i = " << i << " and k = " << k << " " <<tileList[i] << endl;
  }while(tileList[i].rotate());
  return false;
}


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
void printMatrix(Tile tileMatrix[9]){
  cout << "The solution is the following:\n";
  for (int i = 0; i < 9; i++){
    if(i == 3 || i == 6){
      cout << endl << tileMatrix[i].getName() << " ";
    }
    else{
      cout << tileMatrix[i].getName() << " ";
    }
  }
  cout << endl;
}

//possible solution
/*bool solvePattern(vector<Tile> tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int row, int col){
  int i;
  bool checked;
  stateIteration(tileList, false);
  while(!tileList.empty() && stateIteration(tileList, true)){
	i = tileList.size()-1;
	if (!tileList[i].getState()) {
		cout << "Inserting: " << tileList[i] << endl;
		tileMatrix[row][col] = tileList[i]; // inserting the element into the matrix
		tileList.pop_back();
		checked = true;
	}
	else checked = false;
	if (checked) {
		if (row == 0 && col == 0) {
			cout << "Doing the first element: " << tileMatrix[row][col] << endl;
			do {
				if (row == 0) {//first row
					if (firstRow(tileList, tileMatrix, i, row, col)) return true;
				}
				else if (row == 1 || row == 2) {//second or third rows
					if (secondOrThirdRow(tileList, tileMatrix, i, row, col)) return true;
				}

			} while (tileMatrix[row][col].rotate());//rotate 'A'
		}
		else {
			if (row == 0) {//first row
				if (firstRow(tileList, tileMatrix, i, row, col)) return true;
			}
			else if (row == 1 || row == 2) {//second or third rows
				if (secondOrThirdRow(tileList, tileMatrix, i, row, col)) return true;
			}
		}
		tileList.push_back(tileMatrix[row][col]);
		//while (tileMatrix[row][col].rotate());
	}
    rotateTile(tileList, i);
  }
  //there is no matching solution
  return false;
}

bool firstRow(vector<Tile> &tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int i, int row, int col){
  do{
    //if the edges additively equate to zero
    if((tileMatrix[row][col].getRight() + tileList[i-1].getLeft()) == 0){
	  tileList[i - 1].changeState(true);
      if(col+1 < MATRIXSIZE){ //if the current column is not the last element of the row
        if(solvePattern(tileList, tileMatrix, row, col+1)) return true;
      }
      else{//otherwise call the function at location row+1 column 0
        if(solvePattern(tileList, tileMatrix, row+1, 0)) return true;
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
        if(solvePattern(tileList, tileMatrix, row, col+1)) return true;
      }
      else{//otherwise call the function at location row+1 column 0
        if(solvePattern(tileList, tileMatrix, row+1, 0)) return true;
      }
    }
  }while(tileList[i-1].rotate());
  return false;
}

bool stateIteration(vector<Tile> tileList, bool check) {
	for (vector<Tile>::reverse_iterator rit = tileList.rbegin(); rit != tileList.rend(); rit++) {
		if (check) {
			if (!(rit->getState())) return true;
		}
		else {
			rit->changeState(false);
		}
	}
	return false;
}*/
