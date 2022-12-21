#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int k = 0;
    std::cin >> a >> b >> c;

    if (a < c)
    {
        c = c - a;
        a = c + a;
        c = a - c;
    }
    if (a < b)
    {
        b = b - a;
        a = b + a;
        b = a - b;
    }
    if (b < c)
    {
        b = b - c;
        c = b + c;
        b = c - b;
    }

    if (b + c < a)
    {
        std::cout << "impossible";
    }
    else
    {
        if (c * c + b * b > a * a)
        {
            std::cout << "acute";
        }
        else
        {
            if (c * c + b * b == a * a)
                std::cout << "rectangular";
            else
                std::cout << "obtuse";
        }
    }

    return EXIT_SUCCESS;
}