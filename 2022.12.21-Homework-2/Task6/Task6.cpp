#include <iostream>

int main(int argc, char* argv[])
{
    int line1   = 0;
    int column1 = 0;
    int line2   = 0;
    int column2 = 0;

    if (line1 == line2 || column1 == column2 || (line1 - line2) * (line1 - line2) == (column1 - column2) * (column1 - column2))
        std::cout << "YES";
    else
        std::cout << "NO";

    return EXIT_SUCCESS;
}