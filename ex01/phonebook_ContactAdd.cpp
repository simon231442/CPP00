#include "PhoneBook.hpp"

static void full_of_contact_handle(int *index, int *full);
static void	add_success_display();

void	PhoneBook::ContactAdd()
{
	full_of_contact_handle(&index_current_, &full_);
	contact[index_current_].InfoSet();	
	index_current_++;
	add_success_display();
}

static void full_of_contact_handle(int *index, int *full)
{
	if (*index % 8 == 0)
	{
		*index = 0;
		*full = 0;
	}
}

static void	add_success_display()
{
	std::cout << "\n" << ADD_SUCCESS << std::endl;
}
