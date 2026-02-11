/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:08:45 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/06 11:31:48 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip> // pour setw()
#include <iostream>
#include <cstdlib>

static std::string truncate(const std::string &str)
{
    if(str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

static    std::string askNonEmpty(const std::string &prompt)
{
    std::string input;
    
    while(true)
    {
        std::cout << prompt;
        if(!std::getline(std::cin, input))
        {
            std::cout << "\nEOF detected. Exiting program." << std::endl;
            std::exit(0);
        }        
        
        if(!input.empty())
            return input;
        std::cout << "input empty, please try again." << std::endl;
    }
}

Contact::Contact() {}
Contact::~Contact() {}

void Contact::fill()
{
	first_name_ = askNonEmpty("First name: ");
	last_name_ = askNonEmpty("Last name: ");
	nickname_ = askNonEmpty("Nickname: ");
	phone_number_ = askNonEmpty("Phone number: ");
	darkest_secret_ = askNonEmpty("Darkest secret: ");
}

void Contact::displayShort(int index) const
{
    std::cout   << std::setw(10) << index << "|"
                << std::setw(10) << truncate(first_name_) << "|"
                << std::setw(10) << truncate(last_name_) << "|"
                << std::setw(10) << truncate(nickname_) << "|" << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "First Name: " << first_name_ << std::endl;
    std::cout << "Last Name: " << last_name_ << std::endl;
    std::cout << "NickName: " << nickname_ << std::endl;
    std::cout << "Phone Number: " << phone_number_ << std::endl;
    std::cout << "Dark secret: " << darkest_secret_ << std::endl;
}
