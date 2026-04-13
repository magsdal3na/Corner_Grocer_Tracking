#ifndef TRACKING_MAIN_MENUS_H_
#define TRACKING_MAIN_MENUS_H_

#include <string>

class Menu {
	public:
		//default constructor
		Menu();

		int option1();
		//void option2();
		//void option3();
		//void option4();
		void menuDisplay();
		int inputList();

	private:
		int m_selection; //might not need. placeholder
		std::string m_inputItem;
		int m_amount;
		std::string m_item;
		int m_itemFrequency;

};

#endif //TRACKING_MAIN_MENUS_H_
