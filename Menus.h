#ifndef TRACKING_MAIN_MENUS_H_
#define TRACKING_MAIN_MENUS_H_

#include <string>
using namespace std;

class Menu {
	public:
		//default constructor
		Menu();

		int option1();
		int option2();
		int option3();
		int backupFileCreation();
		void menuDisplay();

	private:
		string m_inputItem;
		int m_amount;
		string m_item;
		int m_itemFrequency;
		string m_starOutput;

};

#endif //TRACKING_MAIN_MENUS_H_
