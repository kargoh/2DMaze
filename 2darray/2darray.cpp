#include <iostream>
using namespace std;

int main()
{	
	
	const int rows = 5;
	const int cols = 5;
	const int tileSize = 3;
	string mapString = "";
	int type;
	int twoDimensionalArray[rows][cols] = { 
		{2,1,0,0,0}, 
		{0,0,0,1,0},
		{1,1,1,1,0},
		{1,0,0,0,0},
		{1,3,1,1,1}
	};
	
	for (int row = 0; row < rows; row++) { // to iterate through the rows of the maze
		for (int a = 0; a < tileSize; a++) { // to create the 3x3 tilesize
			for (int col = 0; col < cols; col++) { // to iterate throught the columns of the maze
				for (int b = 0; b < tileSize; b++) { // to create the 3x3 tilesize
					type = twoDimensionalArray[row][col]; // set type to equal the value of index
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

	
	/*
	const int rows = 5;
	const int cols = 5;
	const int tileSize = 3;
	string mapString = "";
	int type;
	int twoDimensionalArray[rows][cols] = { 
		{2,1,0,0,0}, 
		{0,0,0,1,0},
		{1,1,1,1,0},
		{1,0,0,0,0},
		{1,3,1,1,1}
	};

	for (int row = 0; row < rows; row++) { // to iterate through the rows of the maze
		for (int a = 0; a < tileSize; a++) { // to create the 3x3 tilesize
			for (int col = 0; col < cols; col++) { // to iterate throught the columns of the maze
				for (int b = 0; b < tileSize; b++) { // to create the 3x3 tilesize
					type = twoDimensionalArray[row][col]; // set type to equal the value of index
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
	*/
}
