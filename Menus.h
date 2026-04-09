#ifndef TRACKING_MAIN_MENUS_H_
#define TRACKING_MAIN_MENUS_H_

#include <string>

class Menu {
	public:
		//default constructor
		Menu();

		void option1();
		//void option2();
		//void option3();
		//void option4();
		void menuDisplay();

	private:
		int m_selection; //might not need. placeholder
		std::string m_item;
		int m_amount;

};

#endif //TRACKING_MAIN_MENUS_H_
