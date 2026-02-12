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

void	Contact::infoset()
{
	first_name_ = infoAsk(FIRST_NAME);
	last_name_ = infoAsk(LAST_NAME);
	nick_name_ = infoAsk(NICKNAME);
	phone_number_ = infoAsk(PHONE_NUMBER);
	dark_secret_ = infoAsk(DARK_SECRET);
}

static std::string	infoAsk(const std:string &FieldName)
{
	std::string	input;

	std::cout << std::setw(15);
	std::cout << std::FildName << " : ";
	std::getline(std::cin, input);
	return (input);
}




	
