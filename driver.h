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
bool solvePattern(vector<Tile>, Tile[3][3], int tileNum = 0);
vector<Tile> rotateTile(vector<Tile> tileList);
void printMatrix(Tile tileMatrix[3][3]);
