//driver program for recursive tile program
//main.cpp

//libraries used for the program
#include "driver.h"

//namespace used for the program
using namespace std;

int main(){
  cout << "Welcome to the tile recursive solution program.\n";
  //opening the data file that is used.
  ifstream input("ola4data.txt");
  //if the file fails to open, call fileCheck
  if(input.fail()) fileCheck(input);
  //closes input file after use
  input.close();
}
