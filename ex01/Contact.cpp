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

	std::cout << std::setw(15);
	std::cout << FieldName << " : ";
	std::getline(std::cin, input);
	return (input);
}

