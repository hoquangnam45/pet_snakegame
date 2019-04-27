#include "Snake.h"
Snake::Snake(){};

Snake::~Snake(){
    //delete snakeBody.getHead();
};

LinkedList<Cell>& Snake::getSnakeBody(){
    return snakeBody;
}

int Snake::getLength(){
    return snakeBody.getSize();
}

void Snake::initSnake(int x, int y, int length){
    for (int i = 0; i < length; i++){
        Cell snakePart;
        snakePart.setType(cellType::SNAKE);
        snakePart.setRowCol(x, y + i);
        snakeBody.addTail(snakePart);
    }
}
void Snake::moveUp(){
    if (move_direction == direction::DOWN) {
        move();
        return;
    }
    move_direction = direction::UP;
    Cell oldHead = snakeBody.getHead()->getData();
    Cell newHead = oldHead; // copy first
    newHead.setRow(oldHead.getRow() - 1);
    snakeBody.addHead(newHead);
    if(!grow_flag) snakeBody.deleteTail();
    else grow_flag = 0;
}
void Snake::moveDown(){
    if (move_direction == direction::UP) {
        move();
        return;
    }
    move_direction = direction::DOWN;
    Cell oldHead = snakeBody.getHead()->getData();
    Cell newHead = oldHead; // copy first
    newHead.setRow(oldHead.getRow() + 1);
    snakeBody.addHead(newHead);
    if(!grow_flag) snakeBody.deleteTail();
    else grow_flag = 0;
};
void Snake::moveLeft(){
    if (move_direction == direction::RIGHT) {
        move();
        return;
    }
    move_direction = direction::LEFT;
    Cell oldHead = snakeBody.getHead()->getData();
    Cell newHead = oldHead; // copy first
    newHead.setCol(oldHead.getCol() - 1);
    snakeBody.addHead(newHead);
    if(!grow_flag) snakeBody.deleteTail();
    else grow_flag = 0;
};
void Snake::moveRight(){
    if (move_direction == direction::LEFT) {
        move();
        return;
    }
    move_direction = direction::RIGHT;
    Cell oldHead = snakeBody.getHead()->getData();
    Cell newHead = oldHead; // copy first
    newHead.setCol(oldHead.getCol() + 1);
    snakeBody.addHead(newHead);
    if(!grow_flag) snakeBody.deleteTail();
    else grow_flag = 0;
};
void Snake::move(){
    switch(move_direction){
        case direction::LEFT:
            moveLeft();
            break;
        case direction::RIGHT:
            moveRight();
            break;
        case direction::UP:
            moveUp();
            break;
        case direction::DOWN:
            moveDown();
            break;
    }
}
void Snake::eat(){
    grow_flag = 1;
};
bool Snake::hasEaten(){
    return grow_flag;
}