//getline()
//std:getline(std::cin, name);
//setw(); --> a voir !!! 
//str.c_str(); -->met un \0;
//str.substr(

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

static std::string	InfoAsk(const std::string &FieldName);
void	Contact::InfoSet()
{
	first_name_ = InfoAsk(FIRST_NAME);
	last_name_ = InfoAsk(LAST_NAME);
	nick_name_ = InfoAsk(NICKNAME);
	phone_number_ = InfoAsk(PHONE_NUMBER);
	dark_secret_ = InfoAsk(DARK_SECRET);
}

static std::string	InfoAsk(const std::string &FieldName)
{
	std::string	input;

	std::cout << std::setw(PADDING);
	std::cout << FieldName << PROMPT_END;
	std::getline(std::cin, input);
	return (input);
}

static void	FieldDisplay(std::string &fieldName);
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

static void	FieldDisplay(std::string &fieldName)
{
	std::string	toDisplay;

	toDisplay = fieldName.substr(0, 10);
	if (fieldName.length() > 10)
		toDisplay[9] = '.';
	std::cout << std::setw(10);
	std::cout << toDisplay;
}

static void	info_line_display(std::string fieldName, std::string fieldValue);
void	Contact::DisplayIndex()
{
	info_line_display(FIRST_NAME, first_name_);
	info_line_display(LAST_NAME, last_name_);
	info_line_display(NICKNAME, nick_name_);
	info_line_display(PHONE_NUMBER, phone_number_);
	info_line_display(DARK_SECRET, dark_secret_);
}

static void	info_line_display(std::string fieldName, std::string fieldValue)
{
	std::cout << std::setw(PADDING);
	std::cout << fieldName << PROMPT_END;
	std::cout << fieldValue << std::endl;
}


