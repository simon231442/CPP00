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
		get_line(std::cout, input);
		if (input.compare(ADD) == 0)
			ContactAdd();
		if (input.compare(SEARCH) == 0)

	}

}

void	PhoneBook::MenduDisplay()
{
	std::cout << MENU_DISPLAY;
}
