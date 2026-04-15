#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //for inputting file
#include "Menus.h"
using namespace std;

int main() {
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
			groceries.option2();
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

	return 0;
}
