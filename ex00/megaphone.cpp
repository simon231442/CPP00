#include <iostream>

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
