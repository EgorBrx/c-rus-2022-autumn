#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;

	float g = -1 * float(b) / a;
	float f = -1 * float(d) / c;

	if (a != 0)
		if ((g != f) && (int(g) == g))
			std::cout << int(g);
		else
			if ((c == 0) && (int(g) == g))
				std::cout << int(g);
			else
				std::cout << "NO";
	else
		if (b == 0)
			std::cout << "INF";
		else
			std::cout << "NO";

	return EXIT_SUCCESS;
}