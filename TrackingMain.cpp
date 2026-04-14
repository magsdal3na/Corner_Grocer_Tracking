#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //for inputting file
#include "Menus.h"
using namespace std;

int main() {
	//setting up input file stream and error catching
	//ifstream inFS; //input file stream
	//string item; //item from file

	//inFS.open("CS210_Project_Three_Input_File.txt");
	//if (!inFS.is_open()) {
	//	cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
	//	return 1; //indicates error
	//}

	//inFS >> item;
	//while (!inFS.fail()) {
	//	inFS >> item;
	//}
	//if (!inFS.eof()) {
	//	cout << "Input failture before reaching end of file." << endl;
	//}

	Menu groceries;
	int selection = 0;

	groceries.menuDisplay();

	cout << "Please select 1 - 4: ";
	cin >> selection;

	while ((selection >= 1) && (selection <= 4)) {

		while (selection == 1) {
			groceries.option1();
			cout << "Make a new selection: ";
			cin >> selection;
		}

		while (selection == 2) {
			//groceries.inputList();
			cout << "Make a new selection: ";
			cin >> selection;
		}

		while (selection == 3) {
			groceries.option3();
			cout << "Make a new selection: ";
			cin >> selection;
		}

		while (selection == 4) {
			cout << "Ending program. . ." << endl;
			return 0;
		}
	}

	//inFS.close();

	return 0;
}
