

#pragma once

#include <array>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <memory>
#include "constraintFind.hpp"

class Board{
private:
	const std::vector<int> X = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	constraintFind finder;

public:
	Board();

	std::vector<std::vector<int>> makeExampleBoard();
	// print the whole board
	void printBoard(std::vector<std::vector<int>>& board);

	/* solves current broad
	@return: true if it can solve, false otherwise
	*/
	bool solveBoard(std::vector<std::vector<int>> board);

	/*
	@param: coords for box to look in
	@return: an array where 0 = value | 1 = x | 2 = y.
			 {-1, -1, -1} if invalid
	*/
	std::array<int, 3> getBestStep(std::vector<std::vector<int>>& board, int x, int y);

	// change board vector to another valid random board
	std::vector<std::vector<int>> generateBoard();

	// create completely random board (might be invalid)
	std::vector<std::vector<int>> createRandomBoard();
};
