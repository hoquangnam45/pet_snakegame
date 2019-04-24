#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;
int main(){
    cout << "\033[2J\033[1;1H";
    //bool start = 0;
    string start;
    cout << "Bắt đầu trò chơi(Y/n)" << endl;
    cin >> start;
    if (start != "Y" && start != "y" && start != "yes" && start != "Yes") {
        cout << "\033[2J\033[1;1H";
        return 0;
    }
    cout << "\033[2J\033[1;1H";
    cout << "Để thoát game nhấn q" << endl;
    sleep(3);
    return 0;
}