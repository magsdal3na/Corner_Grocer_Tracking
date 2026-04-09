#include <iostream>
#include <iomanip>
#include "Menus.h"
using namespace std;

int main() {
	int selection = 0;

	cin >> selection;

	while ((selection >= 1) && (selection <= 4)) {
		cout << "working" << endl;
		break;
	}

	return 0;
}
