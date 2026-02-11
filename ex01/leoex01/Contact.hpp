/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:51:00 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/09/29 15:39:39 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:	
		
		Contact();
		~Contact();
		
		void		setFirstName(const std::string& first_name);
		void		setLastName(const std::string& last_name);
		void		setNickName(const std::string& nick_name);
		void		setPhoneNumber(const std::string& phone_number);
		void		setDarkestSecret(const std::string& darkest_secret);
		
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
	
	private:
		
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif