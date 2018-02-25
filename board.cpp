#include "board.hpp"
#include <iostream>
#include <algorithm>

/*

Starting Sudoku:
0  1  2   3  4  5   6  7  8 pos
0, 0, 0 | 8, 9, 0 | 0, 6, 0 0
3, 6, 5 | 0, 0, 2 | 0, 7, 0 1
2, 9, 0 | 0, 0, 0 | 0, 0, 0 2

0, 8, 4 | 5, 0, 0 | 0, 3, 6 3
0, 0, 1 | 3, 7, 9 | 4, 0, 0 4
9, 5, 0 | 0, 0, 4 | 2, 1, 0 5

0, 0, 0 | 0, 0, 0 | 0, 9, 1 6
0, 4, 0 | 1, 0, 0 | 6, 2, 5 7
0, 3, 0 | 0, 5, 6 | 0, 0, 0 8


Solution:

4, 1, 7 | 8, 9, 3 | 5, 6, 2
3, 6, 5 | 4, 1, 2 | 8, 7, 9
2, 9, 8 | 7, 6, 5 | 1, 4, 3

7, 8, 4 | 5, 2, 1 | 9, 3, 6
6, 2, 1 | 3, 7, 9 | 4, 5, 8
9, 5, 3 | 6, 8, 4 | 2, 1, 7

5, 7, 6 | 2, 4, 8 | 3, 9, 1
8, 4, 9 | 1, 3, 7 | 6, 2, 5
1, 3, 2 | 9, 5, 6 | 7, 8, 4

*/


Board::Board(){

	board.resize(9);
	for(auto& i : board){
		i.resize(9);
		std::fill(i.begin(), i.end(), 0);
	}

	board[0][3] = 8;
	board[0][4] = 9;
	board[0][7] = 6;
	board[1][0] = 3;
	board[1][1] = 6;
	board[1][2] = 5;
	board[1][5] = 2;
	board[1][7] = 7;
	board[2][0] = 2;
	board[2][1] = 9;
	board[3][1] = 8;
	board[3][2] = 4;
	board[3][3] = 5;
	board[3][7] = 3;
	board[3][8] = 6;
	board[4][2] = 1;
	board[4][3] = 3;
	board[4][4] = 7;
	board[4][5] = 9;
	board[4][6] = 4;
	board[5][0] = 9;
	board[5][1] = 5;
	board[5][5] = 4;
	board[5][6] = 2;
	board[5][7] = 1;
	board[6][7] = 9;
	board[6][8] = 1;
	board[7][1] = 4;
	board[7][3] = 1;
	board[7][6] = 6;
	board[7][7] = 2;
	board[7][8] = 5;
	board[8][1] = 3;
	board[8][4] = 5;
	board[8][5] = 6;

	//printBoard();
}

void Board::printBoard(){
	std::cout << std::endl;
	int countX;
	int countY = 1;
	for(auto& i : board){
		countX = 1;
		for(auto j : i){
			std::cout << j << " ";
			if(countX % 3 == 0){
				std::cout << " ";
			}
			countX++;
		}
		std::cout << std::endl;
		if(countY % 3 == 0){
			std::cout << std::endl;
		}
		countY++;
	}
}

bool Board::solveBoard(){
	bool solved = false;

	printBoard();
	while (!solved){
		std::vector<std::vector<int>> prevBoard = board;;
		// look each box
		int yPos = 0;
		while(yPos <= 6){
			int xPos = 0;
			while(xPos <= 6){

				std::array<int,3> bestStep = getBestStep(xPos, yPos);
				// if we found an answer, save to board
				if(bestStep[0] > 0){
					board[bestStep[2]][bestStep[1]] = bestStep[0];
				}
				xPos += 3;
			}
			yPos += 3;
		}

		// check if board is out of zero, if true then function is done
		solved = true;
		for(auto i : board){
			if(std::find(i.begin(), i.end(), 0) != i.end()){
				solved = false;
			}
		}
		if(prevBoard == board) return false;
	}
	printBoard();
	return true;
}

std::array<int, 3> Board::getBestStep(int x, int y){

	std::vector<int> availableSteps;
	std::array<int, 9> score;

	// check box for traken values
	auto takenSteps = finder.getConstrBox(board, x, y);

	// go through all valid value ({1..9})
	for(auto i : X){
		bool taken = false;
		for(auto j : takenSteps){
			if(i == j) taken = true;
		}
		if(taken == false){
			// save values that are not taken
			availableSteps.push_back(i);
		}
	}

	// convert param to left upper corner coordinate of box
	int indexX = (x/3)*3;
	int indexY = (y/3)*3;
	int yCount = indexY;

	// initialize values to compare later
	std::array<std::array<int, 3>, 10> rtrArray;
	std::fill(score.begin(), score.end(), 0);

	// create default return value
	std::fill(rtrArray[9].begin(), rtrArray[9].end(), -1);
	for(auto i = board.begin()+indexY; i < board.begin()+indexY + 3; i++){
		int xCount = indexX;

		// loop inside box dimension
		for(auto j = i->begin()+indexX; j < i->begin()+indexX + 3; j++){
			// if tile is empty
			if(*j == 0){
				auto horiz = finder.getConstrHorizontal(board, xCount, yCount);
				auto vert = finder.getConstrVertical(board, xCount, yCount);

				for(auto& k : availableSteps){
					// if value is taken
					if(std::find(horiz.begin(), horiz.end(), k) != horiz.end()){

					}
					else if(std::find(vert.begin(), vert.end(), k) != vert.end()){

					}
					// if value is not taken
					else{
						score[k-1]++;
						if(score[k-1] == 1){
							rtrArray[k-1] = {
								k, xCount, yCount
							};
						}
					}
				}

			}

			xCount++;
		}
		yCount++;
	}
	// return array with least score
	for(int i = 0; i < 9; i++){
		if(score[i] == 1){
			return rtrArray[i];
		}
	}
	// return invalid array
	return rtrArray[9];
}
