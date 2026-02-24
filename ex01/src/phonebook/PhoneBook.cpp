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

/**
 * Runs the main phonebook menu loop.
 * 
 * Algorithm:
 * 1. Display initial menu with available commands
 * 2. Enter infinite loop for command processing:
 *    - Display prompt and wait for user input
 *    - Parse command (ADD, SEARCH, EXIT)
 *    - Execute corresponding function
 *    - Display error for invalid commands
 * 3. Exit loop when EXIT command is received
 * 
 * Handles EOF (Ctrl+D) by displaying message and exiting program.
 */
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

/**
 * Displays the main menu with available commands.
 * Shows welcome message and command options to the user.
 */
static void	menu_display()
{
	std::cout << MENU_DISPLAY;
}

/**
 * Displays the command prompt.
 * Outputs formatted prompt with padding, waiting for user input.
 */
static void	prompt_display()
{
	std::cout << std::endl;
	std::cout << std::setw(PADDING);
	std::cout << CMD_PROMPT << PROMPT_END;
}
