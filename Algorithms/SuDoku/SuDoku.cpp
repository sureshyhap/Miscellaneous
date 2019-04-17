#include "SuDoku.h"
#include <iostream>

SuDoku::SuDoku(int a[SuDoku::SIZE][SuDoku::SIZE]) {
  for (int i = 0; i < SuDoku::SIZE; ++i) {
    for (int j = 0; j < SuDoku::SIZE; ++j) {
      puzzle[i][j];
      puzzle[i][j].change_num(a[i][j]);
      if (a[i][j] != 0) {
	puzzle[i][j].change_is_solved(true);
	puzzle[i][j].change_possibilities(a[i][j], true);
      }
    }
  }
}

void SuDoku::print() const {
  for (int i = 0; i < SuDoku::SIZE; ++i) {
    std::cout << "-------------------------------------------------------" << std::endl;
    for (int j = 0; j <= SuDoku::SIZE; ++j) {
      std::cout << "|     ";
    }
    std::cout << std::endl;
    for (int j = 0; j < SuDoku::SIZE; ++j) {
      if (puzzle[i][j].num != 0) {
	std::cout << "|  " << puzzle[i][j].num << "  ";
      }
      else {
	std::cout << "|  " << " " << "  ";
      }
    }
    std::cout << "|" << std::endl;
    for (int j = 0; j <= SuDoku::SIZE; ++j) {
      std::cout << "|     ";
    }
    std::cout << std::endl;
  }
  std::cout << "-------------------------------------------------------" << std::endl;
}

void SuDoku::solve() {
  bool changed_num = true;
  while (changed_num == true) {
    changed_num = false;
    for (int i = 0; i < SuDoku::SIZE; ++i) {
      for (int j = 0; j < SuDoku::SIZE; ++j) {
	if (puzzle[i][j].get_is_solved() == false) {
	  check_row(i, j);
	  check_column(i, j);
	  check_box(i, j);
	  ///////////////////////////////////////////////
	  check_row_possibilities(i, j);
	  check_column_possibilities(i, j);
	  check_box_possibilities(i, j);
	  ///////////////////////////////////////////////
	  const bool* poss = puzzle[i][j].get_possibilities();
	  int num_possibilities = SuDoku::SIZE;
	  int possible_num = 0;
	  for (int k = 1; k <= SuDoku::SIZE; ++k) {
	    if (poss[k] == false) {
	      --num_possibilities;
	    }
	    else {
	      possible_num = k;
	    }
	  }
	  if (num_possibilities == 1) {
	    puzzle[i][j].change_num(possible_num);
	    puzzle[i][j].change_is_solved(true);
	    for (int a = 1; a <= SuDoku::SIZE; ++a) {
	      puzzle[i][j].change_possibilities(a, false);
	    }
	    puzzle[i][j].change_possibilities(possible_num, true);
	    changed_num = true;
	  }
	}
      }
    }
  }
}

SuDoku::Cell::Cell(int n, bool is) : num(n), is_solved(is) {
  for (int i = 1; i <= SuDoku::SIZE; ++i) {
    if (is_solved == true) {
      possibilities[i] = false;
    }
    else {
      possibilities[i] = true;
    }
  }
  if (is_solved == true) {
    possibilities[num] = true;
  }
}

void SuDoku::Cell::change_num(int n) {
  num = n;
}

void SuDoku::Cell::change_is_solved(bool is) {
  is_solved = is;
}

void SuDoku::Cell::change_possibilities(int num, bool truth_val) {
  possibilities[num] = truth_val;
}

int SuDoku::Cell::get_num() const {
  return num;
}

bool SuDoku::Cell::get_is_solved() const {
  return is_solved;
}

const bool* SuDoku::Cell::get_possibilities() const {
  return possibilities;
}

void SuDoku::check_row(int row, int column) {
  for (int j = 0; j < SuDoku::SIZE; ++j) {
    if (j == column) {
      continue;
    }
    if (puzzle[row][j].get_is_solved() == true) {
      puzzle[row][column].change_possibilities(puzzle[row][j].get_num(), false);
    }
  }
}

void SuDoku::check_column(int row, int column) {
  for (int i = 0; i < SuDoku::SIZE; ++i) {
    if (i == row) {
      continue;
    }
    if (puzzle[i][column].get_is_solved() == true) {
      puzzle[row][column].change_possibilities(puzzle[i][column].get_num(), false);
    }
  }
}

