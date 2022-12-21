#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    float Answer = 1;

    std::cin >> n;

    for (float i = 1, j = 1; j <= n;  j++, i *= 1 / j)
        Answer += i;

    std::cout << Answer;

    return EXIT_SUCCESS;
}
