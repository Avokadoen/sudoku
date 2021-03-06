#pragma once

#include <array>
#include <vector>

/*class to establish constraints
@param: any board in form of 2d vector and coordinates
@return: collection of invalid values for coordinates
*/
class constraintFind{
public:
	static std::vector<int> getConstrHorizontal	(std::vector<std::vector<int>> board, int x, int y);
	static std::vector<int> getConstrVertical	(std::vector<std::vector<int>> board, int x, int y);
	static std::vector<int> getConstrBox		(std::vector<std::vector<int>> board, int x, int y);
};
