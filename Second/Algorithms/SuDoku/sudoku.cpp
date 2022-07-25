#include "sudoku.h"
#include <iostream>
#include <string>

SuDoku::SuDoku(int puzzle_board[][DIMENSION]) {
  for (int i = 0; i < DIMENSION; ++i) {
    for (int j = 0; j < DIMENSION; ++j) {
      board[i][j] = puzzle_board[i][j];
    }
  }
}

void SuDoku::print_puzzle() {
  std::string line = "-------------------------------------------------------\n";
  std::string line_bars = "|     |     |     |     |     |     |     |     |     |\n";
  std::cout << line;
  for (int i = 0; i < DIMENSION; ++i) {
    std::cout << line_bars;
    std::cout << '|';
    for (int j = 0; j < DIMENSION; ++j) {
      std::cout << "  " << board[i][j] << "  |";
    }
    std::cout <<  '\n' << line_bars;
    std::cout << line;
  }
}



