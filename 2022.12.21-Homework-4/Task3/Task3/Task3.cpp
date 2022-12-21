#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int Answer = 0;

    std::cin >> n;

    for (int Count = 0, CurrentNum = 1, i = 0, Limit = 1; Count < n; Count++, i++)
    {
        if (i == Limit)
        {
            i = 0;
            Limit += 1;
            CurrentNum += 1;
        }
        std::cout << CurrentNum << " ";
    }

    return EXIT_SUCCESS;
}