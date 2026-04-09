#include <iostream>
#include <iomanip>
#include <string>
#include "Menus.h"
using namespace std;

int main() {
	Menu groceries;
	int selection = 0;

	cin >> selection;

	while ((selection >= 1) && (selection <= 4)) {
		cout << "working. . ." << endl;

		while (selection == 1) {
			groceries.option1();
			cout << "Make a new selection: ";
			cin >> selection;
		}

		while (selection == 2) {
			cout << "List placeholder" << endl;
			break;
		}

		while (selection == 3) {
			cout << "Histogram placeholder" << endl;
			break;
		}

		while (selection == 4) {
			cout << "Ending program. . ." << endl;
			break;
		}
	}

	return 0;
}
