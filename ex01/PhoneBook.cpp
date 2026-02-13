#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::MenuRun()
{
	MenuDisplay();

	while (1)
	{
		std::string	input;
		std::getline(std::cin, input);
		if (input.compare(ADD) == 0)
			ContactAdd();
/*		if (input.compare(SEARCH) == 0)
*/		else if (input.compare(EXIT) == 0)
			break;
		else
			std::cout << CMD_ERROR << std::endl;

	}

}

void	PhoneBook::MenuDisplay()
{
	std::cout << MENU_DISPLAY;
}

void	PhoneBook::ContactAdd()
{
	if (index_current_ % 8 == 0)
		index_current_ = 0;
	contact[index_current_].InfoSet();	
	index_current_++;
}
