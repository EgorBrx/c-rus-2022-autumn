#include <iostream>

int main(int argc, char* argv[])
{
    int i = 1;
    int Answer = 0;
    while (i != 0)
    {
        std::cin >> i;
        if (i < 0)
            Answer++;
    }
    std::cout << Answer;

    return EXIT_SUCCESS;
}
