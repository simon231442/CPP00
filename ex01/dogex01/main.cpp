/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:28:45 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/06 11:32:57 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

int main()
{
    PhoneBook  phonebook;
    std::string command;

	std::cout << "*-----------------------------------------------*\n";
    std::cout << "*-----------PHONEBOOK APPLICATION --------------*\n";
	std::cout << "*-----------------------------------------------*\n";
	while (true)
    {
		std::cout << "-------------------------------------------------\n";
        std::cout << "-----Enter command (ADD, SEARCH, EXIT): ";

        if (!std::getline(std::cin, command))
        {
            std::cout << "\nEOF detected. Exiting program.\n";
            std::exit(0);
        }

        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
			phonebook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else
        {
            std::cout << "Unknown command.\n";
        }
    }
    return 0;
}
