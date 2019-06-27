#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "SuDoku.h"

int main(int argc, char* argv[]) {
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
  infile.close();
  SuDoku sudoku(a);
  sudoku.print();
  sudoku.solve();
  sudoku.print();
  return 0;
}
