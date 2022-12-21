#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int Answer = 0;

    std::cin >> n;

    for (int i = 1; n > 0; n /= 10, i *= 2)
    {
        Answer += i * (n % 10);
    }

    std::cout << Answer;

    return EXIT_SUCCESS;
}

