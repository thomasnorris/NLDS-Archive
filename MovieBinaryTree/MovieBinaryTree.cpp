// MovieBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"
#include "MovieBinaryTree.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const string INPUT_FILE_NAME = "movies.txt";
const string OUTPUT_FILE_NAME = INPUT_FILE_NAME;
const string LIST_COMMAND = "L";
const string INSERT_COMMAND = "I";
const string SEARCH_COMMAND = "S";
const string DELETE_COMMAND = "D";
const string QUIT_COMMAND = "Q";

BSTree* _tree;

int main()
{
	LoadFile();
	
	_tree->ListInOrder();

	_tree->SearchAndPrintMatch("Up", 2009);
	_tree->SearchAndPrintMatch("Schindler's List", 1993);
	_tree->Delete("It", 2017);
	_tree->Delete("Inside Out", 2014);

	_tree->ListInOrder();

	system("pause");

    return 0;
}

void LoadFile()
{
	_tree = new BSTree();
	ifstream inputFile;
	inputFile.open(INPUT_FILE_NAME);

	if (!inputFile.good())
		DisplayFileError(INPUT_FILE_NAME);

	string line;
	while (getline(inputFile, line))
	{
		auto movie = new BSTree::MovieNode();
		movie->SetTitle(line);
		getline(inputFile, line);
		movie->SetRating(line);
		getline(inputFile, line);
		movie->SetUrl(line);
		getline(inputFile, line);
		movie->SetYear(stoi(line));
		getline(inputFile, line);
		movie->SetYear(stoi(line));

		_tree->Insert(movie);
	}

	cout << "The file \"" << INPUT_FILE_NAME << "\" has loaded successfully." << endl << endl;
}

void DisplayFileError(string fileName)
{
	cout << "There was an issue opening the file \"" << fileName << "\". Please check the file and try again." << endl << endl;
	system("pause");
	_Exit(0);
}
