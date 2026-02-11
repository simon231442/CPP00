/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:01:02 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/10/17 13:17:27 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip> // for setw()
# include <cctype>

class Phonebook
{		
	public:
		Phonebook();
		~Phonebook();

		void		runMenu();
	
	private:
		Contact		_contact[8];
		int			_current_i;
		bool		_time_to_exit;

		void		_add();
		void		_search();
		void		_exit();
		bool		_getTimeToExit() const;
		void		_setTimeToExit();
		int			_getCurrentI() const;
		void		_setCurrentI();
		std::string	_trimString(const std::string& str);
		std::string	_getValidInput(const std::string& str);
		int			_getValidIndex();
		std::string	_getValidPhoneNumber(const std::string& str);
};

#endif