void SuDoku::check_box(int row, int column) {
  int box_row = 0, box_column = 0;
  switch (row) {
  case 0:
  case 1:
  case 2:
    box_row = 0;
    break;
  case 3:
  case 4:
  case 5:
    box_row = 1;
    break;
  case 6:
  case 7:
  case 8:
    box_row = 2;
    break;
  }
  switch (column) {
  case 0:
  case 1:
  case 2:
    box_column = 0;
    break;
  case 3:
  case 4:
  case 5:
    box_column = 1;
    break;
  case 6:
  case 7:
  case 8:
    box_column = 2;
    break;
  }
  const int ROWS_IN_BOX = 3;
  const int COLUMNS_IN_BOX = 3;
  int start_row = box_row * ROWS_IN_BOX;
  int start_column = box_column * COLUMNS_IN_BOX;
  for (int i = start_row; i < start_row + ROWS_IN_BOX; ++i) {
    for (int j = start_column; j < start_column + COLUMNS_IN_BOX; ++j) {
      if (puzzle[i][j].get_is_solved() == true) {
	puzzle[row][column].change_possibilities(puzzle[i][j].get_num(), false);
      }
    }
  }
}

void SuDoku::check_row_possibilities(int row, int column) {
  for (int k = 1; k <= SuDoku::SIZE; ++k) {
    bool cant_determine = false;
    for (int j = 0; j < SuDoku::SIZE && cant_determine == false; ++j) {
      if (j == column) {
	continue;
      }
      const bool* p = puzzle[row][j].get_possibilities();
      if (p[k] == true) {
	cant_determine = true;
      }
    }
    if (cant_determine == false) {
      for (int a = 1; a <= SuDoku::SIZE; ++a) {
	puzzle[row][column].change_possibilities(a, false);
      }
      puzzle[row][column].change_possibilities(k, true);
      return;
    }
  }
}

void SuDoku::check_column_possibilities(int row, int column) {
  for (int k = 1; k <= SuDoku::SIZE; ++k) {
    bool cant_determine = false;
    for (int i = 0; i < SuDoku::SIZE && cant_determine == false; ++i) {
      if (i == row) {
	continue;
      }
      const bool* p = puzzle[i][column].get_possibilities();
      if (p[k] == true) {
	cant_determine = true;
      }
    }
    if (cant_determine == false) {
      for (int a = 1; a <= SuDoku::SIZE; ++a) {
	puzzle[row][column].change_possibilities(a, false);
      }
      puzzle[row][column].change_possibilities(k, true);
      return;
    }
  }
}

void SuDoku::check_box_possibilities(int row, int column) {
  int box_row = 0, box_column = 0;
  switch (row) {
  case 0:
  case 1:
  case 2:
    box_row = 0;
    break;
  case 3:
  case 4:
  case 5:
    box_row = 1;
    break;
  case 6:
  case 7:
  case 8:
    box_row = 2;
    break;
  }
  switch (column) {
  case 0:
  case 1:
  case 2:
    box_column = 0;
    break;
  case 3:
  case 4:
  case 5:
    box_column = 1;
    break;
  case 6:
  case 7:
  case 8:
    box_column = 2;
    break;
  }
  const int ROWS_IN_BOX = 3;
  const int COLUMNS_IN_BOX = 3;
  int start_row = box_row * ROWS_IN_BOX;
  int start_column = box_column * COLUMNS_IN_BOX;
  for (int k = 1; k <= SuDoku::SIZE; ++k) {
    bool cant_determine = false;
    for (int i = start_row; i < start_row + ROWS_IN_BOX && cant_determine == false; ++i) {
      for (int j = start_column; j < start_column + COLUMNS_IN_BOX && cant_determine == false; ++j) {
	const bool* p = puzzle[i][j].get_possibilities();
	if (p[k] == true) {
	  cant_determine = true;
	}
      }
    }
    if (cant_determine == false) {
      for (int a = 1; a <= SuDoku::SIZE; ++a) {
	puzzle[row][column].change_possibilities(a, false);
      }
      puzzle[row][column].change_possibilities(k, true);
      return;      
    }
  }
}
