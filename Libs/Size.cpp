#include "Size.h"

Size::Size(){
    x = y = 0;
}
Size::~Size(){};
Size::Size(int x, int y){
    this->x = x;
    this->y = y;
}
Size& Size::operator= (const Size& b){
    this->x = b.x;
    this->y = b.y;
}
int Size::getX(){
    return x;
}
int Size::getY(){
    return y;
};
int Size::flattenSize(){
    return x * y;
};