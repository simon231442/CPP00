#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
class PhoneBook{
	private :
		Contact::Contact	contact[8];
		int					count_;

	public :
		PhoneBook();
		~PhoneBook();
		void	ContactAdd();
		void	ContactSearch();
	};

#endif
