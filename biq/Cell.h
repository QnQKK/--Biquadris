#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>
#include "Window.h"


class Cell {
  bool Active;
  bool blind;
  std::string color;
  Xwindow *window;
  int x;
  int y;
  int width = 25;
  int height = 25;

  public:
  Cell();  // Default constructor
  ~Cell(); // Destructor
  void Activate(std::string new_color);
  void Deactivate(std::string new_color);
  void TurnBlind();
  void NotBlind();
  std::string GetColor ();
    
  bool isActive();

  void draw(int row, int col, Xwindow * board); 

  friend std::ostream& operator<<(std::ostream &out, const Cell &c);
};


#endif