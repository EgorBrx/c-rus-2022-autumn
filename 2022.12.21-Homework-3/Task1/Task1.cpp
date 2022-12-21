#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    if (a < b)
        while (a <= b)
        {
            std::cout << a << " ";
            a++;
        }
    else
    {
        while (a >= b)
        {
            std::cout << a << " ";
            a--;
        }
    }
    return EXIT_SUCCESS;
}
