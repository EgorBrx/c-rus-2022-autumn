#include <iostream>

int* CreateArray(int n);
int FillArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    int* A = CreateArray(n);
    FillArray(A, n);
    int Current = A[n - 1] + A[0] + A[1];
    int Max = Current;

    for (int i = 2; i <= n; i++)
    {
        Current += A[(n + i % n) % n] - A[(n + (i - 3) % n) % n];
        if (Max < Current)
            Max = Current;
    }
    std::cout << Max;

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