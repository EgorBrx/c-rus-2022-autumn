#include <iostream>

int IsCanGet(int n);
int IsCanGet(int n, int a, int b);

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    if (IsCanGet(n) > 0)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return EXIT_SUCCESS;
}

int IsCanGet(int n, int a, int b)
{
    if (n == 1)
        return 1;
    if (n < 1)
        return 0;

    return IsCanGet(n - a, a, b) + IsCanGet(n - b, a, b);
}
int IsCanGet(int n)
{
    return IsCanGet(n, 3, 5);
}