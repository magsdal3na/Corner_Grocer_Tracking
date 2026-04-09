#include <iostream>
#include <iomanip>
#include <string>
#include "Menus.h"
using namespace std;

Menu::Menu() {
	m_selection = 0;
	m_item = 0; //needs to be a string later
	m_amount = 0;
}

//prompt user for input
void Menu::option1() {
	cout << "Input the item name: ";
	cin >> m_item;
	cout << endl;
	cout << "Input the item's amount: ";
	cin >> m_amount;
	cout << m_item << " " << m_amount << endl;
}
