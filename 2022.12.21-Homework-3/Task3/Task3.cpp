#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;
    std::cin >> n;
    m = n;
    n *= 2;
    do
    {
        int i = m - n / 2 + 1;
        do
        {
            std::cout << i << " ";
            i++;
        } while (i <= m);
        std::cout << std::endl;
        m++;
    } while (m != n);

    return EXIT_SUCCESS;
}
