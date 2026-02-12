#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#define MENU_DISPLAY \
    "\n╔════════════════════════════════════════════════╗\n" \
    "║         📞 MY AWESOME PHONEBOOK 📞            ║\n" \
    "╠════════════════════════════════════════════════╣\n" \
    "║                                                ║\n" \
    "║  Available Commands:                           ║\n" \
    "║                                                ║\n" \
    "║  • ADD    : Add a new contact                  ║\n" \
    "║  • SEARCH : Search and display contacts        ║\n" \
    "║  • EXIT   : Quit the phonebook                 ║\n" \
    "║                                                ║\n" \
    "╚════════════════════════════════════════════════╝\n" \
    "\nEnter a command : "

# define ADD	"ADD"
# define SEARCH	"SEARCH"
# define EXIT	"EXIT"

class PhoneBook{
	private :
		Contact::Contact	contact[8];
		int					count_;
		void				MenduDisplay();
		void				ContactAdd();
		void				ContactSearch();

	public :
		PhoneBook();
		~PhoneBook();
		void				MenuRun();
	};

#endif
