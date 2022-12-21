#include <iostream>

char* AddStar(char* str, char* StrResult, int n, int lenghtStr);
char* AddStar(char* str);

int main(int argc, char* argv[])
{
    char str[1001];
    std::cin >> str;

    std::cout << AddStar(str);

    return EXIT_SUCCESS;
}

char* AddStar(char* str, char* StrResult, int n, int lenghtStr)
{
    if (n == lenghtStr - 1)
    {
        StrResult[n * 2] = str[n];
        return StrResult;
    }
    StrResult[2 * n] = str[n];
    StrResult[2 * n + 1] = '*';
    AddStar(str, StrResult, n + 1, lenghtStr);
}
char* AddStar(char* str)
{
    int   n = strlen(str);
    char* str_result = new char[n * 2 + 1] {'0'};
    return AddStar(str, str_result, 0, n);
}