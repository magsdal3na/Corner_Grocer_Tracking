#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm> //to use transform
#include <cctype> //to use tolower
#include <map> //to count words in file
#include "Menus.h"
using namespace std;

//sets up basic constructor
Menu::Menu() {
	m_amount = 0;
	m_item = "";
}

//prompt user for input and output frequency of item
int Menu::option1() {
	ifstream inFS;
	string inputItem;
	int itemFrequency = 0;
	string m_item;

	try {
		//attempts to open text file
		inFS.open("CS210_Project_Three_Input_File.txt");

		if (!inFS.is_open()) {
			cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
			throw runtime_error("File System Error: Unable to locate or open the input data file.");
		}

		//prompts user for input of item name
		cout << endl;
		cout << "Enter an item's name: " << endl;
		cin >> inputItem;

		//loop iterates until end of input
		while (!inFS.eof()) {
			inFS >> m_item;

			//while the input doesn't fail, convert user and file input to lowercase for comparison
			if (!inFS.fail()) {
				string itemLower = m_item;
				string inputLower = inputItem;

				//converting text to lowercase
				transform(itemLower.begin(), itemLower.end(), itemLower.begin(), tolower);
				transform(inputLower.begin(), inputLower.end(), inputLower.begin(), tolower);

				//increase frequency if input item and list item matches
				if (itemLower == inputLower) {
					++itemFrequency;
				}
			}
		}


		if (itemFrequency > 0) {
			//outputs the item's frequency if item had more than 0 items
			cout << itemFrequency << endl;
			cout << endl;
		}
		else {
			cout << "There is no match for that word." << endl;
			cout << endl;
		}

		inFS.close();
	}
	//catches the runtime error
	catch (const runtime_error& e) {
		cout << "Error: " << e.what() << endl;
		return 1; //signals error to main()
	}

	return 0;
}

//printing full list with numbers representing frequency
int Menu::option2() {
	ifstream inFS;
	string m_item;
	//map to store words and the count
	map<string, int> itemCounts;

	try {
		//attempts to open input file
		inFS.open("CS210_Project_Three_Input_File.txt");

		if (!inFS.is_open()) {
			throw runtime_error("Error: Could not open input file for frequency list output.");
		}

		//iterates until at the end of the input file
		while (!inFS.eof()) {
			inFS >> m_item;

			if (!inFS.fail()) {
				//if item exists, map is updated
				itemCounts[m_item]++;
			}
		}
		cout << endl;
		//iterate through list and print frequencies
		for (auto const& pair : itemCounts) {
			cout << right << setw(15) << pair.first << " " << left << pair.second << endl;
		}

		cout << endl;

		inFS.close();
	}

	catch (const runtime_error& t_e) {
		cout << t_e.what() << endl;
		return 1; //signals failure to main()
	}

	return 0;
}

//printing frequency using a histogram
int Menu::option3() {
	ifstream inFS;
	string m_item;
	//map to store words and the count
	map<string, int> itemCounts;

	try {
		//attempt to open input file
		inFS.open("CS210_Project_Three_Input_File.txt");

		if (!inFS.is_open()) {
			throw runtime_error("Error: Could not open input file for histogram output.");
		}

		//iterates until at the end of the input file
		while (!inFS.eof()) {
			inFS >> m_item;

			if (!inFS.fail()) {
				//if item exists, map is updated
				itemCounts[m_item]++;
			}
		}

		cout << endl;

		//iterate through list and print frequencies with stars
		for (auto const& pair : itemCounts) {
			string starOutput(pair.second, '*');
			cout << right << setw(15) << pair.first << " " << left << starOutput << " " << endl;
		}

		cout << endl;

		inFS.close();
	}

	catch (const runtime_error& t_e) {
		cout << t_e.what() << endl;
		return 1; //signals failure to main()
	}

	return 0;
}

//creates the backup file
int Menu::backupFileCreation() {
	ifstream inFS;
	ofstream outFS;
	string m_item;
	map<string, int> itemCounts;

	try {
		//attempts to open input file and create/open output file
		inFS.open("CS210_Project_Three_Input_File.txt"); //input file
		outFS.open("frequency.dat"); //output file backup data

		//checking to see if input file can open
		if (!inFS.is_open()) {
			throw runtime_error("Error: Unable to open input file for backup.");
		}

		//checking to see if output file can be created
		if (!outFS.is_open()) {
			throw runtime_error("Error: Unable to create frequency.dat backup file.");
		}

		//inputs data from input file
		while (!inFS.eof()) {
			inFS >> m_item;
			//runs while data input does not fail
			if (!inFS.fail()) {
				//if item exists, map is updated
				itemCounts[m_item]++;
			}
		}

		//iterates over all items and values to create frequency list
		for (auto const& pair : itemCounts) {
			outFS << pair.first << " " << pair.second << endl;
		}

		//closes both files
		inFS.close();
		outFS.close();
	}

	catch (const runtime_error& e) {
		cout << e.what() << endl;
		return 1; //signals failure to main()
	}

	return 0;
}

//outputs the menu
void Menu::menuDisplay() {
	cout << setfill('-') << setw(50) << "" << endl;
	cout << setfill(' ') << setw(32) << "   Welcome to the   " << endl;
	cout << setw(42) << "   Corner Grocer Tracking Program!   " << " " << endl;
	cout << setfill('-') << setw(51) << " " << endl;
	cout << setfill(' ') << setw(50) << endl;
	cout << setw(20) << "Please select from one of these options: " << setw(20) << endl;
	cout << "1. Input an item/word to see the frequency." << endl;
	cout << "2. Print full list of items with frequencies." << endl;
	cout << "3. Print full list of frequencies in a histogram." << endl;
	cout << "4. End program." << endl;
	cout << endl;
}

