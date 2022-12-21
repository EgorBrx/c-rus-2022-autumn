#include <iostream>

int main(int argc, char* argv[])
{
	int a       = 0;
	int b       = 0;
	int c       = 0;
	int d       = 0;
	int e       = 0;
	int result  = 0;

	std::cin >> a >> b >> c >> d >> e;
	
	for (int x = 0; x < 1001; x++)
		if ((a * x * x * x + b * x * x + c * x + d == 0) && (x != e))
			result++;
	std::cout << result;

	return EXIT_SUCCESS;
}