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
		else if (input.compare(SEARCH) == 0)
			ContactSearch();
//			Contact::DisplaySearch();
		else if (input.compare(EXIT) == 0)
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
	std::cout << std::setw(PADDING);
	std::cout << CMD_PROMPT << PROMPT_END;
}

void	PhoneBook::ContactAdd()
{
	if (index_current_ % 8 == 0)
		index_current_ = 0;
	contact[index_current_].InfoSet();	
	std::cout << "\n" << ADD_SUCCESS << std::endl;
	index_current_++;
}

void	PhoneBook::ContactSearch()
{
	ContactAllDisplay();
	std::cout << std::endl;
	std::cout << std::setw(PADDING);
	std::cout << SELECT_PROMPT << PROMPT_END;
	std::string	input;
	std::getline(std::cin, input);
	int index = input[0] - '0';
	if (isdigit(input[0]) && index < 8 && index < index_current_)
		contact[index].DisplayIndex();
	else
		std::cout << SELECT_ERROR << std::endl;
}

void	PhoneBook::ContactAllDisplay()
{
	for (int i = 0; i < index_current_; i++)
	{
		std::cout << i << " ";
		contact[i].DisplaySearch();
	}
}

