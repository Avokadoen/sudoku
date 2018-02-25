#pragma once

#include <array>
#include <vector>

#include "constraintFind.hpp"

class Board{
private:
	const std::vector<int> X = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<std::vector<int>> board;
	constraintFind finder;

public:
	Board();
	// print the whole board
	void printBoard();
	// TODO:
	// random problem
	// load from file
	// reset board
	// unit test

	// solves current broad
	void solveBoard();

	/*
	@param: coords for box to look in
	@return: an array where 0 = value | 1 = x | 2 = y.
			{-1, -1, -1} if invalid 
	*/
	std::array<int, 3> getBestStep(int x, int y);
};
