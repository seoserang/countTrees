#include <iostream>
#include <fstream>
#include <string>
#include <map>

int calculateNumOfTrees(std::string sequences[], int numRows, int width, int right, int down);

int main()
{
	std::string sequences[500];
	int count = 0;
	int numRows = 0;
	int numOfTrees = 0;
	int countOfRights = 0;

	int numOfTrees11 = 0, numOfTrees51 = 0, numOfTrees71 = 0, numOfTrees12 = 0;

	std::ifstream inputFile;

	//open file
	inputFile.open("advent2020103.txt");

	if (!inputFile)
	{
		std::cout << "Error finding input file." << std::endl;
		system("pause");
		exit(-1);
	}

	//store txt into array
	while (!inputFile.eof())
	{
		inputFile >> sequences[count];
		count++;
	}

	numRows = count;
	int width = sequences[0].length();

	unsigned int combined;
	combined = calculateNumOfTrees(sequences, numRows, width, 1, 1) *
		calculateNumOfTrees(sequences, numRows, width, 3, 1) *
		calculateNumOfTrees(sequences, numRows, width, 5, 1) *
		calculateNumOfTrees(sequences, numRows, width, 7, 1) *
		calculateNumOfTrees(sequences, numRows, width, 1, 2);

	std::cout<<"The number of trees for 3 right and 1 down is: " << calculateNumOfTrees(sequences, numRows, width, 3, 1) << std::endl;
	std::cout << "The number of trees multiplied from slopes -1/1, -1/3, -1/5, -1/7, -2/1 are: " <<
		combined
	<< std::endl;

	return 0;
}

int calculateNumOfTrees(std::string sequences[], int numRows, int width, int right, int down)
{
	double numOfTrees = 0;
	int countOfRights = right;
	int rows = down;

	while (rows < numRows)
	{
		if (sequences[rows][countOfRights % width] == '#')
		{
			numOfTrees++;
		}
		//std::cout << i + 1 << " " << countOfRights % width << std::endl;

		countOfRights += right;

		rows += down;
	}

	return numOfTrees;
}