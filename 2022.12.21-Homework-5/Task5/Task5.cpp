#include <iostream>

int* CreateArray(int n);
int FillArray(int* Array, int n);
int DeleteArray(int* Array, int n);

int main(int argc, char* argv[])
{
    int n = 0;
    int X = 0;
    int NearNum = 0;

    std::cin >> n;
    int* A = CreateArray(n);
    FillArray(A, n);
    NearNum = A[0];

    std::cin >> X;

    for (int i = 0; i < n; i++)
    {
        if ((NearNum - X) * (NearNum - X) > (X - A[i]) * (X - A[i]))
            NearNum = A[i];
    }

    std::cout << NearNum;

    DeleteArray(A, n);

    return EXIT_SUCCESS;
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
int DeleteArray(int* Array, int n)
{
    delete[] Array;

    return 0;
}