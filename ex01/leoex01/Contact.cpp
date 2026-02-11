/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:22:45 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/09/14 17:17:24 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(const std::string& first_name)
{
	_first_name = first_name;
}

void	Contact::setLastName(const std::string& last_name)
{
	_last_name = last_name;
}

void	Contact::setNickName(const std::string& nick_name)
{
	_nick_name = nick_name;
}

void	Contact::setPhoneNumber(const std::string& phone_number)
{
	_phone_number = phone_number;
}

void	Contact::setDarkestSecret(const std::string& darkest_secret)
{
	_darkest_secret = darkest_secret;
}

std::string	Contact::getFirstName() const
{
	return (_first_name);
}

std::string	Contact::getLastName() const
{
	return (_last_name);
}

std::string	Contact::getNickName() const
{
	return (_nick_name);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phone_number);
}

std::string Contact::getDarkestSecret() const
{
	return (_darkest_secret);
}