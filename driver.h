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
//bool solvePattern(vector<Tile> tileList, Tile[MATRIXSIZE][MATRIXSIZE], int row = 0, int col = 0);
void rotateTile(vector<Tile> &tileList, int current);
void printMatrix(Tile tileMatrix[9]);
//bool firstRow(vector<Tile> &tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int i, int row, int col);
//bool secondOrThirdRow(vector<Tile> &tileList, Tile tileMatrix[MATRIXSIZE][MATRIXSIZE], int i, int row, int col);
//bool stateIteration(vector<Tile> tileList, bool check);
bool charInList(vector<char> tileInList, char tileName);
bool solvePattern(vector<Tile> tileList, Tile[9], vector<char> listOfInsertedTiles, int i = 0, int k = 0);
bool checkInsertion(vector<Tile> tileList, Tile[9], vector<char> listOfInsertedTiles, int i, int k);
