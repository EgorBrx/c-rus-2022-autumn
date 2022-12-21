#include <iostream>

int HanoyTower(int n);
int HanoyTower(int From, int To, int n);

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    HanoyTower(n);

    return EXIT_SUCCESS;
}

int HanoyTower(int From, int To, int n)
{
    int temporary = 6 - (From + To);

    if (n != 1)
    {
        HanoyTower(From, temporary, n - 1);
        std::cout << "Disk " << n << " move from " << From << " To " << To << std::endl;
        HanoyTower(temporary, To, n - 1);
    }
    else
        std::cout << "Disk " << n << " move from " << From << " To " << To << std::endl;
    return 0;
}
int HanoyTower(int n)
{
    HanoyTower(1, 2, n);

    return 0;
}