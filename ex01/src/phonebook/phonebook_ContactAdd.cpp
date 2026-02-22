#include "PhoneBook.hpp"

static void phonebook_full_handle(int *index, int *full);
static void	add_success_message_display();

void	PhoneBook::ContactAdd()
{
	phonebook_full_handle(&index_current_, &full_);
	contact[index_current_].InfoSet();	
	index_current_++;
	add_success_message_display();
}

static void phonebook_full_handle(int *index, int *full)
{
	if (*index != 0 && *index % 8 == 0)
	{
		*index = 0;
		*full = 1;
	}
}

static void	add_success_message_display()
{
	std::cout << "\n" << ADD_SUCCESS << std::endl;
}
