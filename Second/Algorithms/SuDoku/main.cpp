#include <iostream>
#include "sudoku.h"
#include <fstream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) {
  std::cout << "Enter filename: ";
  std::string input_filename;
  std::cin >> input_filename;


  input_filename = "easy_puzzle_1.txt";

  
  std::ifstream infile(input_filename);
  if (!infile.is_open()) {
    std::cerr << "Could not open file.\n";
    exit(1);
  }
  char ch = {};
  int count = 0;
  int board[DIMENSION][DIMENSION] = {{0}};
  while (infile.get(ch)) {
    if (!isdigit(ch)) {
      continue;
    }
    board[count / 9][count % 9] = int(ch - '0');
    ++count;
  }
  SuDoku sudoku(board);
  sudoku.print_puzzle();
  infile.close();
  return 0;
}
