#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int k = 0;
    int m = 0;
    std::cin >> n >> k >> m;

    if (n == k)
        std::cout << 2 * m * k;
    else
        if (n < k)
            std::cout << 2 * m * (n % k);
        else
            std::cout << 2 * m * (n / k) + 2 * m * (n % k);

    return EXIT_SUCCESS;
}