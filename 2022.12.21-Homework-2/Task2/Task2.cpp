#include <iostream>

int main(int argc, char* argv[])
{
    int year = 0;

    std::cin >> year;

    if ((year % 4 == 0 && year % 25 != 0) || year % 400 == 0)
        std::cout << "YES";
    else
        std::cout << "NO";

    return EXIT_SUCCESS;
}