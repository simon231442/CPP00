//getline()
//std:getline(std::cin, name);
//setw(); --> a voir !!! 
//str.c_str(); -->met un \0;
//str.substr(

#include "Contact.hpp"

/**
 * Default constructor for Contact class.
 * Initializes an empty contact with default string values.
 */
Contact::Contact()
{
}

/**
 * Destructor for Contact class.
 * Cleans up contact resources.
 */
Contact::~Contact()
{
}

static std::string	InfoAsk(const std::string &FieldName);

/**
 * Sets all contact information by prompting the user.
 * 
 * Algorithm:
 * - Sequentially prompts for each field:
 *   1. First name
 *   2. Last name
 *   3. Nickname
 *   4. Phone number
 *   5. Dark secret
 * - Stores each response in corresponding private member variable
 */
void	Contact::InfoSet()
{
	first_name_ = InfoAsk(FIRST_NAME);
	last_name_ = InfoAsk(LAST_NAME);
	nick_name_ = InfoAsk(NICKNAME);
	phone_number_ = InfoAsk(PHONE_NUMBER);
	dark_secret_ = InfoAsk(DARK_SECRET);
}

/**
 * Prompts user for a specific contact field.
 * 
 * @param FieldName Name of the field to prompt for
 * @return User input as string
 * 
 * Algorithm:
 * - Display field name with right-aligned padding
 * - Read entire line of input (allows spaces)
 * - Return raw input without validation
 */
static std::string	InfoAsk(const std::string &FieldName)
{
	std::string	input;

	std::cout << std::setw(PADDING);
	std::cout << FieldName << PROMPT_END;
	std::getline(std::cin, input);
	return (input);
}

static void	FieldDisplay(std::string &fieldName);

/**
 * Displays contact in search table format.
 * 
 * Algorithm:
 * - Outputs contact fields in pipe-separated columns
 * - Each field is truncated to 10 characters max
 * - Format: |first_name|last_name|nickname|
 * - Used when displaying multiple contacts in list view
 */
void	Contact::DisplaySearch()
{
	std::cout << SEP;
	FieldDisplay(first_name_);
	std::cout << SEP;
	FieldDisplay(last_name_);
	std::cout << SEP;
	FieldDisplay(nick_name_);
	std::cout << SEP << std::endl;
}

/**
 * Displays a single field in truncated table format.
 * 
 * @param fieldName The field content to display
 * 
 * Algorithm:
 * - Truncate field to maximum 10 characters
 * - If longer than 10 chars, replace 10th char with '.'
 * - Right-align content in 10-character width
 * - Ensures uniform column width in table display
 */
static void	FieldDisplay(std::string &fieldName)
{
	std::string	toDisplay;

	// Extract first 10 characters
	toDisplay = fieldName.substr(0, 10);
	
	// Add ellipsis if field was truncated
	if (fieldName.length() > 10)
		toDisplay[9] = '.';
	
	std::cout << std::setw(10);
	std::cout << toDisplay;
}

static void	info_line_display(std::string fieldName, std::string fieldValue);

/**
 * Displays full contact details for selected index.
 * 
 * Algorithm:
 * - Displays all 5 contact fields in detailed format
 * - Each field shown on separate line with label
 * - Used when user selects specific contact to view
 * - No truncation applied (full content displayed)
 */
void	Contact::DisplayIndex()
{
	info_line_display(FIRST_NAME, first_name_);
	info_line_display(LAST_NAME, last_name_);
	info_line_display(NICKNAME, nick_name_);
	info_line_display(PHONE_NUMBER, phone_number_);
	info_line_display(DARK_SECRET, dark_secret_);
}

/**
 * Displays a single contact field as labeled line.
 * 
 * @param fieldName Label for the field
 * @param fieldValue Content of the field
 * 
 * Algorithm:
 * - Right-align field label with padding
 * - Display separator (" : ")
 * - Display full field value without truncation
 * - Format: "     field_name : value"
 */
static void	info_line_display(std::string fieldName, std::string fieldValue)
{
	std::cout << std::setw(PADDING);
	std::cout << fieldName << PROMPT_END;
	std::cout << fieldValue << std::endl;
}


