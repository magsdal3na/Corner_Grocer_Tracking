#ifndef TRACKING_MAIN_MENUS_H_
#define TRACKING_MAIN_MENUS_H_

#include <string>

class Menu {
	public:
		//default constructor
		Menu();

		int option1();
		int option2();
		int option3();
		void menuDisplay();

	private:
		int m_selection; //might not need. placeholder
		std::string m_inputItem;
		int m_amount;
		std::string m_item;
		int m_itemFrequency;
		std::string m_starOutput;

};

#endif //TRACKING_MAIN_MENUS_H_
