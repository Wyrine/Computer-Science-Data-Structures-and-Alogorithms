#pragma once

//driver header file
//driver.h

//program libraries needed
#include <iostream>
#include <fstream>
#include "tile.h"

using namespace std;


//function prototypes
void fileCheck(ifstream& input);
void readFile(ifstream& input);
void printMatrix(Tile tileMatrix[9]);
bool solvePattern(vector<Tile> tileList, Tile[9], int i = 0, int k = 0);
bool checkInsertion(vector<Tile> tileList, Tile[9], int i, int k, int startNum);
vector<Tile> swapTiles(vector<Tile> tileList, int start, int current);
bool swapAndInsert(vector<Tile> tileList, Tile matrix[9], int i, int k, int startNum);
