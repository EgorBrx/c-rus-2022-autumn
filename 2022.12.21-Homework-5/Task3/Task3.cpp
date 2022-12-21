#include <iostream>

int* CreateArray(int n);
int FillArray(int* Array, int n);
int ShowArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n = 0;

    std::cin >> n;
    int* A = CreateArray(n);
    FillArray(A, n);
    int Max = A[0];
    int Min = A[0];

    for (int i = 1; i < n; i++)
    {
        if (A[i] > Max)
            Max = A[i];
        if (A[i] < Min)
            Min = A[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] == Max)
            A[i] = Min;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }

    return EXIT_SUCCESS;
}

//general
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



