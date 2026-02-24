#include "PhoneBook.hpp"

static int			phonebook_is_empty(int index);
static void		 	phonebook_empty_message_display();
static int	index_is_valid(std::string input, int index_current, int full);
static void			contact_all_display(Contact contact[], int index, int full);
static std::string	index_ask();

/**
 * Searches and displays contacts from the phonebook.
 * 
 * Algorithm:
 * 1. Verify phonebook is not empty
 * 2. Display all contacts in tabular format
 * 3. Prompt user to select a contact by index
 * 4. Validate input and display full contact details
 * 5. If invalid input, recursively call itself for retry
 * 
 * Input validation:
 * - Must be a digit
 * - Must be less than 8 (array size)
 * - Must be within valid range (< index_current_ or full flag set)
 */
void	PhoneBook::ContactSearch()
{
	// Check if phonebook contains any contacts
	if (!phonebook_is_empty(index_current_))
		return (phonebook_empty_message_display());

	// Display all contacts in table format
	contact_all_display(contact, index_current_, full_);

	// Prompt user for contact index
	std::string	input = index_ask();
	int index = input[0] - '0';
	
	// Validate index: must be digit, within bounds, and point to existing contact
	if (index_is_valid(input, index_current_, full_))
		contact[index].DisplayIndex();
	else
	{
		std::cout << SELECT_ERROR << std::endl;
		ContactSearch();  // Recursive retry on invalid input
	}
}

/**
 * Checks if the phonebook is empty.
 * 
 * @param index Current contact count
 * @return 1 if phonebook has contacts, 0 if empty
 */
static int	phonebook_is_empty(int index)
{
	if (index)
		return (1);
	return (0);
}

/**
 * Displays empty phonebook message.
 * Notifies the user that no contacts are available.
 */
static void phonebook_empty_message_display()
{
	std::cout << EMPTY << std::endl;
}

/**
 * Displays all contacts in tabular search format.
 * 
 * @param contact Array of Contact objects
 * @param index Current number of contacts
 * @param full Flag indicating if phonebook has been filled once
 */
static void	contact_all_display(Contact contact[], int index, int full)
{
	// If phonebook is full, display all 8 slots
	if (full)
		index = 8;
	
	// Iterate and display each contact with its index
	for (int i = 0; i < index; i++)
	{
		std::cout << i << " ";
		contact[i].DisplaySearch();
	}
}

/**
 * Validates if the user input is a valid contact index.
 * 
 * @param input User input string
 * @param index_current Current number of contacts in phonebook
 * @param full Flag indicating if phonebook has been filled once
 * @return 1 if valid, 0 if invalid
 */
static int	index_is_valid(std::string input, int index_current, int full)
{
	// Verify input is a single character
	if (input.length() != 1)
		return (0);
	
	// Verify it's a digit between 0 and 7
	if (input[0] < '0' || input[0] > '7')
		return (0);
	
	int index = input[0] - '0';
	
	// If phonebook not full, verify index points to existing contact
	if (!full && index >= index_current)
		return (0);
	
	return (1);
}

/**
 * Prompts user to enter a contact index.
 * 
 * @return User input as string
 * 
 * Algorithm:
 * - Display formatted prompt with padding
 * - Read entire line of user input
 * - If EOF reached (Ctrl+D), program is exited
 * - Return raw input for validation by caller
 */
static std::string	index_ask()
{
	std::string	answer;

	std::cout << std::endl;
	std::cout << std::setw(PADDING);
	std::cout << SELECT_PROMPT << PROMPT_END;

	std::getline(std::cin, answer);
	if (std::cin.eof())
	{
		std::cout << "\n" << EOF_MESSAGE << std::endl;
		std::exit(0);
	}

	return (answer);
}
