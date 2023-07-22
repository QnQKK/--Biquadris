#include "Cell.h"


using namespace std;

Cell::Cell(): Active(false), blind(false), color(" "), window(nullptr), x(0), y(0) {}

Cell::~Cell() {}

void Cell::Activate(string new_color) {
    Active = true;
    color = new_color;
}

void Cell::Deactivate(string new_color) {
    Active = false;
    color = new_color;
}

void Cell::TurnBlind() {
    blind = true;
}

void Cell::NotBlind() {
    blind = false;
}


bool Cell::isActive() {
    return Active;
}

ostream &operator<<(ostream &out, const Cell &c) {
    if (!(c.blind)) {
    out << c.color;
    }
    else {
        out << "?";
    }
    return out;
}


string Cell::GetColor() {
    return color;
}





void Cell::draw(int row, int col, Xwindow *board){
   if (color == "I") {
     board->fillRectangle(row * 25, col *25, 25, 25, 7);
   } else if (color == "J"){
     board->fillRectangle(row * 25, col *25, 25, 25, 2);
   } else if (color == "L"){
     board->fillRectangle(row * 25, col *25, 25, 25, 0);
   } else if (color == "Z"){
     board->fillRectangle(row * 25, col *25, 25, 25, 6);
   } else if (color == "S"){
     board->fillRectangle(row * 25, col *25, 25, 25, 3);
   } else if (color == "O"){
     board->fillRectangle(row * 25, col *25, 25, 25, 4);
   } else if (color == "T"){
     board->fillRectangle(row * 25, col *25, 25, 25, 8);
   } else if (color == " ") {
     board->fillRectangle(row * 25, col *25, 25, 25, 1);
   }else if (color == "*"){
     board->fillRectangle(row * 25, col *25, 25, 25, 9);
   }

    if (blind) {
        board->fillRectangle(row * 25, col *25, 25, 25, 1);
    }
}

