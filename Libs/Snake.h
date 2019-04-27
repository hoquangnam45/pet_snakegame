#include "Cell.h"
#include "LinkedList.h"
enum direction{
    LEFT,
    RIGHT,
    UP, 
    DOWN
};
class Snake{
    public:
        Snake();
        ~Snake();
        LinkedList<Cell>& getSnakeBody();
        int getLength();
        void initSnake(int x, int y, int length=3);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void move();
        void eat();
        bool hasEaten();
        //void updateBoard(Board);
    private:
        LinkedList<Cell> snakeBody;
        bool initUpdateBoard = 0;
        bool grow_flag = 0;
        direction move_direction = LEFT; 
};