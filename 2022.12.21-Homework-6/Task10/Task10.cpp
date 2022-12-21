#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int k = 0;
    int current = 0;
    int a[100000]{ 0 };

    std::cin >> n;
    std::cin >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> current;
        if (a[current] == 0)
            a[current] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        std::cin >> current;
        if (a[current] == 1)
            a[current] = 2;
    }
    for (int i = 0; i < 100000; i++)
    {
        if (a[i] == 2)
        {
            std::cout << i << ' ';
        }
    }

    return EXIT_SUCCESS;
}