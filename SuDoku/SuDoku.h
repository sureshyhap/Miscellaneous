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
    bool possibilities[SIZE + 1];
  };
  void check_row(int row, int column);
  void check_column(int row, int column);
  void check_box(int row, int column);
  Cell puzzle[SIZE][SIZE];
};

#endif //SUDOKU_H
