#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// declare global functions
list<int> getCoordinatesByType(int);
int getNthValueFromMap(list<list<int>>, int, int);
int getNthValueFromList(list<int>, int);
list<list<int>> setNthValueFromMap(list<list<int>>, int, int, int);
void printMap();
bool checkPath(int, int, int);

// declare global variables
list<list<int>> twoDimensionalArray = {
	{2,1,0,0,0},
	{0,0,0,1,0},
	{1,1,1,1,0},
	{1,0,0,0,0},
	{1,3,1,1,1}
};
list<int> startPos;
string mapString = "";
const int rows = 5;
const int cols = 5;
const int tileSize = 3;

int main()
{
	printMap();
	startPos = getCoordinatesByType(2); // 2 == start
	checkPath(0, getNthValueFromList(startPos, 0), getNthValueFromList(startPos, 1)); // start checking type "0", row = 0, col = 0;
}



bool checkPath(int checkType, int row, int col) {
	int type = -1;
	/*
	cout << getNthValueFromMap(twoDimensionalArray, row - 1, col) << "\n";
	cout << getNthValueFromMap(twoDimensionalArray, row, col + 1) << "\n";
	cout << getNthValueFromMap(twoDimensionalArray, row + 1, col) << "\n";
	cout << getNthValueFromMap(twoDimensionalArray, row, col - 1) << "\n";
	*/
	type = getNthValueFromMap(twoDimensionalArray, row + 1, col);
	if (type == 0) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (type == checkType) {
					twoDimensionalArray = setNthValueFromMap(twoDimensionalArray, 4, row, col);
					break;
				}
			}
		}
	}
	return false;
}

list<list<int>> setNthValueFromMap(list<list<int>> list, int type, int row, int col) {
	// declare variables
	int rowIndex = 0;
	int colIndex = 0;
	int value = -1;

	// loop through row list (of lists)
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		for (auto rowValue : list) {
			if (row == rowIndex) {
				rowValue.assign(col, type);
				break;
			}
			rowIndex++;
		}
	}
	return list;
}

int getNthValueFromMap(list<list<int>> list, int row, int col) {
	// declare variables
	int rowIndex = 0;
	int colIndex = 0;
	int value = -1;

	// loop through row list (of lists)
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		for (auto rowValue : list) {
			if (row == rowIndex) {

				// loop through col list (of ints)
				for (auto colValue : rowValue) {
					if (col == colIndex) {
						value = colValue;
						break;
					}
					colIndex++;
				}
				break;
			}
			rowIndex++;
		}
	}
	return value;
}



int getNthValueFromList(list<int> list, int _i) {
	// declare variables
	int index = 0;
	int colIndex = 0;
	int value = 0;

	// loop through row list (of lists)
	for (auto indexValue : list) {
		if (_i == index) {
			value = indexValue;
			break;
		}
		index++;
	}
	return value;
}

void printMap() {
	int type = -1;
	for (int row = 0; row < rows; row++) { // to iterate through the rows of the maze
		for (int a = 0; a < tileSize; a++) { // to create the 3x3 tilesize
			for (int col = 0; col < cols; col++) { // to iterate throught the columns of the maze
				for (int b = 0; b < tileSize; b++) { // to create the 3x3 tilesize
					type = getNthValueFromMap(twoDimensionalArray, row, col); // set type to equal the value of index
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

list<int> getCoordinatesByType(int coordinatesType) {
	int type = -1;
	int rowIndex = -1;
	int colIndex = -1;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			type = getNthValueFromMap(twoDimensionalArray, row, col);
			if (type == coordinatesType) {
				colIndex = col;
				rowIndex = row;
				break;
			}
		}
		if (colIndex >= 0 || rowIndex >= 0) {
			break;
		}
	}
	list<int> coordinates = { colIndex, rowIndex };
	return coordinates;
}

