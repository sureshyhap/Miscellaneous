#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "SuDoku.h"

int main(int argc, char* argv[]) {
  /*
  // Easy Puzzle 10,152,324,601
  int a[SuDoku::SIZE][SuDoku::SIZE] =
    { {5, 6, 0, 4, 9, 0, 7, 0, 0},
	{0, 0, 1, 0, 5, 0, 0, 0, 0},
	{3, 0, 9, 0, 2, 0, 1, 0, 5},
	{0, 2, 7, 0, 0, 0, 0, 0, 4},
	{0, 5, 0, 9, 8, 7, 0, 1, 0},
	{1, 0, 0, 0, 0, 0, 5, 7, 0},
	{7, 0, 2, 0, 3, 0, 4, 0, 8},
	{0, 0, 0, 0, 6, 0, 9, 0, 0},
	{0, 0, 4, 0, 7, 2, 0, 5, 1}
  };
  */
  int a[SuDoku::SIZE][SuDoku::SIZE] = {{0}};
  std::string s;
  std::cout << "Enter the input file name: ";
  std::cin >> s;
  std::ifstream infile(s);
  std::string row;
  // The first top line is information about the puzzle
  getline(infile, row);
  // Read from the file a representation of a puzzle
  for (int i = 0; i < SuDoku::SIZE; ++i) {
    getline(infile, row);
    std::istringstream is(row);
    for (int j = 0; j < SuDoku::SIZE; ++j) {
      is >> a[i][j];
    }
  }
  /*
  std::cout << "Enter blanks as 0s." << std::endl;
  for (int i = 0; i < SuDoku::SIZE; ++i) {
    std::cout << "Enter ";
    switch (i) {
    case 0:
      std::cout << "first ";
      break;
    case 1:
      std::cout << "second ";
      break;
    case 2:
      std::cout << "third ";
      break;
    case 3:
      std::cout << "fourth ";
      break;
    case 4:
      std::cout << "fifth ";
      break;
    case 5:
      std::cout << "sixth ";
      break;
    case 6:
      std::cout << "seventh ";
      break;
    case 7:
      std::cout << "eighth ";
      break;
    case 8:
      std::cout << "ninth ";
      break;
    }
    std::cout << "row: ";
    for (int j = 0; j < SuDoku::SIZE; ++j) {
      std::cin >> a[i][j];
    }
  }
  */
  SuDoku sudoku(a);
  sudoku.print();
  sudoku.solve();
  sudoku.print();
  return 0;
}
