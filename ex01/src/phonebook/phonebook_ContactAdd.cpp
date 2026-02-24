
#include "PhoneBook.hpp"

static void phonebook_full_handle(int *index, int *full);
static void	add_success_message_display();

/**
 * Adds a new contact to the phonebook.
 * 
 * Algorithm:
 * 1. Checks if the phonebook is full and resets index if needed
 * 2. Prompts user to enter contact information
 * 3. Increments the current index for next insertion
 * 4. Displays success message
 * 
 * Uses circular buffer logic: when 8 contacts are reached,
 * oldest contact gets overwritten.
 */
void	PhoneBook::ContactAdd()
{
	// Handle circular buffer overflow (max 8 contacts)
	phonebook_full_handle(&index_current_, &full_);
	
	contact[index_current_].InfoSet();	
	index_current_++;
	add_success_message_display();
}

/**
 * Handles the phonebook full condition.
 * 
 * @param index Pointer to the current insertion index
 * @param full Pointer to the full flag
 * 
 * Algorithm:
 * - When index reaches 8 (array is full), reset to 0 for circular overwrite
 * - Set full flag to 1 to indicate at least one full cycle has occurred
 */
static void phonebook_full_handle(int *index, int *full)
{
	// Check if we've reached capacity (8 contacts)
	if (*index != 0 && *index % 8 == 0)
	{
		*index = 0;
		*full = 1;
	}
}

/**
 * Displays success message after adding a contact.
 * Outputs a formatted success notification to the user.
 */
static void	add_success_message_display()
{
	std::cout << "\n" << ADD_SUCCESS << std::endl;
}
