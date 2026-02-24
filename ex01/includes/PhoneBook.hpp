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

# define PADDING		15
# define ADD	   		"ADD"
# define SEARCH	   		"SEARCH"
# define EXIT	   		"EXIT"
# define CMD_PROMPT		"Enter a command"
# define PROMPT_END		" : "
# define CMD_ERROR		"Unknown command. Use ADD, SEARCH or EXIT"
# define ADD_SUCCESS	"Contact added successfully"
# define SELECT_PROMPT	"Enter index"
# define EMPTY			"Phonebook is empty"
# define SELECT_ERROR	"Invalid index, try again"

class PhoneBook{
	private :
		Contact			contact[8];
		int				index_current_;
		int				full_;

		void			ContactAdd();
		void			ContactSearch();

	public :
		PhoneBook();
		~PhoneBook();
		void			MenuRun();
	};

#endif
