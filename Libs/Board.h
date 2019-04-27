#include "Size.h"
#include "Snake.h"
// #include "Snake.h"
#include "Food.h"
#define CELL_PRINT_SIZE 1
class Board{
    public:
        Board();
        ~Board();
        Board(Size);
        void initBoard(Size);
        void printBoard();
        void clearScreen();
        int flatIndex(int row, int col);
        int isGameOver();
        void run();
        // void clearBoard();
        void updateBoard();
        // void updateBoard(Food&);
        // void updateBoard(Snake&);
    private:
        const int defaultSnakeLength = 3;
        Size board_size;
        Cell* board_cell;
        char* board_buffer;
        Snake medusa;
        Food apple;
        int numPlayableCell = 0;
        Cell oldTail;
        int foodPos; // for debugging
        int score = 0;
        bool gameOver = 0; // determine if gameover
        bool moveFlag = 0; // determine if snake move
        bool foodFlag = 0; // determine if food generated
        bool growFlag = 0; // determine if snake grew
};