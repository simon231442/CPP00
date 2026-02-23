#include "PhoneBook.hpp"

static int			phonebook_is_empty(int index);
static void		 	phonebook_empty_message_display();
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
	if (isdigit(input[0]) && index < 8 && (index < index_current_ || full_))
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
 * 
 * Algorithm:
 * - If phonebook is full, display all 8 contacts
 * - Otherwise, display only contacts up to current index
 * - Each contact is prefixed with its index number
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
 * Prompts user to enter a contact index.
 * 
 * @return User input as string
 * 
 * Algorithm:
 * - Display formatted prompt with padding
 * - Read entire line of user input
 * - Return raw input for validation by caller
 */
static std::string	index_ask()
{
	std::string	answer;

	std::cout << std::endl;
	std::cout << std::setw(PADDING);
	std::cout << SELECT_PROMPT << PROMPT_END;

	std::getline(std::cin, answer);

	return (answer);
}
