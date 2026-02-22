#include "PhoneBook.hpp"

// Vérifie si le carnet contient au moins un contact.
static int			phonebook_is_empty(int index);
// Affiche le message indiquant qu'aucun contact n'est présent.
static void 		phonebook_empty_message_display();
// Affiche les contacts disponibles avec leurs indices visibles.
static void			contact_all_display(Contact contact[], int index, int full);
// Demande l'indice à consulter à l'utilisateur.
static std::string	index_ask();

// Permet de parcourir les contacts : affiche la liste puis détaille celui choisi.
void	PhoneBook::ContactSearch()
{
	if (!phonebook_is_empty(index_current_))
		return (phonebook_empty_message_display());

	contact_all_display(contact, index_current_, full_);

	std::string	input = index_ask();
	int index = input[0] - '0';
	if (isdigit(input[0]) && index < 8 && (index < index_current_ || full_))
		contact[index].DisplayIndex();
	else
	{
		std::cout << SELECT_ERROR << std::endl;
		ContactSearch(); // Relance la sélection tant qu'une entrée valide n'est pas fournie.
	}
}

// Retourne 1 si l'index courant est non nul (carnet non vide).
static int	phonebook_is_empty(int index)
{
	if (index)
		return (1);
	return (0);
}

// Signale à l'utilisateur qu'il n'y a rien à afficher.
static void phonebook_empty_message_display()
{
	std::cout << EMPTY << std::endl;
}

// Liste les contacts existants en affichant leur index suivi des champs tronqués.
static void	contact_all_display(Contact contact[], int index, int full)
{
	if (full)
		index = 8; // Quand le carnet est plein, tous les emplacements sont utilisables.
	for (int i = 0; i < index; i++)
	{
		std::cout << i << " ";
		contact[i].DisplaySearch();
	}
}


// Demande à l'utilisateur l'indice du contact à détailler.
static std::string	index_ask()
{
	std::string	answer;

	std::cout << std::endl;
	std::cout << std::setw(PADDING);
	std::cout << SELECT_PROMPT << PROMPT_END;

	std::getline(std::cin, answer);

	return (answer);
}
