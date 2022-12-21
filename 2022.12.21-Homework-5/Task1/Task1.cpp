#include <iostream>

int* CreateArray(int n);
int ShowArray(int* Array, int n);
int FillArray(int* Array, int n);
int cNumInArray(int* Array, int n, int num);

int main(int argc, char* argv[])
{
    int n   = 0;
    int x = 0;
    std::cin >> n;
    int* Array = CreateArray(n);
    FillArray(Array, n);
    std::cin >> x;

    std::cout << cNumInArray(Array, n, x);

    return EXIT_SUCCESS;
}

int cNumInArray(int* Array, int n, int num)
{
    int result = 0;

    for (int i = 0; i < n; i++)
        if (Array[i] == num)
            result++;

    return result;
}
//general
int ShowArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << Array[i] << " ";
    std::cout << std::endl;
    return 0;
}
int FillArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cin >> Array[i];
    return 0;
}
int* CreateArray(int n)
{
    int* Array = new int[n] {0};
    return Array;
}