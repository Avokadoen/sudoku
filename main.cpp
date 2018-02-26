#include "board.hpp"
#include <array>
#include <iostream>
int main(){
	Board board;
	std::vector<std::vector<int>> tiles;
	tiles = board.makeExampleBoard();
//	std::array <int, 3> kek = board.getBestStep(0, 0);
//	std::cout << kek[0];
	board.solveBoard(tiles);

	tiles = board.generateBoard();

	board.solveBoard(tiles);
}
