#ifndef _SUDOKU_H
#define _SUDOKU_H

const int DIMENSION = 9;

class SuDoku {
 private:
  int board[DIMENSION][DIMENSION] = {{0}};
 public:
  SuDoku(int puzzle_board[][DIMENSION]);
  void print_puzzle();
  void solve_puzzle();
};

#endif
