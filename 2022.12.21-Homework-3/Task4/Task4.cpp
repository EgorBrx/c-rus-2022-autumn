#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int i = 1;
    int m = 0;
    std::cin >> n;
    do
    {
        i = 1;
        do
        {
            std::cout << i + m << " ";
            i++;
        } while (i <= n - m);
        i = 1;
        while (i <= m)
        {
            std::cout << n - i << " ";
            i++;
        }

        std::cout << std::endl;
        m++;
    } while (m < n);

    return EXIT_SUCCESS;
}
