#pragma once

//driver header file
//driver.h

//program libraries needed
#include <iostream>
#include <fstream>
#include "tile.h"

using namespace std;

const int MATRIXSIZE = 3;

//function prototypes
void fileCheck(ifstream& input);
void readFile(ifstream& input);
bool solvePattern(vector<Tile>, Tile[MATRIXSIZE][MATRIXSIZE], int tileNum = 0, int row = 0, int col = 0);
vector<Tile> rotateTile(vector<Tile> tileList);
void printMatrix(Tile tileMatrix[MATRIXSIZE][MATRIXSIZE]);
