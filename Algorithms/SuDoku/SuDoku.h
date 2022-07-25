#ifndef SUDOKU_H
#define SUDOKU_H

class SuDoku {
 public:
  static const int SIZE = 9;
  SuDoku(int a[SIZE][SIZE]);
  void print() const;
  void solve();
 protected:
  class Cell {
    friend class SuDoku;
  public:
    Cell(int n = 0, bool is = false);
    void change_num(int n);
    void change_is_solved(bool is);
    void change_possibilities(int num, bool truth_val);
    int get_num() const;
    bool get_is_solved() const;
    const bool* get_possibilities() const;
  protected:
    int num;
    bool is_solved;
    // 1 - indexed (Not 0 - indexed)
    // possibilities[0] is not used
    bool possibilities[SIZE + 1];
  };
  // Checks using other numbers in the row/column/box
  void check_row(int row, int column);
  void check_column(int row, int column);
  void check_box(int row, int column);
  // Checks using possibilities in the other cells
  // in the row, column, box
  void check_row_possibilities(int row, int column);
  void check_column_possibilities(int row, int column);
  void check_box_possibilities(int row, int column);
  // The actual puzzle itself
  Cell puzzle[SIZE][SIZE];
};

#endif //SUDOKU_H
