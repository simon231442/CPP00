/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:14:25 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/10/17 15:15:37 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook() : _current_i(0), _time_to_exit(false)
{
}

Phonebook::~Phonebook()
{
}

void Phonebook::runMenu()
{
	std::string choice;
	std::string add("ADD");
	std::string search("SEARCH");
	std::string exit("EXIT");

	std::cout << " *** WELCOME TO MY AWESOME PHONEBOOK ***" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "You have 3 options you can use:" << std::endl;
	std::cout << " - 'ADD' to add a new contact" << std::endl;
	std::cout << " - 'SEARCH' to search a contact" << std::endl;
	std::cout << " - 'EXIT' to exit the phonebook" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	while (!std::cin.eof() && !_time_to_exit)
	{
		std::cout << "Enter your choice <ADD> <SEARCH> <EXIT>: ";
		if (!std::getline(std::cin, choice))
		{
			std::cout << std::endl << "Program interrupted by user. Goodbye!" << std::endl;
			break;
		}

		std::string cleaned_choice = _trimString(choice);
		if (cleaned_choice.empty())
			continue;

		if (cleaned_choice == add)
			_add();
        else if (cleaned_choice == search)
			_search();
		else if (cleaned_choice == exit)
			_exit();
		else
			std::cout << "Only 3 commands are available: 'ADD' 'SEARCH' 'EXIT'" << std::endl;
	}
}

void	Phonebook::_add()
{
	std::cout << "Add a new contact" << std::endl;

	std::string	first_name = _getValidInput("Enter the first name : ");
	if (first_name.empty())
		return ;
	std::string	last_name = _getValidInput("Enter the last name : ");
	if (last_name.empty())
		return ;
	std::string	nick_name = _getValidInput("Enter the nickname : ");
	if (nick_name.empty())
		return ;
	std::string	phone_number = _getValidPhoneNumber("Enter the phone number : ");
	if (phone_number.empty())
		return ;
	std::string	darkest_secret = _getValidInput("Enter the darkest secret : ");
	if (darkest_secret.empty())
		return ;

	_contact[_current_i].setFirstName(first_name);
	_contact[_current_i].setLastName(last_name);
	_contact[_current_i].setNickName(nick_name);
	_contact[_current_i].setPhoneNumber(phone_number);
	_contact[_current_i].setDarkestSecret(darkest_secret);

	std::cout << "Contact added succesfully !" << std::endl;
	_setCurrentI();
}

void	Phonebook::_search()
{
	int	valid_contact = 0;

	for (int i = 0; i < 8; i++)
	{
		if (!_contact[i].getFirstName().empty())
			valid_contact++;
	}
	if (valid_contact == 0)
	{
		std::cout << "The phonebook is empty, try 'ADD' first" << std::endl;
		return ;
	}

    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First name" << "|";
    std::cout << std::setw(10) << std::right << "Last name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if (!_contact[i].getFirstName().empty())
		{
			std::string	first_name(_contact[i].getFirstName());
			std::string	last_name(_contact[i].getLastName());
			std::string	nickname(_contact[i].getNickName());

			if (first_name.length() > 10)
				first_name = first_name.substr(0, 9) + ".";
			if (last_name.length() > 10)
				last_name = last_name.substr(0, 9) + ".";
			if (nickname.length() > 10)
				nickname = nickname.substr(0, 9) + ".";

			std::cout << std::setw(10) << std::right << i << "|";
			std::cout << std::setw(10) << std::right << first_name << "|";
			std::cout << std::setw(10) << std::right << last_name << "|";
			std::cout << std::setw(10) << std::right << nickname << std::endl;
		}
	}

	int chosen_index = _getValidIndex();

	if (chosen_index == -1)
		return;

	std::cout << "=== Contact infos ====" << std::endl;
	std::cout << "First name : " << _contact[chosen_index].getFirstName() << std::endl;
	std::cout << "Last name : " << _contact[chosen_index].getLastName() << std::endl;
	std::cout << "Nickname : " << _contact[chosen_index].getNickName() << std::endl;
	std::cout << "Phone number : " << _contact[chosen_index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << _contact[chosen_index].getDarkestSecret() << std::endl;
}

