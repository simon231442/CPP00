#ifndef CONACT_HPP
# define CONACT_HPP

#include <string>

class contact{
	private :
		std::string	first_name_; //attribu de la classe
		std::string	last_name_;
		std::string	nick_name_;
		std::string	phone_number_;
		std::string	dark_secret_;

	public :
		contact();
		~contact();
		void	infoSet();
		void	displaySearch() const;
		void	displayIndex() const;
	};

#endif
