#include <iostream>

int* CreateArray(int n);
int FillArray(int* Array, int n);
int DeleteArray(int* Array, int n);
int ShowArray(int* Array, int n);
int swap(int& a, int& b);

int main(int argc, char* argv[])
{
    int n = 0;

    std::cin >> n;
    int* A = CreateArray(n);

    FillArray(A, n);

    for (int i = 0; i < n / 2; i++)
        swap(A[i], A[n - 1 - i]);

    ShowArray(A, n);

    DeleteArray(A, n);

    return EXIT_SUCCESS;
}

int swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
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
int ShowArray(int* Array, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << Array[i] << " ";
    std::cout << std::endl;
    return 0;
}
int DeleteArray(int* Array, int n)
{
    delete[] Array;

    return 0;
}