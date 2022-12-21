#include <iostream>

int MaxNumberInStr(int* str, int n, int max);
int MaxNumberInStr(char* str);
int* CreateArray(int n);

int main(int argc, char* argv[])
{
    char str[1001];
    std::cin >> str;

    std::cout << MaxNumberInStr(str);

    return 0;
}

int MaxNumberInStr(int* str, int n, int max)
{
    if (str[n] > max)
        max = str[n];
    if (n == 0)
    {
        return max;
    }

    return MaxNumberInStr(str, n - 1, max);
}
int MaxNumberInStr(char* str)
{
    int  max = 0;
    int  n = strlen(str);
    int* Str_Int = CreateArray(n);

    for (int i = 0; i < n; i++)
        Str_Int[i] = str[i] - '0';

    if (n == 1)
    {
        return Str_Int[0];
    }

    return MaxNumberInStr(Str_Int, n - 1, max);
}
int* CreateArray(int n)
{
    int* Array = new int[n] {0};

    return Array;
}