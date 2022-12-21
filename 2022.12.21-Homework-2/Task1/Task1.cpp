#include <iostream>

int main(int args, char* argv[])
{
	int n = 0;
	std::cin >> n;
	switch (n / 100)
	{
	case 1:
	{
		std::cout << "sto ";
		break;
	}
	case 2:
	{
		std::cout << "dvesti ";
		break;
	}
	case 3:
	{
		std::cout << "trista ";
		break;
	}
	case 4:
	{
		std::cout << "chetyresta ";
		break;
	}
	case 5:
	{
		std::cout << "pyatsot ";
		break;
	}
	case 6:
	{
		std::cout << "shestsot ";
		break;
	}
	case 7:
	{
		std::cout << "semsot ";
		break;
	}
	case 8:
	{
		std::cout << "vosensot ";
		break;
	}
	case 9:
	{
		std::cout << "devyatsot ";
		break;
	}
	}
	switch (n / 10 % 10)
	{
	case 2:
	{
		std::cout << "dvadtsat' ";
		break;
	}
	case 3:
	{
		std::cout << "tridsat' ";
		break;
	}
	case 4:
	{
		std::cout << "sorok ";
		break;
	}
	case 5:
	{
		std::cout << "pyatdesyat ";
		break;
	}
	case 6:
	{
		std::cout << "shestdesyat ";
		break;
	}
	case 7:
	{
		std::cout << "semdesyat ";
		break;
	}
	case 8:
	{
		std::cout << "vosemdesyat ";
		break;
	}
	case 9:
	{
		std::cout << "devyanosto ";
		break;
	}
	case 1:
	{
		switch (n % 10)
		{
		case 0:
		{
			std::cout << "desyat bananov";
			return EXIT_SUCCESS;
		}
		case 1:
		{
			std::cout << "odinnadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 2:
		{
			std::cout << "dvenadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 3:
		{
			std::cout << "trinadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 4:
		{
			std::cout << "chetyrnadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 5:
		{
			std::cout << "pyatnadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 6:
		{
			std::cout << "shestnadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 7:
		{
			std::cout << "semnadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 8:
		{
			std::cout << "vosemnadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		case 9:
		{
			std::cout << "devyatnadtsatb' bananov";
			return EXIT_SUCCESS;
		}
		}
	}
	}
	if ((n / 10 % 10 != 1) && (n != 0))
		switch (n % 10)
		{
		case 0:
		{
			std::cout << "bananov";
			break;
		}
		case 1:
		{
			std::cout << "odin banan";
			break;
		}
		case 2:
		{
			std::cout << "dva banana";
			break;
		}
		case 3:
		{
			std::cout << "tri banana";
			break;
		}
		case 4:
		{
			std::cout << "chetyri banana";
			break;
		}
		case 5:
		{
			std::cout << "pyatb' bananov";
			break;
		}
		case 6:
		{
			std::cout << "shestb' bananov";
			break;
		}
		case 7:
		{
			std::cout << "semb' bananov";
			break;
		}
		case 8:
		{
			std::cout << "vosemb' bananov";
			break;
		}
		case 9:
		{
			std::cout << "devyat' bananov";
			break;
		}
		}
	if (n == 0)
	{
		std::cout << "nolb' bananov";
	}
	return EXIT_SUCCESS;
}