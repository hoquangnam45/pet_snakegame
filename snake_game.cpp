#include <iostream>
#include <string>
#include <unistd.h>
#include "Libs/Board.h"
using namespace std;
int main(){
    cout << "\033[2J\033[1;1H";
    //bool start = 0;
    string start;
    cout << "Bắt đầu trò chơi(Y/n)" << endl;
    // cin >> start;
    // if (start != "Y" && start != "y" && start != "yes" && start != "Yes") {
    //     cout << "\033[2J\033[1;1H";
    //     return 0;
    // }
    //Size board_size = Size(20,20);
    cout << "Để thoát game nhấn q" << endl;
    usleep(1e6);
    Board game_board(Size(11, 11));
    game_board.run();
    //
    // game_board.clearScreen();
    // game_board.printBoard();
    return 0;
}
