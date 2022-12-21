#include <iostream>

int MinFromFour(int a, int b, int c, int d, int min=0, int n = 0, bool BoolFlag = true);

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin >> a >> b >> c >> d;
    
    std::cout << MinFromFour(a, b, c, d);

    return EXIT_SUCCESS;
}

int MinFromFour(int a, int b, int c, int d, int min, int n, bool BoolFlag)
{
    if (n == 5)
        return min;
    if (BoolFlag)
        min = a;
    if (a < min)
        return MinFromFour(b, c, d, a, a, n + 1, false);
    else
        return MinFromFour(b, c, d, a, min, n + 1, false);
}