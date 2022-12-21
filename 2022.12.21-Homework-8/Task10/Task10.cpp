#include <iostream>

int admin(int*&, int, int);
int* CreateArray(int n);

int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;

	std::cin >> n;
	int* Forum = CreateArray(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> Forum[i];
		std::cin >> Forum[i];
	}

	std::cin >> k;
	std::cout << admin(Forum, k - 1, n);
	return EXIT_SUCCESS;
}
int admin(int*& arr, int k, int n)
{
	int result = 1;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == k + 1)
		{
			result += admin(arr, i, n);
		}
	}
	return result;
}
int DeleteArray(int* Array, int n)
{
	delete[] Array;

	return 0;
}
int* CreateArray(int n)
{
	int* Array = new int[n] {0};
	return Array;
}