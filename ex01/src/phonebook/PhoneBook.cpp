//contactSearch --> empty case
//index ask
#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	index_current_ = 0;
	full_ = 0;
}

PhoneBook::~PhoneBook()
{
}


static void	menu_display();
static void	prompt_display();

void	PhoneBook::MenuRun()
{
	menu_display();
	while (1)
	{
		prompt_display();
		std::string	input;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\n" << EOF_MESSAGE << std::endl;
			std::exit(0);
		}
		if (input.compare(ADD) == 0)
			ContactAdd();
		else if (input.compare(SEARCH) == 0)
			ContactSearch();
		else if (input.compare(EXIT) == 0)
			break;
		else
			std::cout << CMD_ERROR << std::endl;
	}
}

static void	menu_display()
{
	std::cout << MENU_DISPLAY;
}

static void	prompt_display()
{
	std::cout << std::endl;
	std::cout << std::setw(PADDING);
	std::cout << CMD_PROMPT << PROMPT_END;
}
/*
void	PhoneBook::ContactAllDisplay()
{
	int	count;
	if (full_)
		count = 8;
	else
		count = index_current_;
	for (int i = 0; i < count; i++)
	{
		std::cout << i << " ";
		contact[i].DisplaySearch();
	}
}
*/
