#ifndef CONACT_HPP
# define CONACT_HPP

# include <string>
# include <iostream>

# define FIRST_NAME		"first name"
# define LAST_NAME		"last name"
# define NICKNAME		"nickname"
# define PHONE_NUMBER	"phone number"//12 caracteres
# define DARK_SECRET		"dark secret"

class Contact{
	private :
		std::string	first_name_; //attribu de la classe
		std::string	last_name_;
		std::string	nick_name_;
		std::string	phone_number_;
		std::string	dark_secret_;

	public :
		Contact();
		~Contact();
		void	InfoSet();
		void	displaySearch() const;
		void	displayIndex() const;
	};


static std::string	InfoAsk(const std::string &FieldName);
#endif
