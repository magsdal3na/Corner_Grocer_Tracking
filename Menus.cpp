#include <iostream>
#include <iomanip>
#include <string>
#include "Menus.h"
using namespace std;

Menu::Menu() {
	m_selection = 0;
	m_item = "";
	m_amount = 0;
}

//prompt user for input
void Menu::option1() {
	cout << "Input the item name: ";
	cin >> m_item;
	cout << "Input the item's amount: ";
	cin >> m_amount;
	cout << m_item << " " << m_amount << endl;
}

void Menu::menuDisplay() {
	cout << setfill('-') << setw(40) << " " << endl;
	cout << setfill(' ') << setw(20) << "   Welcome to the   " << setw(20) << endl;
	cout << setw(20) << "   Corner Grocer Tracking Program!   " << setw(20) << endl;
	cout << setfill('-') << setw(40) << " " << endl;
	cout << setfill(' ') << setw(20) << "Please select from one of these options: " << setw(20) << endl;
}
