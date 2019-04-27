#include "Food.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
Food::Food(){
    srand(time(0));
};
Food::~Food(){};
int Food::generatePosition(int numberOfPlayableCell, int snakeLength){
    if (numberOfPlayableCell < snakeLength) {
        return -1;
    }
    if ((rand() % 100) + 1 > p_foodAppear) {
        return -1;
    }
    return rand() % (numberOfPlayableCell - snakeLength) + 1;
}