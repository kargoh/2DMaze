#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int getNthValue(list<list<int>>, int, int);

int main()
{
	list<list<int>> twoDimensionalArray;
	twoDimensionalArray = {
		{2,1,0,0,0},
		{0,0,0,1,0},
		{1,1,1,1,0},
		{1,0,0,0,0},
		{1,3,1,1,1}
	};
	string mapString = "";
	const int rows = 5;
	const int cols = 5;
	const int tileSize = 3;
	int type;
	
	for (int row = 0; row < rows; row++) { // to iterate through the rows of the maze
		for (int a = 0; a < tileSize; a++) { // to create the 3x3 tilesize
			for (int col = 0; col < cols; col++) { // to iterate throught the columns of the maze
				for (int b = 0; b < tileSize; b++) { // to create the 3x3 tilesize
					type = getNthValue(twoDimensionalArray, row, col); // set type to equal the value of index
					if (type == 0) { // create path
						mapString += ".";
					}
					else if (type == 2) { // start
						if (a == 1 && b == 1) mapString += "S"; // center point
						else mapString += ".";
					}
					else if (type == 3) { // finish
						if (a == 1 && b == 1) mapString += "F"; // center point
						else mapString += ".";
					}
					else { // create walls
						mapString += "x";
					}
				}
			}
			mapString += "\n"; // create line break
		}
	}
	cout << mapString;
}

int getNthValue(list<list<int>> _list, int _r, int _c) {
	// declare variables
	int rowIndex = 0;
	int colIndex = 0;
	int value = 0;

	// loop through row list (of lists)
	for (auto rowValue : _list) {
		if (_r == rowIndex) {

			// loop through col list (of ints)
			for (auto colValue : rowValue) {
				if (_c == colIndex) {
					value = colValue;
					break;
				}
				colIndex++;
			}
			break;
		}
		rowIndex++;
	}
	return value;
}

