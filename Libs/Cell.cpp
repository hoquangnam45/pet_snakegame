#include "Cell.h"
Cell::Cell(cellType type){
    this->type = type;
}
Cell::Cell(){
    row = col = 0;
    type = EMPTY;
};
Cell::~Cell(){};

void Cell::setType(enum cellType type){
    this->type = type;
};
cellType& Cell::getType(){
    return type;
};
void Cell::setRowCol(int row, int col){
    this->row = row;
    this->col = col;
};
void Cell::setRow(int row){
    this->row = row;
}
void Cell::setCol(int col){
    this->col = col;
};
int Cell::getRow(){
    return row;
};
int Cell::getCol(){
    return col;
};
Cell& Cell::operator= (const Cell& newCell){
    this->type = newCell.type;
    this->row = newCell.row;
    this->col = newCell.col;
};