void Phonebook::_exit()
{
	std::string	answer;
	std::string	yes("YES");

	std::cout << "Are you sure you want to quit?" << std::endl;
    
	while (!std::cin.eof())
	{
		std::cout << "Type YES to quit definitively: ";
		if (!std::getline(std::cin, answer))
		{
			std::cout << "Exiting program." << std::endl;
			_setTimeToExit();
			return;
		}

		std::string cleaned = _trimString(answer);
		if (cleaned == yes)
		{
			_setTimeToExit();
			return;
		}

		std::cout << "Exit cancelled. Returning to menu." << std::endl;
		return;
	}
}

bool	Phonebook::_getTimeToExit() const
{
	return (_time_to_exit);
}

void	Phonebook::_setTimeToExit(void)
{
	_time_to_exit = true;
}

int		Phonebook::_getCurrentI() const
{
	return (_current_i);
}

void	Phonebook::_setCurrentI()
{
	_current_i = (_current_i + 1) % 8;
}

std::string	Phonebook::_trimString(const std::string& str)
{
	size_t	start = 0;

	while (start < str.length() && std::isspace(str[start]))
		start++;
	if (start == str.length())
		return ("");
	
	size_t	end = str.length() - 1;
	while (end > start && std::isspace(str[end]))
		end--;
	
	return (str.substr(start, end - start + 1));
}

std::string	Phonebook::_getValidInput(const std::string& str)
{
	std::string	input;

	while (!std::cin.eof())
	{
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Input interrupted." << std::endl;
			return ("");
		}
		
		std::string	cleaned = _trimString(input);
		if (!cleaned.empty())
			return (cleaned);
		std::cout << "Cannot be empty, please enter a value" << std::endl;
	}
	return ("");
}

int	Phonebook::_getValidIndex()
{
	std::string	input;
	int			index;

	while (!std::cin.eof())
	{
		std::cout << "Enter the index of the contact you want to display : ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "Input interrupted." << std::endl;
			return (-1);
		}
		
		std::string	cleaned = _trimString(input);
		if (cleaned.empty())
		{
			std::cout << "Please enter a number." << std::endl;
			continue ;
		}

		bool	is_number = true;
		for (size_t i = 0; i < cleaned.length(); i++)
		{
			if (!std::isdigit(cleaned[i]))
			{
				is_number = false;
				break ;
			}
		}
		
		if (!is_number)
		{
			std::cout << "Please enter a valid number." << std::endl;
			continue ;
		}
		
		index = 0;
		for (size_t i = 0; i < cleaned.length(); i++)
			index = index * 10 + (cleaned[i] - '0');
		
		if (index < 0 || index > 7)
		{
			std::cout << "Index must be between 0 and 7." << std::endl;
			continue ; 
		}
		if (_contact[index].getFirstName().empty())
		{
			std::cout << "No contact at this index. Choose an index "
				<< "from the table above." << std::endl;
			continue ;
		}
		return (index);
	}
	return (-1);
}

std::string Phonebook::_getValidPhoneNumber(const std::string& str)
{
	std::string input;

	while (!std::cin.eof())
	{
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Input interrupted." << std::endl;
			return ("");
		}

		std::string cleaned = _trimString(input);
		if (cleaned.empty())
		{
			std::cout << "Phone number cannot be empty." << std::endl;
			continue;
		}

		bool is_valid = true;
		for (size_t i = 0; i < cleaned.length(); i++)
		{
			if (!std::isdigit(cleaned[i]) && cleaned[i] != ' ' &&
				cleaned[i] != '-' && cleaned[i] != '(' &&
				cleaned[i] != ')' && cleaned[i] != '+')
			{
				is_valid = false;
				break;
			}
		}

		if (!is_valid)
		{
			std::cout << "Phone number can only contain digits " 
				<< "and formatting characters." << std::endl;
			continue;
		}

		bool has_digit = false;
		for (size_t i = 0; i < cleaned.length(); i++)
		{
			if (std::isdigit(cleaned[i]))
			{
				has_digit = true;
				break;
			}
		}
		if (!has_digit)
		{
			std::cout << "Phone number must contain at least "
				<< "one digit." << std::endl;
			continue;
		}
		return (cleaned);
	}
	return ("");
}