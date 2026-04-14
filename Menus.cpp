#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm> //to use transform
#include <cctype> //to use tolower
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

	cout << m_inputItem << " " << m_itemFrequency << endl;

	inFS.close();

	return 0;
}

void Menu::menuDisplay() {
	cout << setfill('-') << setw(40) << " " << endl;
	cout << setfill(' ') << setw(20) << "   Welcome to the   " << setw(20) << endl;
	cout << setw(20) << "   Corner Grocer Tracking Program!   " << setw(20) << endl;
	cout << setfill('-') << setw(40) << " " << endl;
	cout << setfill(' ') << setw(20) << "Please select from one of these options: " << setw(20) << endl;
}

int Menu::inputList() {
	ifstream inFS;
	string m_inputItem;
	int m_itemFrequency;
	string m_item;

	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
		return 1;
	}

	cout << "Printing item list. . ." << endl;

	while (!inFS.eof()) {
		inFS >> m_item;

		if (!inFS.fail()) {
			cout << m_item << endl;
		}
	}

	inFS.close();

	return 0;
}
