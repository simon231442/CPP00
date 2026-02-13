#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#define MENU_DISPLAY \
    "\n╔════════════════════════════════════════════════╗\n" \
    "║          📞 MY AWESOME PHONEBOOK 📞            ║\n" \
    "╠════════════════════════════════════════════════╣\n" \
    "║                                                ║\n" \
    "║  Available Commands:                           ║\n" \
    "║                                                ║\n" \
    "║  • ADD    : Add a new contact                  ║\n" \
    "║  • SEARCH : Search and display contacts        ║\n" \
    "║  • EXIT   : Quit the phonebook                 ║\n" \
    "║                                                ║\n" \
    "╚════════════════════════════════════════════════╝\n" \

# define ADD		"ADD"
# define SEARCH		"SEARCH"
# define EXIT		"EXIT"
# define CMD_PROMPT "Enter a command"
# define CMD_ERROR	"Unknown command, try again"
# define ADD_SUCCESS "Contact added successfully"

class PhoneBook{
	private :
		Contact				contact[8];
		int					index_current_;
		void				MenuDisplay();
		void				PromptDisplay();
		void				ContactAdd();
		void				ContactSearch();

	public :
		PhoneBook();
		~PhoneBook();
		void				MenuRun();
	};

#endif
