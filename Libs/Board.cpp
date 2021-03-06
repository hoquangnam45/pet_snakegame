#include "Board.h"
#include <iostream>
#include <iomanip>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
using namespace std;
#define CHAR_SNAKE_HEAD 'O'
#define CHAR_SNAKE_BODY 'K'
#define CHAR_FOOD '$'
bool kbhit(){
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}
char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

Board::Board(){
	board_cell = nullptr;
	board_buffer = nullptr;
};

Board::Board(Size board_size){
	initBoard(board_size);
}
Board::~Board(){
	delete[] board_buffer;
	delete[] board_cell;
	//clearBoard();
};
void Board::initBoard(Size board_sizes){
	this->board_size = board_sizes;
	int flatten_size = board_size.flattenSize();
	//cout << flatten_size + board_size.getY() << endl;
	board_cell = new Cell[flatten_size + board_size.getY()];
	board_buffer = new char[flatten_size + board_size.getY() + 1];
	board_buffer[flatten_size + board_size.getY() + 1] = '\0';
	for (int i = 0; i < flatten_size + board_size.getY(); i++){
		int row = i / (board_size.getX() + 1) + 1;
		int col = i - (row - 1) * (board_size.getX() + 1) + 1;
		// cout << row << " " << col << endl;
		board_cell[i].setRowCol(row, col);
		if (col == 1 || col == board_size.getX()) {
			board_buffer[i] = '|';
			board_cell[i].setType(cellType::WALL);
		}
		else if(col == board_size.getX() + 1){
			board_buffer[i] = '\n';
			board_cell[i].setType(cellType::EMPTY);
		}
		else if(row == 1 || row == board_size.getY()){
			board_buffer[i] = '~';
			board_cell[i].setType(cellType::WALL);
		}
		else{
			board_buffer[i] = ' ';
			board_cell[i].setType(cellType::EMPTY);
			numPlayableCell++;
		}
	}
	medusa.initSnake(board_size.getY() / 2 + 1, (board_size.getX() - defaultSnakeLength) / 2 + 1, defaultSnakeLength);
	LinkedNode<Cell>* snakeSegment = medusa.getSnakeBody().getHead();
	int idx = 0;
	while(snakeSegment){
		int row = snakeSegment->getData().getRow();
		int col = snakeSegment->getData().getCol();
		if (board_cell[flatIndex(row, col)].getType() == cellType::WALL || 
			board_cell[flatIndex(row, col)].getType() == cellType::SNAKE) 
		{
			gameOver = 1;
			return;
		}
		board_cell[flatIndex(row, col)] = snakeSegment->getData();
		if (!idx) board_buffer[flatIndex(row, col)] = CHAR_SNAKE_HEAD;
		else board_buffer[flatIndex(row, col)] = CHAR_SNAKE_BODY;
		idx++;
		snakeSegment = snakeSegment->getNextNode();
	}
};
void Board::printBoard(){
	clearScreen();
	cout << board_buffer;
}
void Board::clearScreen(){
	cout << "\033[2J\033[1;1H";
}
int Board::flatIndex(int row, int col){
	return (row - 1) * (board_size.getX() + 1) + col - 1;
};
void Board::run(){
	oldTail = medusa.getSnakeBody().getTail()->getData();
	while(!gameOver && numPlayableCell - medusa.getLength()){
		moveFlag = 0;
		if (kbhit()){
			oldTail = medusa.getSnakeBody().getTail()->getData();
			switch(getch()){
				case 'w':
					medusa.moveUp();
					break;
				case 's':
					medusa.moveDown();
					break;
				case 'a':
					medusa.moveLeft();
					break;
				case 'd':
					medusa.moveRight();
					break;
				case 'q':
					gameOver = 1;
					goto Score_output;
					break;
				default:
					medusa.move();
					break;
			}
			moveFlag = 1;
		}
		else {
			oldTail = medusa.getSnakeBody().getTail()->getData();
			medusa.move();
			moveFlag = 1;
		}

		//cout << "ss" << endl;
	// 	else 
	// 	move();
		updateBoard();
		printBoard();
		usleep(3e5);
	}
	Score_output:
	cout << "OK, Bạn rất bá đạo, ghi được " << score << " điểm" << endl;
}
// void Board::clearBoard(){
//     delete board_cell;\
// };

void Board::updateBoard(){
	if(moveFlag){
		int headRow = medusa.getSnakeBody().getHead()->getData().getRow();
		int headCol = medusa.getSnakeBody().getHead()->getData().getCol();
		int headNextRow = medusa.getSnakeBody().getHead()->getNextNode()->getData().getRow();
		int headNextCol = medusa.getSnakeBody().getHead()->getNextNode()->getData().getCol();

		Cell headCell = board_cell[flatIndex(headRow, headCol)].getType();
		// Update head
		board_buffer[flatIndex(headRow, headCol)] = CHAR_SNAKE_HEAD;
		board_buffer[flatIndex(headNextRow, headNextCol)] = CHAR_SNAKE_BODY;
		board_cell[flatIndex(headRow, headCol)].setType(cellType::SNAKE);
		// Update tail 
		if (!growFlag){
			board_buffer[flatIndex(oldTail.getRow(), oldTail.getCol())] = ' ';
			board_cell[flatIndex(oldTail.getRow(), oldTail.getCol())].setType(cellType::EMPTY);
		}
		else growFlag = 0;

		// Check if there is food
		if (headCell.getType() == cellType::FOOD){
			medusa.eat();
			growFlag = 1;
			foodFlag = 0;
			score++;
		}
		else if(headCell.getType() == cellType::SNAKE || headCell.getType() == cellType::WALL){
			gameOver = 1;
		}
	}
	
	if (!foodFlag){
		int randomCell = apple.generatePosition(numPlayableCell, medusa.getLength());
		if(randomCell != -1){
			int i = -1;
			do{
				i++;
				while (i % (board_size.getX() + 1) == board_size.getX() || board_cell[i].getType() != cellType::EMPTY) i++;	
			}
			while (--randomCell);
			board_cell[i].setType(cellType::FOOD);
			board_buffer[i] = CHAR_FOOD;
			foodPos = i;
			foodFlag = 1;
		};
	}
};