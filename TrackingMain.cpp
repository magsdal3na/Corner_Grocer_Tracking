#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //for inputting and outputting files
#include "Menus.h"
using namespace std;

int main() {
	Menu groceries; //sets up constructor
	int selection = 0;

	//creates backup file on startup
	groceries.backupFileCreation();

	//displays menu
	groceries.menuDisplay();

	cout << "Please select 1 - 4: ";
	cin >> selection;

	//iterates while input is a number within 1 - 4
	while ((selection >= 1) && (selection <= 4)) {

		while (selection == 1) {
			groceries.option1();
			cout << "Please select 1 - 4: ";
			cin >> selection;
		}

		while (selection == 2) {
			groceries.option2();
			cout << "Please select 1 - 4: ";
			cin >> selection;
		}

		while (selection == 3) {
			groceries.option3();
			cout << "Please select 1 - 4: ";
			cin >> selection;
		}

		while (selection == 4) {
			cout << "Ending program. . ." << endl;
			return 0;
		}
	}

	//prints if user enters incorrect value
	//exits program
	cout << "Incorrect value entered. Please restart program." << endl;

	return 0;
}
