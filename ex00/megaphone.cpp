#include <iostream>
/*
int main(int ac,char *av[])
{
	if (ac < 2)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);

	av++;
	while (ac-- > 1)
	{
		while (**av)
		{
			std::cout << static_cast<char>(std::toupper(**av));
			(*av)++;
		}
		av++;
	}
	std::cout << std::endl;
	return (0);
}
*/

#include <string>

int	main(int ac, char **av)
{
	if (ac < 2){std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; return (0);}

	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper((unsigned char)str[j]);
	}
	std::cout << std::endl;
	return (0);
}

