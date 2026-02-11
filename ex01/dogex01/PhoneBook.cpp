/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:03:29 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/06 11:35:38 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib> //pour gerer les erreurs d'entree
#include <iomanip>
#include <string>
#include <string>


PhoneBook::PhoneBook() : count_(0) {}
PhoneBook::~PhoneBook() {}

static int minInt(int a, int b)
{
    return(a < b) ? a : b;
}

void PhoneBook::addContact()
{
    int slot = count_ % 8;
    
    std::cout << "[ADD] adding contact at slot" << slot << std::endl;
    contacts[slot].fill();
    count_++;
    std::cout << "Contact saved. \n";
}

static bool isAllDigits(const std::string &str)
{
    if(str.empty())
        return false;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

void PhoneBook::searchContact() const
{
    int total = minInt(count_, 8);
    if(count_ == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nick Name" << "|" << std::endl;

    for(int i = 0; i < total; i++)
        contacts[i].displayShort(i);
    
    std::string index;
    std::cout << "Enter Index: ";

    if(!std::getline(std::cin, index))
    {
        std::cout << "\nEOF detected. Exiting program\n";
        std::exit(0);
    }
    if(!isAllDigits(index))
    {
        std::cout << "Invalid index\n";
        return;
    }
    int idx = std::atoi(index.c_str());
    if(idx < 0 || idx >= total)
    {
        std::cout << "index out of range. \n";
        return;
    }
    contacts[idx].displayFull();
}