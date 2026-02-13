//contactSearch -->
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
		PromptDisplay();
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

void	PhoneBook::PromptDisplay()
{
	std::cout << std::endl;
	std::cout << std::setw(15);
	std::cout << CMD_PROMPT << " : ";
}

void	PhoneBook::ContactAdd()
{
	if (index_current_ % 8 == 0)
		index_current_ = 0;
	contact[index_current_].InfoSet();	
	std::cout << "\n" << ADD_SUCCESS << std::endl;
	index_current_++;
}
