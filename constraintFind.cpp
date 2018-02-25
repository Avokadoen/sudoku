#include "constraintFind.hpp"
#include <array>

std::vector<int> constraintFind::getConstrHorizontal
(std::vector<std::vector<int>> board, int x, int y)
{
	auto line = board.begin()+y;

	std::vector<int> rtrConstraint;
	for(auto i : *line){
		if(i != 0){
			rtrConstraint.push_back(i);
		}
	}

	return rtrConstraint;
}

std::vector<int> constraintFind::getConstrVertical
(std::vector<std::vector<int>> board, int x, int y)
{
	std::vector<int> rtrConstraint;
	for(auto& i : board){
		if(i[x] != 0){
			rtrConstraint.push_back(i[x]);
		}
	}
	return rtrConstraint;
}

std::vector<int> constraintFind::getConstrBox
(std::vector<std::vector<int>> board, int x, int y)
{
	std::vector<int> rtrConstraint;
	int indexX = (x/3)*3;
	int indexY = (y/3)*3;
	for(auto i = board.begin()+indexY; i < board.begin()+indexY + 3; i++){
		for(auto j = i->begin()+indexX; j < i->begin()+indexX+3; j++){
			if(*j != 0){
				rtrConstraint.push_back(*j);
			}
		}
	}
	return rtrConstraint;

}

/*std::vector<int> constraintFind::getConstrPredict
(std::vector<std::vector<int>> board, int x, int y)
{
	//std::vector<int> available = getConstrBox()
}

std::vector<int> constraintFind::getConstrAll
(std::vector<std::vector<int>> board, int x, int y)
{

}*/
