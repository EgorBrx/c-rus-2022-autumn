#include <iostream>

char* AddBoard(char* str, char* StrResult, int n, int lenghtStr);
char* AddBoard(char* str);

int main(int argc, char* argv[])
{
    char str[1001];
    std::cin >> str;

    std::cout << AddBoard(str);

    return EXIT_SUCCESS;
}
char* AddBoard(char* str, char* StrResult, int n, int lenghtStr)
{
    if (n == lenghtStr - 1)
    {
        StrResult[n * 2] = str[n];
        return StrResult;
    }
    StrResult[2 * n] = str[n];
    if (n < lenghtStr / 2)
        StrResult[2 * n + 1] = '(';
    else
        StrResult[2 * n + 1] = ')';
    AddBoard(str, StrResult, n + 1, lenghtStr);
}
char* AddBoard(char* str)
{
    int   n = strlen(str);
    char* str_result = new char[n * 2 + 1] {'0'};

    return AddBoard(str, str_result, 0, n);
}