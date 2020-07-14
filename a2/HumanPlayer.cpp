#include <iostream>
#include "HumanPlayer.h"
#include <string>
// #include <vector>

HumanPlayer::HumanPlayer(char symb) : Player(symb) {

}

HumanPlayer::~HumanPlayer() {

}

void HumanPlayer::get_move(OthelloBoard* b, int& col, int& row, char c) {

    int n;
    std::cout << "Enter the row followed by the column with no spaces between:" << '\n';
    std::cin>>n;
    row = n/10;
    col = n%10;
    if(!std::cin.good()){
      std::cout<<"Please enter a two digit number, the tens place being the row and the ones place representing the column."<<std::endl;
      std::cin.clear();
      std::cin.ignore(99999999, '\n');
    }
    std::cout<<"row: "<<row<<" col: "<<col<<std::endl;

}

HumanPlayer* HumanPlayer::clone() {
	HumanPlayer *result = new HumanPlayer(symbol);
	return result;
}
