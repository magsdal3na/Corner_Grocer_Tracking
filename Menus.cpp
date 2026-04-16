#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm> //to use transform
#include <cctype> //to use tolower
#include <map> //to count words in file
#include "Menus.h"
using namespace std;

Menu::Menu() {
	m_selection = 0;
	m_inputItem = "";
	m_amount = 0;
	m_item = "";
	m_itemFrequency = 0;
}

//prompt user for input
int Menu::option1() {
	ifstream inFS;
	string m_inputItem;
	int m_itemFrequency = 0;
	string m_item;

	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
		return 1;
	}

	cout << endl;
	cout << "Enter an item's name: " << endl;
	cin >> m_inputItem;

	while (!inFS.eof()) {
		inFS >> m_item;

		if (!inFS.fail()) {
			string m_itemLower = m_item;
			string m_inputLower = m_inputItem;

			//converting text to lowercase
			transform(m_itemLower.begin(), m_itemLower.end(), m_itemLower.begin(), tolower);
			transform(m_inputLower.begin(), m_inputLower.end(), m_inputLower.begin(), tolower);

			if (m_itemLower == m_inputLower) {
				++m_itemFrequency;
			}
		}
	}

	cout << m_itemFrequency << endl;
	cout << endl;

	inFS.close();

	return 0;
}

//printing frequency with numbers representing frequency
int Menu::option2() {
	ifstream inFS;
	string m_item;
	//map to store words and the count
	map<string, int> m_itemCounts;

	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
		return 1;
	}

	while (!inFS.eof()) {
		inFS >> m_item;

		if (!inFS.fail()) {
			//if item exists, map is updated
			m_itemCounts[m_item]++;
		}
	}

	//iterate through list and print frequencies
	for (auto const& pair : m_itemCounts) {
		cout << pair.first << " " << pair.second << endl;
	}

	inFS.close();

	return 0;
}

//printing frequency using a histogram
int Menu::option3() {
	ifstream inFS;
	string m_item;
	//map to store words and the count
	map<string, int> m_itemCounts;

	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
		return 1;
	}

	while (!inFS.eof()) {
		inFS >> m_item;

		if (!inFS.fail()) {
			//if item exists, map is updated
			m_itemCounts[m_item]++;
		}
	}

	//iterate through list and print frequencies with stars
	for (auto const& pair : m_itemCounts) {
		string m_starOutput(pair.second, '*');
		cout << pair.first << " " << m_starOutput << endl;
	}

	inFS.close();

	return 0;
}

int Menu::backupFileCreation() {
	ifstream inFS;
	ofstream outFS;
	string m_item;
	map<string, int> m_itemCounts;

	inFS.open("CS210_Project_Three_Input_File.txt"); //input file
	outFS.open("frequency.dat"); //output file backup data

	//checking to see if input file can open
	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
		return 1;
	}

	//checking to see if output file can be created
	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat." << endl;
		return 1;
	}

	//inputs data from input file
	while (!inFS.eof()) {
		inFS >> m_item;
		//runs while data input does not fail
		if (!inFS.fail()) {
			//if item exists, map is updated
			m_itemCounts[m_item]++;
		}
	}

	//iterates over all items and values to create frequency list
	for (auto const& pair : m_itemCounts) {
		outFS << pair.first << " " << pair.second << endl;
	}

	//closes both files
	inFS.close();
	outFS.close();

	return 0;
}

void Menu::menuDisplay() {
	cout << setfill('-') << setw(50) << "" << endl;
	cout << setfill(' ') << setw(32) << "   Welcome to the   " << endl;
	cout << setw(41) << "   Corner Grocer Tracking Program!   " << " " << endl;
	cout << setfill('-') << setw(51) << " " << endl;
	cout << setfill(' ') << setw(50) << endl;
	cout << setw(20) << "Please select from one of these options: " << setw(20) << endl;
	cout << "1. Input an item/word to see the frequency." << endl;
	cout << "2. Print full list of items with frequencies." << endl;
	cout << "3. Print full list with frequencies in a histogram." << endl;
	cout << "4. End program." << endl;
	cout << endl;
}

