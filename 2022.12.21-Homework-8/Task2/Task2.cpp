#include <iostream>

int phi(int n);
int phi(int n, int* buffer);
int DeleteArray(int* Array, int n);
int* CreateArray(int n);

int main(int argc, char* argv[])
{
    int n = 0;

    std::cin >> n;

    std::cout << phi(n);

    return EXIT_SUCCESS;
}

int phi(int n, int* buffer)
{
    if (n == 0 || n == 1)// n < 2
        return 1;
    if (buffer[n] == 0)
        buffer[n] = phi(n - 2, buffer) + phi(n - 1, buffer);
    return buffer[n];
}
int phi(int n)
{
    int* buffer = CreateArray(n);
    int  result = 0;
    if (n == 0 || n == 1)// n < 2
    {
        return 1;
    }
    result = phi(n - 1, buffer) + phi(n - 2, buffer);
    DeleteArray(buffer, n);
    return result;
}
int DeleteArray(int* Array, int n)
{
    delete[] Array;

    return 0;
}
int* CreateArray(int n)
{
    int* Array = new int[n] {0};
    return Array;
}