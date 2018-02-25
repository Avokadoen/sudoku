#pragma once

#include <array>
#include <vector>

class constraintFind{
public:
	static std::vector<int> getConstrHorizontal	(std::vector<std::vector<int>> board, int x, int y);
	static std::vector<int> getConstrVertical	(std::vector<std::vector<int>> board, int x, int y);
	static std::vector<int> getConstrBox		(std::vector<std::vector<int>> board, int x, int y);
	//static std::vector<int> getConstrPredict	(std::vector<std::vector<int>> board, int x, int y);
	//static std::vector<int> getConstrAll 		(std::vector<std::vector<int>> board, int x, int y);
};
